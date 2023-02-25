//
// Created by mikec_g1kgiu8 on 11/16/2021.
//

#include "IndexHandler.h"

void IndexHandler::addWord(const string& word, const string& documentID) {
    index.insert(word).emplace_back(documentID);
    ++wordCount;
}

vector<string>& IndexHandler::findWord(const string& searchQuery) {
    return index.find(searchQuery);
}

void IndexHandler::addPerson(const string& name, const string& documentID) {
    people.add(name).emplace_back(documentID);
}

vector<string> &IndexHandler::findPerson(const string& person) {
    return people.at(person);
}

void IndexHandler::addOrganization(const string& org, const string& documentID) {
    organizations.add(org).emplace_back(documentID);
}

vector<string> &IndexHandler::findOrganization(const string& org) {
    return organizations.at(org);
}

void IndexHandler::addFrequency(const string& word, const int& frequency) {
    if (wordFrequency.count(word) == 0) { //if the word is not already in wordFrequency
        vector<int> temp;
        temp.push_back(frequency);
        wordFrequency.insert({word, temp});
    } else { //if the word is already in wordFrequency
        wordFrequency.at(word).push_back(frequency);
    }
}

vector<int> &IndexHandler::getFrequency(const string& word) {
    return wordFrequency.at(word);
}

void IndexHandler::addFilePath(const string& documentID, const string& filepath) {
    filePaths.insert({documentID, filepath});
}

string& IndexHandler::getFilePath(const string& documentID) {
    return filePaths.at(documentID);
}

void IndexHandler::doPersistence() {
    ofstream f1("Word_Persistence.txt");
    index.callPersistenceWithRoot(f1);
    f1 << "Word Frequency" << endl;
    for (auto const& element : wordFrequency) {
        f1 << element.first << " ";
        for (int i = 0; i < element.second.size(); i++) {
            f1 << element.second.at(i) << " ";
        }
        f1 << endl;
    }
    f1 << "File Paths" << endl;
    for (auto const& element : filePaths) {
        f1 << element.first << " " << element.second << endl;
    }
    f1.close();

    string fileName1 = "Org_Persistence.txt";
    organizations.doPersistence(fileName1);

    string fileName2 = "Person_Persistence.txt";
    people.doPersistence(fileName2);

}

void IndexHandler::clearIndex() {
    index.deleteTree();
    people.clear();
    organizations.clear();

    wordFrequency.clear();
    filePaths.clear();
}

int IndexHandler::getWordCount() {
    return wordCount;
}

int IndexHandler::getUniqueWordCount() {
    return index.getUniqueWordCount();
}

int IndexHandler::getUniqueOrg() {
    return organizations.getUnique();
}

int IndexHandler::getUniquePeople() {
    return people.getUnique();
}

void IndexHandler::getTopWords(vector<int>& topWordCount, vector<string>& topWords) {
    for (auto const& element : wordFrequency) {
        topWords.push_back(element.first);
        int temp = 0;
        for (int i = 0; i < element.second.size(); i++) {
             temp += element.second.at(i);
        }
        topWordCount.push_back(temp);
    }

    for (int i = 0; i < 50; i++) {
        int greatestIndex = i;
        for (int j = i + 1; j < topWordCount.size(); j++) {
            if (topWordCount.at(j) > topWordCount.at(greatestIndex)) {
                greatestIndex = j;
            }
        }
        int temp1 = topWordCount.at(i);
        topWordCount.at(i) = topWordCount.at(greatestIndex);
        topWordCount.at(greatestIndex) = temp1;

        string temp2 = topWords.at(i);
        topWords.at(i) = topWords.at(greatestIndex);
        topWords.at(greatestIndex) = temp2;
    }
}
