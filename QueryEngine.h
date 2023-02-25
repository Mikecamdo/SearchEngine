//
// Created by mikec_g1kgiu8 on 11/16/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_QUERYENGINE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_QUERYENGINE_H

#include "IndexHandler.h"
#include "DocumentParser.h"
#include <string>
#include <sstream>
#include <vector>
#include "porter2_stemmer.h"

#include "include/rapidjson/document.h"
#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/filereadstream.h"



using namespace std;
/// QueryEngine class.
///
/// The QueryEngine class handles most of the functionality needed for SearchEngine::start() to run.
class QueryEngine {
    private:
        IndexHandler theIndexer;
        DocumentParser theParser;

        /// Function to make strings lowercase.
        ///
        /// @param str is passed and returned as lowercase.
        /// @returns str but lowercase.
        string lowerStr(string&);

        /// Sort function.
        ///
        /// The function sorts words by how many times they have appeared in the dataset.
        /// @param requiredFiles is a vector of files that meet the search term requirements.
        /// @param theSearchTerms is a vector of search terms.
        void sortByFrequency(vector<string>&, vector<string>&);

        /// Print function.
        ///
        /// Prints out the document and its title, publisher, and website.
        /// @param requiredFiles is a vector of files that meet the search term requirements.
        /// @param size is used to loop through the print function size times.
        void printResults(const vector<string>&, const int&);

    public:
        /// Default constructor.
        QueryEngine();

        /// Opens files.
        ///
        /// Uses QueryEngine::theParser to call DocumentParser::openDirUsingFileSystem()
        void initializeIndexWithFiles();

        /// Reads files using persistence index.
        ///
        /// Uses QueryEngine::theParser to call DocumentParser::readFromPersistenceIndex()
        void initializeIndexWithPersistence();

        /// Clears the index.
        ///
        /// Uses QueryEngine::theParser to call DocumentParser::clearIndex()
        void clearIndex();

        /// Calls persistence function.
        ///
        /// Uses QueryEngine::theParser to call DocumentParser::doPersistence()
        void doPersistence();

        /// Searches for a word.
        ///
        /// Searches for the passed word searchQuery.
        /// @param searchQuery is a string of the word you want to search for
        void search(const string&);

        /// Function to set argv.
        ///
        /// Uses QueryEngine::theParser to call DocumentParser::setArgv()
        /// @param files is the variable you want to set argv as
        void setArgv(char**);

        /// Gets number of articles parsed.
        /// @returns an int of the number of articles parsed
        int getArticleCount();

        /// Gets average words indexed.
        /// @returns an int of the average number of words indexed
        int getAvgWordsIndexed();

        /// Gets the number of unique words in the tree.
        /// @returns an int of the number of unique words in the tree
        int getUniqueWords();

        /// Gets the number of unique orgs.
        /// @returns an int of the number of unique orgs
        int getUniqueOrg();

        /// Gets the number of unique people.
        /// @returns an int of the number of unique people
        int getUniquePeople();

        /// Prints top 50 most common words.
        ///
        /// Used for stats to print the 50 most common words and how many times they were used
        void printTopWords();


};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_QUERYENGINE_H
