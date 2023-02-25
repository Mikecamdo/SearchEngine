//
// Created by mikec_g1kgiu8 on 12/3/2021.
//

#include "catch.hpp"
#include "DSHashTable.h"
#include <vector>
#include <string>

using namespace std;

TEST_CASE("DSHashTable class", "[DSHashTable]") {
    static DSHashTable<string, vector<string>> tester1;
    static DSHashTable<char, int> tester2;
    static DSHashTable<bool, string> tester3;

    SECTION("Add/At Function") {
        tester1.add("George").emplace_back("214");
        tester1.add("George").emplace_back("2209");
        tester1.add("Robert").emplace_back("1738");

        CHECK(tester1.at("George").at(0) == "214");
        CHECK(tester1.at("George").at(1) == "2209");
        CHECK(tester1.at("Robert").at(0) == "1738");

        tester2.add('C') = 3;
        tester2.add('z') = 198;
        tester2.add('~') = 2001;

        CHECK(tester2.at('C') == 3);
        CHECK(tester2.at('z') == 198);
        CHECK(tester2.at('~') == 2001);

        tester3.add(true) = "Truth";
        tester3.add(false) = "Falsity";

        CHECK(tester3.at(true) == "Truth");
        CHECK(tester3.at(false) == "Falsity");
    }

    SECTION("Clear Function") {
        tester2.add('C') = 3;
        tester2.add('z') = 198;
        tester2.add('~') = 2001;

        tester2.clear();

        CHECK_THROWS(tester2.at('C') == 3);
        CHECK_THROWS(tester2.at('z') == 198);
        CHECK_THROWS(tester2.at('~') == 2001);

        tester3.add(true) = "Truth";
        tester3.add(false) = "Falsity";

        CHECK_THROWS(tester3.at(true) == "Truth");
        CHECK_THROWS(tester3.at(false) == "Falsity");
    }
}