//
// Created by mikec_g1kgiu8 on 11/13/2021.
//

#include "DocumentParser.h"
#include "porter2_stemmer.h"
#include <sstream>

DocumentParser::DocumentParser() {
    argv = nullptr;
    path = nullptr;
    setStopWords();
}

DocumentParser::DocumentParser(char** input) {
    argv = input;
    path = argv[1];
    setStopWords();
}

void DocumentParser::openDirUsingFileSystem(IndexHandler& theIndexer) { //opens the directories and parses the files
    int w = 0;
    for (const auto & entry : fs::directory_iterator(path)) { //for the outer folders
        for (const auto & entry2 : fs::directory_iterator(entry.path().c_str())) { //for the .json files
            ++w;
            ++articleCount;
            if (w % 100 == 0) {
                cout << ".";
                if (w % 5000 == 0) {
                    cout << endl;
                }
                cout.flush();
            }
            parse(entry2.path().c_str(), theIndexer);
        }
    }
}

void DocumentParser::parse(const char* filepath, IndexHandler& theIndexer) {
    FILE* fp = fopen(filepath, "rb");

    char readBuffer[65536];
    FileReadStream is (fp, readBuffer, sizeof(readBuffer));

    Document document;
    document.ParseStream(is);

    string theFilePath(filepath);
    theIndexer.addFilePath(document["uuid"].GetString(), theFilePath); //stores the filepath for each documentID


    stringstream ss(document["text"].GetString());
    string a;
    map<string, int> alreadyAppeared; //prevents documentIDs from being added twice to the same word
    while (ss >> a) { //goes through every word in bodyText
        a = lowerStr(a);
        Porter2Stemmer::trim(a);
        Porter2Stemmer::stem(a);
        if ((stopWords.count(a) == 0) && (alreadyAppeared.count(a) == 0)) { //if the word is not a stop word and hasn't appeared in the article yet
            theIndexer.addWord(a, document["uuid"].GetString());
            theIndexer.addFrequency(a, 1);
            alreadyAppeared.insert({a, 0});
        } else if (alreadyAppeared.count(a) > 0) {
            theIndexer.getFrequency(a).back() += 1; //adds 1 every time the word appears in the article
        }
    }


    int counter = 1;
    const rapidjson::Value& attributes = document["entities"]["persons"];
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin(); itr != attributes.End(); ++itr) { //for person entities
        const rapidjson::Value& attribute = *itr;
        for (rapidjson::Value::ConstMemberIterator itr2 = attribute.MemberBegin(); itr2 != attribute.MemberEnd(); ++itr2) {
            if (itr2->name.IsString() && itr2->value.IsString()) {
                if (strlen(itr2->value.GetString()) > 0) {
                    if (itr2->name == "name") {
                        theIndexer.addPerson(itr2->value.GetString(), document["uuid"].GetString()); //adds the name of the person and the article ID to the HashTable
                    }
                }
            }
        }
        counter++;
    }

    int counter2 = 1;
    const rapidjson::Value& attributes2 = document["entities"]["organizations"];
    for (rapidjson::Value::ConstValueIterator itr = attributes2.Begin(); itr != attributes2.End(); ++itr) { //for organization entities
        const rapidjson::Value& attribute = *itr;
        for (rapidjson::Value::ConstMemberIterator itr2 = attribute.MemberBegin(); itr2 != attribute.MemberEnd(); ++itr2) {
            if (itr2->name.IsString() && itr2->value.IsString()) {
                if (strlen(itr2->value.GetString()) > 0) {
                    if (itr2->name == "name") {
                        theIndexer.addOrganization(itr2->value.GetString(), document["uuid"].GetString()); //adds the name of the organization and the article ID to the HashTable
                    }
                }
            }
        }
        counter2++;
    }

    fclose(fp);

}

void DocumentParser::setArgv(char** files) {
    argv = files;
    path = argv[1];
}

void DocumentParser::setStopWords() {
    ifstream is("StopWords.txt");
    if (!is.is_open()) {
        cout << "Could not open StopWords.txt" << endl;
        return;
    }
    string t;
    while (is >> t) {
        stopWords.insert({t, 0});
    }
    is.close();
}

string DocumentParser::lowerStr(string &str) {
    char charArray[str.length() + 1];
    strcpy(charArray, str.c_str());

    for (int i = 0 ; i < str.length() ; i++) {
        charArray[i] = (tolower(charArray[i]));
    }
    string output = charArray;
    return output;
}

void DocumentParser::readFromPersistenceIndex(IndexHandler& theIndexer) {
    string line, word, fileID;
    ifstream input1("Word_Persistence.txt");
    getline(input1, line);
    while (!input1.eof()) { //reads in all data for the index
        if (line == "Word Frequency") {
            break;
        }
        stringstream ss(line);
        ss >> word;
        while (ss >> fileID) {
            theIndexer.addWord(word, fileID);
        }
        getline(input1, line);
    }
    getline(input1, line);
    while (!input1.eof()) { //reads in all data for the wordFrequency map
        if (line == "File Paths") {
            break;
        }
        stringstream ss(line);
        ss >> word;
        int frequency;
        while (ss >> frequency) {
            theIndexer.addFrequency(word, frequency);
        }
        getline(input1, line);
    }
    getline(input1, line);
    while (!input1.eof()) { //reads in all data for the filePaths map
        stringstream ss(line);
        string filePath;
        ss >> fileID >> filePath;

        theIndexer.addFilePath(fileID, filePath);
        getline(input1, line);
    }

    input1.close();

    ifstream input2("Org_Persistence.txt");
    getline(input2, line);
    while (!input2.eof()) { //reads in all data for the organizations HashTable
        stringstream ss(line);
        ss >> word;

        string temp;
        while (true) { //makes sure organizations with multiple words get read in properly
            ss >> temp;
            if (temp.length() < 39) {
                word += temp;
            } else {
                break;
            }
        }

        while (ss >> fileID) {
            theIndexer.addOrganization(word, fileID);
        }
        getline(input2, line);
    }
    input2.close();

    ifstream input3("Person_Persistence.txt");
    getline(input3, line);
    while (!input3.eof()) { //reads in all data for the people HashTable
        stringstream ss(line);
        string name, temp;
        ss >> name;

        while (true) { //makes sure people with multiple words get read in properly
            ss >> temp;
            if (temp.length() < 39) {
                name += temp;
            } else {
                break;
            }
        }

        theIndexer.addPerson(name, temp);
        while (ss >> fileID) {
            theIndexer.addPerson(name, fileID);
        }
        getline(input3, line);
    }
    input3.close();
}

int DocumentParser::getArticleCount() {
    return articleCount;
}

