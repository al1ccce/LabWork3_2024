#define BOOST_TEST_MODULE DLinkedListTest
#include <boost/test/included/unit_test.hpp>
#include "dlist.h"

BOOST_AUTO_TEST_CASE(test_addhead_addtail_find) {
    DoubleLinkedList dlist;
    dlist.addHead("head");
    BOOST_CHECK_EQUAL(dlist.head->val, "head");
    BOOST_CHECK_EQUAL(dlist.tail->val, "head");
    dlist.addHead("newhead");
    BOOST_CHECK_EQUAL(dlist.head->val, "newhead");
    BOOST_CHECK_EQUAL(dlist.head->next->val, "head");
    BOOST_CHECK_EQUAL(dlist.tail->val, "head");
    BOOST_CHECK(!dlist.find("unexisted"));
    dlist.addTail("tail");
    BOOST_CHECK_EQUAL(dlist.tail->val, "tail");
    BOOST_CHECK_EQUAL(dlist.head->next->next->val, "tail");
    dlist.addTail("newtail");
    BOOST_CHECK(dlist.find("newtail"));
}

BOOST_AUTO_TEST_CASE(test_delhead_deltail_delval) {
    DoubleLinkedList dlist;
    dlist.addHead("head");
    dlist.addTail("el1");
    dlist.addTail("el2");
    dlist.addTail("tail");
    dlist.deleteHead();
    BOOST_CHECK_EQUAL(dlist.head->val, "el1");
    BOOST_CHECK_EQUAL(dlist.head->prev, nullptr);
    dlist.deleteTail();
    BOOST_CHECK_EQUAL(dlist.tail->val, "el2");
    dlist.addHead("head");
    dlist.deleteValue("el1");
    BOOST_CHECK_EQUAL(dlist.head->next->val, "el2");
    dlist.deleteValue("head");
    BOOST_CHECK_EQUAL(dlist.head->val, "el2");
    dlist.deleteHead();
    BOOST_CHECK_EQUAL(dlist.head, nullptr);
    BOOST_CHECK_EQUAL(dlist.tail, nullptr);
    dlist.addHead("headdd");
    dlist.deleteTail();
    BOOST_CHECK_EQUAL(dlist.head, nullptr);
    BOOST_CHECK_EQUAL(dlist.tail, nullptr);
}

BOOST_AUTO_TEST_CASE(test_print) {
    DoubleLinkedList dlist;
    dlist.addTail("1");
    dlist.addTail("2");
    dlist.addTail("3");
    string file = "list.data";
    string namestruct = "@mylist";
    dlist.print(file, namestruct);
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