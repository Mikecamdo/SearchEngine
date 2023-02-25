//
// Created by mikec_g1kgiu8 on 11/16/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H
#define INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "DSAVLTree.h"
#include "DSHashTable.h"

using namespace std;

/// Handles the index and other stored information.
///
/// Handles the index (i.e. adds words and searches for words in the index).
/// Also handles the data for people entities, organization entities, word frequencies, and file paths.
class IndexHandler {
    private:
        DSAVLTree<string, vector<string>> index;
        DSHashTable<string, vector<string>> people;
        DSHashTable<string, vector<string>> organizations;

        map<string, vector<int>> wordFrequency; //the vector of frequencies is parallel to the vector of documentIDs in the index
        map<string,string> filePaths;

        int wordCount = 0;

    public:
        /// Adds a word to the index.
        ///
        /// Adds a word to the index along with its associated documentID.
        /// If the word is already in the index, the the documentID is added to the word's vector of documentIDs.
        /// @param word The word being added to the index.
        /// @param documentID The documentID associated with the word that is being added to the index.
        void addWord(const string& word, const string& documentID);

        /// Searches the index for the given word.
        ///
        /// Searches the index for the given word and returns its associated documentIDs.
        /// If the word is not in the index, then the index will throw a runtime error (which is caught in QueryEngine).
        /// @param searchQuery The word being searched for.
        /// @return The documentIds associated with the word being searched for.
        vector<string>& findWord(const string& searchQuery);

        /// Adds a person to the people HashTable.
        ///
        /// Adds a person and its associated documentID to the people HashTable.
        /// If the person is already in the people HashTable, then the documentID is added to the person's vector of documentIDs.
        /// @param name The person being added to the people HashTable.
        /// @param documentID The documentID associated with the person being added to the people HashTable.
        void addPerson(const string& name, const string& documentID);

        /// Searches the people HashTable for a given person.
        ///
        /// Searches the people HashTable for the given person and returns its associated documentIDs.
        /// If the person is not in the people HashTable, then the HashTable will throw a runtime error (which is caught in QueryEngine).
        /// @param person The person being searched for.
        /// @return The documentIDs associated with the person being searched for.
        vector<string>& findPerson(const string& person);

        /// Adds an organization to the organizations HashTable.
        ///
        /// Adds an organization and its associated documentID to the organizations HashTable.
        /// If the organization is already in the organizations HashTable, then the documentID is added to the organization's vector of documentIDs.
        /// @param org The organization being added to the organizations HashTable.
        /// @param documentID The documentID associated with the organization being added to the organizations HashTable.
        void addOrganization(const string& org, const string& documentID);

        /// Searches the organizations HashTable for a given organization.
        ///
        /// Searches the organizations HashTable for the given organization and returns its associated documentIDs.
        /// If the organization is not in the organizations HashTable, then the HashTable will throw a runtime error (which is caught in QueryEngine).
        /// @param org The organization being searched for.
        /// @return The documentIDs associated with the organization being searched for.
        vector<string>& findOrganization(const string& org);

        /// Adds a word's frequency to the wordFrequency map.
        ///
        /// Adds a word and its frequency to the wordFrequency map.
        /// If the word if already in the wordFrequency map, then the frequency is added to the word's vector of frequencies.
        /// @param word The word whose frequency is being added.
        /// @param frequency The frequency associated with the given word.
        void addFrequency(const string& word, const int& frequency);

        /// Searches the wordFrequency map for a given word.
        ///
        /// Searches the wordFrequency map for a given word and returns its associated frequencies.
        /// @param word The word being searched for.
        /// @return The frequencies associated with the word being searched for.
        vector<int>& getFrequency(const string& word);

        /// Adds a documentID and its filepath to the filePaths map.
        ///
        /// Adds a documentID and its filepath to the filePaths map.
        /// @param documentID The documentID being added to the filePaths map.
        /// @param filepath The filepath associated with the given documentID.
        void addFilePath(const string& documentID, const string& filepath);

        /// Searches the filePaths map for a given documentID.
        ///
        /// Searches the filePaths map for a given documentID and returns its associated filePath.
        /// @param documentID The documentID being searched for.
        /// @return The filepath associated with the documentID being searched for.
        string& getFilePath(const string& documentID);

        /// Writes the persistence files.
        ///
        /// Writes the persistence files for the index, the organizations HashTable, and the people HashTable.
        /// The filepaths and frequencies are stored in the index's persistence file.
        void doPersistence();

        /// Clears all data that the IndexHandler contains.
        ///
        /// Clears all data from the index, the organizations HashTable, the people HashTable, the wordFrequency map, and the filePaths map.
        void clearIndex();

        /// Returns the number of processed words.
        ///
        /// Returns the number of processed words (not including stop words) that is used to calculate average number of indexed words per document.
        /// @return The number of processed words (not including stop words)
        int getWordCount();

        /// Finds the number of words in the index.
        ///
        /// Finds the number of words in the index and returns the value.
        /// @return The number of words in the index (which equates to the number of unique words).
        int getUniqueWordCount();

        /// Finds the number of organizations in the organizations HashTable.
        ///
        /// Finds the number of organizations in the organizations HashTable and returns the value.
        /// @return The number of organizations in the organizations HashTable (which equates to the number of unique organizations).
        int getUniqueOrg();

        /// Finds the number of people in the people HashTable.
        ///
        /// Finds the number of people in the people HashTable and returns the value.
        /// @return The number of people in the people HashTable (which equates to the number of unique people).
        int getUniquePeople();

        /// Finds the top 50 words by frequency.
        ///
        /// Finds and prints the top 50 words by frequency.
        /// It does so by iterating through every word in wordFrequency,
        /// adding up all of its frequencies, and sorting the resulting vectors for the first 50 elements.
        void getTopWords(vector<int>&, vector<string>&);

};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H
