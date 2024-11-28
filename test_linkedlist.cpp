#define BOOST_TEST_MODULE LinkedListTest
#include <boost/test/included/unit_test.hpp>
#include "list.h"

BOOST_AUTO_TEST_CASE(test_addhead_addtail_find) {
    LinkedList flist;
    flist.addHead("head");
    BOOST_CHECK_EQUAL(flist.head->val, "head");
    flist.addHead("newhead");
    BOOST_CHECK_EQUAL(flist.head->val, "newhead");
    BOOST_CHECK(flist.head->next != nullptr);
    BOOST_CHECK_EQUAL(flist.head->next->val, "head");
    BOOST_CHECK(!flist.find("unexisted"));
    flist.addTail("tail");
    BOOST_CHECK(flist.head->next->next != nullptr);
    BOOST_CHECK_EQUAL(flist.head->next->next->val, "tail");
    flist.addTail("newtail");
    BOOST_CHECK(flist.find("newtail"));
}

BOOST_AUTO_TEST_CASE(test_delhead_deltail_delval) {
    LinkedList flist;
    flist.addHead("head");
    flist.addTail("el1");
    flist.addTail("el2");
    flist.addTail("tail");
    flist.deleteHead();
    BOOST_CHECK_EQUAL(flist.head->val, "el1");
    flist.deleteTail();
    BOOST_CHECK(flist.head->next->next == nullptr);
    BOOST_CHECK_EQUAL(flist.head->next->val, "el2");
    flist.deleteValue("el1");
    BOOST_CHECK_EQUAL(flist.head->val, "el2");
    flist.addHead("head");
    flist.deleteValue("el2");
    BOOST_CHECK_EQUAL(flist.head->val, "head");
}

BOOST_AUTO_TEST_CASE(test_print) {
    LinkedList flist;
    flist.addTail("1");
    flist.addTail("2");
    flist.addTail("3");
    string file = "list.data";
    string namestruct = "@mylist";
    flist.print(file, namestruct);
    ifstream in(file);
    string line;
    getline(in, line);
    BOOST_CHECK_EQUAL(line, namestruct);
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "1");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "2");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "3");
    in.close();
    remove(file.c_str());
}