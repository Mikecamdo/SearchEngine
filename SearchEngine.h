//
// Created by mikec_g1kgiu8 on 11/16/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_SEARCHENGINE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_SEARCHENGINE_H

#include "DSAVLTree.h"
#include "DocumentParser.h"
#include "QueryEngine.h"
#include "IndexHandler.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

/// Class used for menuing.
///
/// This class loops through a menu with options for loading / deleting data, searching for words,
/// showing statistics, and writing to the persistence files.
class SearchEngine {
    private:
        QueryEngine theProcessor;
        bool Persistence = false;

    public:
        /// Default constructor.
        ///
        /// @param files is used to call the QueryEngine function setArgv() to set the file path.
        SearchEngine(char**);

        /// Runs the menuing
        ///
        /// Menu options include
        /// 1) Load/Delete Data
        /// 2) Execute Query
        /// 3) Show Statistics
        /// 4) Write Persistence File
        /// 5) Exit
        void start();

};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_SEARCHENGINE_H
