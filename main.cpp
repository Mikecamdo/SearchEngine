#include "DSAVLTree.h"
#include "DocumentParser.h"
#include "SearchEngine.h"
#include "catch_setup.h"

using namespace std;

/// Main method.
///
/// If there are command line arguments, then it starts the search engine. Otherwise, it runs catch tests.
/// @param argc The number of command line arguments.
/// @param argv The command line arguments.
/// @return 0 (to end the program)
int main(int argc, char** argv) {
    if (argc == 1) {
        runCatchTests();
    } else {
        static SearchEngine Google(argv);
        Google.start();
    }
    return 0;
}