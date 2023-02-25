cmake_minimum_required(VERSION 3.16)
project(21f_final_proj_template)

set(CMAKE_CXX_STANDARD 17)

add_executable(21f_final_proj_template main.cpp catch_setup.cpp DSAVLTree.h DocumentParser.cpp DocumentParser.h blogs_0000001.json SearchEngine.cpp SearchEngine.h IndexHandler.cpp IndexHandler.h QueryEngine.cpp QueryEngine.h DSAVLTreeTests.cpp diffs.txt porter2_stemmer.cpp porter2_stemmer.h util util/hash.h util/string_view.h DSHashTable.h DSHashTableTests.cpp Person_Persistence.txt Org_Persistence.txt Word_Persistence.txt Stats_Persistence.txt)
