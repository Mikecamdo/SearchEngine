//
// Created by mikec_g1kgiu8 on 11/16/2021.
//

#include "QueryEngine.h"

QueryEngine::QueryEngine() {

}

void QueryEngine::initializeIndexWithFiles() {
    theParser.openDirUsingFileSystem(theIndexer);
}

void QueryEngine::initializeIndexWithPersistence() {
    theParser.readFromPersistenceIndex(theIndexer);
}

void QueryEngine::search(const string& searchQuery) {
    stringstream ss(searchQuery); //string stream for the whole search term
    string searchWord;
    vector<string> requiredFiles; //all the files that meet the search criteria
    vector<string> theSearchTerms; //every word in the searchQuery

    while (ss >> searchWord) { //loop that goes through the entire search query
        if (searchWord == "AND") { //if the query starts with AND
            vector<string> searchWords;

            while (ss >> searchWord && searchWord != "NOT" && searchWord != "PERSON" && searchWord != "ORG") { //reads in all words that AND applies to
                searchWord = lowerStr(searchWord); // Convert Word To Lowercase
                Porter2Stemmer::trim(searchWord); // Remove Punctuation
                Porter2Stemmer::stem(searchWord); // Stem The Word

                searchWords.push_back(searchWord);
                theSearchTerms.push_back(searchWord);
            }
            try {
                requiredFiles = theIndexer.findWord(searchWords.at(0)); //required files is all the files the first word is in

                for (int i = 1; i < searchWords.size(); i++) { //loops through every other word that was part of the AND search
                    vector<string> temp = theIndexer.findWord(searchWords.at(i));

                    for (int j = 0; j < requiredFiles.size(); j++) {
                        bool inCommon = false;
                        for (int k = 0; k < temp.size(); k++) {
                            if (requiredFiles.at(j) == temp.at(k)) { //if the document in requiredFiles is one of the word's documents
                                inCommon = true;
                                break;
                            }
                        }
                        if (!inCommon) { //if the document in requiredFiles was not one of the word's documents
                            requiredFiles.erase(requiredFiles.begin() + j);
                            --j; //Needed since erasing a value changes the size of the vector
                        }
                    }
                }

            } catch (std::runtime_error &e) { //if one of the terms is not in the AVLTree
                cout << "No files found with the given search parameters" << endl;
                return;
            }
        } else if (searchWord == "OR") { //if the query starts with OR
            vector<string> searchWords;

            while (ss >> searchWord && searchWord != "NOT" && searchWord != "PERSON" && searchWord != "ORG") {
                searchWord = lowerStr(searchWord); // Convert Word To Lowercase
                Porter2Stemmer::trim(searchWord); // Remove Punctuation
                Porter2Stemmer::stem(searchWord); // Stem The Word

                searchWords.push_back(searchWord);
                theSearchTerms.push_back(searchWord);
            }

            for (int i = 0; i < searchWords.size(); i++) { //remove all words that do not exist in the index
                try {
                    theIndexer.findWord(searchWords.at(i));
                } catch (std::runtime_error &e) {
                    searchWords.erase(searchWords.begin() + i);
                    theSearchTerms.erase(theSearchTerms.begin() + i);
                    --i;
                }
            }

            requiredFiles = theIndexer.findWord(searchWords.at(0));

            for (int i = 1; i < searchWords.size(); i++) { //loops through all words that are part of the OR query
                vector<string> temp = theIndexer.findWord(searchWords.at(i));

                for (int j = 0; j < temp.size(); j++) {
                    bool inCommon = false;
                    for (int k = 0; k < requiredFiles.size(); k++) {
                        if (temp.at(j) == requiredFiles.at(k)) { //if the document is already in requiredFiles
                            inCommon = true;
                            break;
                        }
                    }
                    if (!inCommon) { //if the document is not in requiredFiles
                        requiredFiles.push_back(temp.at(j));
                    }
                }
            }

        }
        if (searchWord == "NOT") { //if NOT is in the query
            ss >> searchWord;
            try {
                vector<string> badFiles = theIndexer.findWord(searchWord);
                for (int i = 0; i < requiredFiles.size(); i++) {
                    for (int j = 0; j < badFiles.size(); j++) {
                        if (requiredFiles.at(i) == badFiles.at(j)) { //if one of requiredFile's documents is one of the NOT term's documents
                            requiredFiles.erase(requiredFiles.begin() + i); //erase the document from requiredFiles
                            --i;
                        }
                    }
                }
            } catch (std::runtime_error &e) { //if the NOT term is not in the index
                continue;
            }
        } else if (searchWord == "ORG") { //if ORG is in the query
            if (requiredFiles.empty()) { //if the query begins with ORG
                try {
                    ss >> searchWord;
                    requiredFiles = theIndexer.findOrganization(searchWord);
                } catch (std::runtime_error &e) { //if the organization is not in the HashTable
                    cout << "No files found with the given search parameters" << endl;
                    return;
                }
            } else {
                ss >> searchWord;
                try {
                    vector<string> orgFiles = theIndexer.findOrganization(searchWord);
                    for (int i = 0; i < requiredFiles.size(); i++) {
                        bool inCommon = false;
                        for (int j = 0; j < orgFiles.size(); j++) {
                            if (requiredFiles.at(i) == orgFiles.at(j)) { //if requiredFile's document is one of the organization's documents
                                inCommon = true;
                                break;
                            }
                        }
                        if (!inCommon) { //if requiredFile's document is not one of the organization's documents
                            requiredFiles.erase(requiredFiles.begin() + i);
                            --i; //Needed since erasing a value changes the size of the vector
                        }
                    }
                } catch (std::runtime_error &e) { //if the organization is not in the HashTable
                    cout << "No files found with the given search parameters" << endl;
                    return;
                }
            }

        } else if (searchWord == "PERSON") { //if PERSON is in the query
            if (requiredFiles.empty()) { //if the query begins with PERSON
                try {
                    ss >> searchWord;
                    requiredFiles = theIndexer.findPerson(searchWord);
                } catch (std::runtime_error &e) { //if the person is not in the HashTable
                    cout << "No files found with the given search parameters" << endl;
                    return;
                }
            } else {
                ss >> searchWord;
                try {
                    vector<string> personFiles = theIndexer.findPerson(searchWord);

                    for (int i = 0; i < requiredFiles.size(); i++) {
                        bool inCommon = false;
                        for (int j = 0; j < personFiles.size(); j++) {
                            if (requiredFiles.at(i) == personFiles.at(j)) { //if requiredFile's document is one of the person's documents
                                inCommon = true;
                                break;
                            }
                        }
                        if (!inCommon) { //if requiredFile's document is not one of the person's documents
                            requiredFiles.erase(requiredFiles.begin() + i);
                            --i; //Needed since erasing a value changes the size of the vector
                        }
                    }
                } catch (std::runtime_error &e) { //if the person is not in the HashTable
                    cout << "No files found with the given search parameters" << endl;
                    return;
                }
            }
        } else { //if the query does not begin with AND/OR/ORG/PERSON
            searchWord = lowerStr(searchWord); // Convert Word To Lowercase
            Porter2Stemmer::trim(searchWord); // Remove Punctuation
            Porter2Stemmer::stem(searchWord); // Stem The Word

            theSearchTerms.push_back(searchWord);

            try {
                requiredFiles = theIndexer.findWord(searchWord);
            } catch (std::runtime_error &e) { //if the word is not in the index
                cout << "No files found with the given search parameters" << endl;
                return;
            }
        }
    }

    if (requiredFiles.empty()) { //if no satisfactory documents exist
        cout << "No files found with the given search parameters" << endl;
    } else {
        sortByFrequency(requiredFiles, theSearchTerms); //sort by relevancy
        cout << "Results: " << endl;

        int numArticles;
        if (requiredFiles.size() > 15) { //prevents more than 15 articles from being printed
            printResults(requiredFiles, 15);
            numArticles = 15;
        } else {
            printResults(requiredFiles, requiredFiles.size());
            numArticles = requiredFiles.size();
        }

        int userInput;
        cout << "Enter the number of the article you want to view, or enter 0 to return to the main menu: ";
        cin >> userInput;
        cin.ignore();
        if (userInput == 0) {
            //Do nothing and return to the main menu
        } else if (userInput <= numArticles && userInput > 0) { //print the information of the valid article number requested
            string theFilePath = theIndexer.getFilePath(requiredFiles.at(userInput - 1));
            const char* filepath = theFilePath.c_str();

            FILE* fp = fopen(filepath, "rb");

            char readBuffer[65536];
            FileReadStream is (fp, readBuffer, sizeof(readBuffer));

            Document document;
            document.ParseStream(is);

            cout << document["title"].GetString() << endl;
            cout << document["text"].GetString() << endl;
            cout << document["published"].GetString() << endl;
            cout << document["thread"]["site"].GetString() << endl << endl;

            fclose(fp);

        } else { //for invalid input
            cout << "Invalid choice, returning to main menu" << endl;
        }

    }

}

