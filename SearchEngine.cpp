//
// Created by mikec_g1kgiu8 on 11/16/2021.
//

#include "SearchEngine.h"

SearchEngine::SearchEngine(char** files) {
    theProcessor.setArgv(files);
}

void SearchEngine::start() {
    string userInput;
    bool dataLoaded = false;

    while(true) {
        cout << "Main Menu" << endl;
        cout << "1) Load/Delete Data" << endl;
        cout << "2) Execute Query" << endl;
        cout << "3) Show Statistics" << endl;
        cout << "4) Write Persistence File" << endl;
        cout << "5) Exit" << endl;

        getline(cin, userInput);

        if (userInput == "1") {
            cout << "1) Load Data from Files" << endl;
            cout << "2) Load Data from Persistence Index" << endl;
            cout << "3) Delete All Data" << endl;
            getline(cin, userInput);
            if (userInput == "1") {
                theProcessor.initializeIndexWithFiles();
                dataLoaded = true;
                cout << "Complete" << endl;
            } else if (userInput == "2") {
                theProcessor.initializeIndexWithPersistence();
                dataLoaded = true;
                Persistence = true;
                cout << "Complete" << endl;
            } else if (userInput == "3") {
                theProcessor.clearIndex();
                cout << "Complete" << endl;
            } else {
                cout << "Invalid input, returning to the main menu" << endl;
            }
        } else if (userInput == "2") {
            if (dataLoaded) {
                cout << "Enter a term you want to search for:";
                string searchTerm;
                getline(cin, searchTerm);
                theProcessor.search(searchTerm);
            } else {
                cout << "Error: There is no data to search. Please load data and try again." << endl;
            }
        } else if (userInput == "3") {
            if (Persistence) {
                ifstream file;
                string line;
                file.open("Stats_Persistence.txt");
                while (getline(file,line)) {
                    cout << line << '\n';
                }
                file.close();
            } else {
                cout << "Number of articles: " << theProcessor.getArticleCount() << endl;
                cout << "Average words indexed per article: " << theProcessor.getAvgWordsIndexed() << endl;
                cout << "Unique words indexed: " << theProcessor.getUniqueWords() << endl;
                cout << "Unique people indexed: " << theProcessor.getUniquePeople() << endl;
                cout << "Unique orgs indexed: " << theProcessor.getUniqueOrg() << endl;
            }
            theProcessor.printTopWords();
        } else if (userInput == "4") {
            theProcessor.doPersistence();
            // Write Stats To Persistence
            ofstream file;
            file.open("Stats_Persistence.txt");
            file << "Number of articles: " << theProcessor.getArticleCount() << "\n";
            file << "Average words indexed per article: " << theProcessor.getAvgWordsIndexed() << "\n";
            file << "Unique words indexed: " << theProcessor.getUniqueWords() << "\n";
            file << "Unique people indexed: " << theProcessor.getUniquePeople() << "\n";
            file << "Unique orgs indexed: " << theProcessor.getUniqueOrg() << "\n";
            file.close();
            cout << "Complete" << endl;
        } else if (userInput == "5") {
            break;
        } else {
            cout << "Invalid input. Try again." << endl;
        }
    }
}
