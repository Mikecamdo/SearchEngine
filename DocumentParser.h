//
// Created by mikec_g1kgiu8 on 11/13/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENTPARSER_H
#define INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENTPARSER_H


#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <filesystem>
#include "DSAVLTree.h"
#include <vector>
#include <map>
#include <cstdio>
#include "IndexHandler.h"

#include "include/rapidjson/document.h"
#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/filereadstream.h"

using namespace std;
namespace fs = std::filesystem;
using namespace rapidjson;

/// Class for parsing documents.
///
/// The DocumentParser includes functions to parse a set of json files
/// and extract their data.
class DocumentParser {
    private:
        Document doc;
        char** argv;

        // Absolute Path
        char* path; //program argument (assigned in the constructor)

        map<string, int> stopWords;

        /// Sets stop words.
        ///
        /// Reads from a file and inserts stop words into a map.
        void setStopWords();

        /// Function to make strings lowercase
        ///
        /// @param str is passed and returned as lowercase
        /// @returns str but lowercase
        string lowerStr(string &str);

        // Statistics
        int articleCount = 0;

public:

        /// Default constructor.
        ///
        /// Initializes argv and path to nullptr and calls setStopWords().
        DocumentParser();

        /// Overloaded constructor.
        ///
        /// Used for speed demo.
        DocumentParser(char**);

        /// Opens the files.
        ///
        /// The function opens the files and prints a loading bar to show how many files have been opened.
        /// Includes int articleCount that counts the number of articles parsed for stats.
        /// @param theIndexer is an IndexHandler object passed to the function to add data to the tree.
        void openDirUsingFileSystem(IndexHandler&);

        /// Reads data from persistence index.
        ///
        /// Opens the files Word_Persistence, Org_Persistence, and Person_Persistence and reads data from them
        /// and uses and uses an IndexHandler objet to add data to the tree.
        /// @param theIndexer is an IndexHandler object passed to the function to add data to the tree.
        void readFromPersistenceIndex(IndexHandler&);

        /// Function to parse data from the files.
        ///
        /// The function reads data from the files, trims and stems the words and passes them to theIndexer.
        /// It reads from the files and gets words, article id, names, and orgs.
        /// @param filepath is a command line argument that references the location of the files you want to read from.
        /// @param theIndexer is an IndexHandler object passed to the function to add data to the tree.
        void parse(const char*, IndexHandler&);

        /// Setter for argv
        ///
        /// @param files used to set argv which is the file path.
        void setArgv(char**);

        /// @returns an int with the number of articles parsed
        int getArticleCount();

};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENTPARSER_H