void QueryEngine::setArgv(char** files) {
    theParser.setArgv(files);
}

string QueryEngine::lowerStr(string &str) {
    char charArray[str.length() + 1];
    strcpy(charArray, str.c_str());

    for (int i = 0 ; i < str.length() ; i++) {
        charArray[i] = (tolower(charArray[i]));
    }
    string output = charArray;
    return output;
}

void QueryEngine::doPersistence() {
    theIndexer.doPersistence();
}

void QueryEngine::sortByFrequency(vector<string>& requiredFiles, vector<string>& theSearchTerms) {
    vector<int> totalFrequency;
    for (int i = 0; i < requiredFiles.size(); i++) { //loop that adds up each relevant word's frequency in each document
        totalFrequency.push_back(0);
        for (int j = 0; j < theSearchTerms.size(); j++) {
            vector<string> temp = theIndexer.findWord(theSearchTerms.at(j));
            for (int k = 0; k < temp.size(); k++) {
                if (temp.at(k) == requiredFiles.at(i)) {
                    totalFrequency.back() += theIndexer.getFrequency(theSearchTerms.at(j)).at(k);
                }
            }
        }
    }

    for (int i = 0; i < totalFrequency.size(); i++) { //sorts the list of documents by the best total frequency (across all words)
        int greatestIndex = i;
        for (int j = i + 1; j < totalFrequency.size(); j++) {
            if (totalFrequency.at(j) > totalFrequency.at(greatestIndex)) {
                greatestIndex = j;
            }
        }
        int temp1 = totalFrequency.at(i);
        totalFrequency.at(i) = totalFrequency.at(greatestIndex);
        totalFrequency.at(greatestIndex) = temp1;

        string temp2 = requiredFiles.at(i);
        requiredFiles.at(i) = requiredFiles.at(greatestIndex);
        requiredFiles.at(greatestIndex) = temp2;
    }
}

