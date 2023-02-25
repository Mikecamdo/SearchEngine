//
// Created by mikec_g1kgiu8 on 11/16/2021.
//

#include "catch.hpp"
#include "DSAVLTree.h"
#include <string>
#include <vector>

using namespace std;

TEST_CASE("DSAVLTree class", "[DSAVLTree]") {
    DSAVLTree<int, int> tester1;
    DSAVLTree<string, string> tester2;
    DSAVLTree<char, string> tester3;
    DSAVLTree<string, vector<string>> tester4;


    SECTION("Insert/Find Functions") {
        tester1.insert(1) = 100;
        tester1.insert(4) = 400;
        tester1.insert(20) = 2000;

        CHECK(tester1.find(1) == 100);
        CHECK(tester1.find(4) == 400);
        CHECK(tester1.find(20) == 2000);

        tester2.insert("Hello") = "Hi";
        tester2.insert("Goodbye") = "Bye";
        tester2.insert("Yes") = "Affirmative";

        CHECK(tester2.find("Hello") == "Hi");
        CHECK(tester2.find("Goodbye") == "Bye");
        CHECK(tester2.find("Yes") == "Affirmative");

        tester3.insert('c') = "cookies";
        tester3.insert('w') = "watermelon";
        tester3.insert('z') = "zebra";

        CHECK(tester3.find('c') == "cookies");
        CHECK(tester3.find('w') == "watermelon");
        CHECK(tester3.find('z') == "zebra");

        vector<string> badGuys;
        badGuys.emplace_back("Joker");
        badGuys.emplace_back("Thanos");
        badGuys.emplace_back("Darth Vader");

        vector<string> goodGuys;
        goodGuys.emplace_back("Superman");
        goodGuys.emplace_back("Iron Man");
        goodGuys.emplace_back("Luke Skywalker");

        tester4.insert("Bad Guys") = badGuys;
        tester4.insert("Good Guys") = goodGuys;

        CHECK(tester4.find("Bad Guys").at(0) == "Joker");
        CHECK(tester4.find("Bad Guys").at(1) == "Thanos");
        CHECK(tester4.find("Bad Guys").at(2) == "Darth Vader");
        CHECK(tester4.find("Bad Guys") == badGuys);

        CHECK(tester4.find("Good Guys").at(0) == "Superman");
        CHECK(tester4.find("Good Guys").at(1) == "Iron Man");
        CHECK(tester4.find("Good Guys").at(2) == "Luke Skywalker");
        CHECK(tester4.find("Good Guys") == goodGuys);

    }

    SECTION("DeleteTree Function") {
        tester1.insert(1) = 100;
        tester1.insert(2) = 200;
        tester1.insert(3) = 300;

        tester1.deleteTree();

        CHECK_THROWS(tester1.find(1));
        CHECK_THROWS(tester1.find(2));
        CHECK_THROWS(tester1.find(3));

        tester2.insert("Hello") = "Hi";
        tester2.insert("Goodbye") = "Bye";
        tester2.insert("Yes") = "Affirmative";

        tester2.deleteTree();

        CHECK_THROWS(tester2.find("Hello"));
        CHECK_THROWS(tester2.find("Goodbye"));
        CHECK_THROWS(tester2.find("Yes"));

        tester3.insert('c') = "cookies";
        tester3.insert('w') = "watermelon";
        tester3.insert('z') = "zebra";

        tester3.deleteTree();

        CHECK_THROWS(tester3.find('c'));
        CHECK_THROWS(tester3.find('w'));
        CHECK_THROWS(tester3.find('z'));

        vector<string> badGuys;
        badGuys.emplace_back("Joker");
        badGuys.emplace_back("Thanos");
        badGuys.emplace_back("Darth Vader");

        vector<string> goodGuys;
        goodGuys.emplace_back("Superman");
        goodGuys.emplace_back("Iron Man");
        goodGuys.emplace_back("Luke Skywalker");

        tester4.insert("Bad Guys") = badGuys;
        tester4.insert("Good Guys") = goodGuys;

        tester4.deleteTree();

        CHECK_THROWS(tester4.find("Bad Guys"));
        CHECK_THROWS(tester4.find("Good Guys"));


    }

    SECTION("Copy Constructor") {
        tester1.insert(17) = 1700;
        tester1.insert(0) = 0;
        tester1.insert(-99) = -9900;

        DSAVLTree<int, int> tester5(tester1);

        tester1.insert(2) = 200;

        CHECK_THROWS(tester5.find(2));

        vector<string> badGuys;
        badGuys.emplace_back("Joker");
        badGuys.emplace_back("Thanos");
        badGuys.emplace_back("Darth Vader");

        vector<string> goodGuys;
        goodGuys.emplace_back("Superman");
        goodGuys.emplace_back("Iron Man");
        goodGuys.emplace_back("Luke Skywalker");

        tester4.insert("Bad Guys") = badGuys;
        tester4.insert("Good Guys") = goodGuys;

        DSAVLTree<string, vector<string>> tester6(tester4);

        tester4.deleteTree();

        CHECK(tester6.find("Bad Guys") == badGuys);
        CHECK(tester6.find("Good Guys") == goodGuys);

    }

    SECTION("= operator") {
        tester1.insert(12) = 1200;
        tester1.insert(4) = 400;

        DSAVLTree<int, int> tester5;
        tester5 = tester1;

        CHECK_THROWS(tester5.find(2));

        vector<string> badGuys;
        badGuys.emplace_back("Joker");
        badGuys.emplace_back("Thanos");
        badGuys.emplace_back("Darth Vader");

        vector<string> goodGuys;
        goodGuys.emplace_back("Superman");
        goodGuys.emplace_back("Iron Man");
        goodGuys.emplace_back("Luke Skywalker");

        tester4.insert("Bad Guys") = badGuys;
        tester4.insert("Good Guys") = goodGuys;

        DSAVLTree<string, vector<string>> tester6;
        tester6 = tester4;

        tester4.deleteTree();

        CHECK(tester6.find("Bad Guys") == badGuys);
        CHECK(tester6.find("Good Guys") == goodGuys);
    }
}