void QueryEngine::printResults(const vector<string>& requiredFiles, const int& size) {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ":" << endl;
            string theFilePath = theIndexer.getFilePath(requiredFiles.at(i)); //finds the documentID's filepath
            const char* filepath = theFilePath.c_str();

            FILE* fp = fopen(filepath, "rb");

            char readBuffer[65536];
            FileReadStream is (fp, readBuffer, sizeof(readBuffer));

            Document document;
            document.ParseStream(is);

            cout << document["title"].GetString() << endl;
            cout << document["published"].GetString() << endl;
            cout << document["thread"]["site"].GetString() << endl << endl;

            fclose(fp);
        }

}

void QueryEngine::clearIndex() {
    theIndexer.clearIndex();
}

int QueryEngine::getArticleCount() {
    return theParser.getArticleCount();
}

int QueryEngine::getAvgWordsIndexed() {
    return (theIndexer.getWordCount() / theParser.getArticleCount());
}

int QueryEngine::getUniqueWords() {
    return theIndexer.getUniqueWordCount();
}

int QueryEngine::getUniqueOrg() {
    return theIndexer.getUniqueOrg();
}

int QueryEngine::getUniquePeople() {
    return theIndexer.getUniquePeople();
}

void QueryEngine::printTopWords() {
    vector<int> topWordCount;
    vector<string> topWords;
    theIndexer.getTopWords(topWordCount, topWords);
    for (int i = 0; i < 50; i++) {
        cout << topWords.at(i) << ": " << topWordCount.at(i) << endl;
    }
}
