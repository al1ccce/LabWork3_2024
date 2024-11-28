#define BOOST_TEST_MODULE StackTest
#include <boost/test/included/unit_test.hpp>
#include "stack.h"

BOOST_AUTO_TEST_CASE(test_push_pop) {
    Stack mystack;
    mystack.addHead("1");
    BOOST_CHECK_EQUAL(mystack.head->val, "1");
    mystack.addHead("2");
    BOOST_CHECK_EQUAL(mystack.head->val, "2");
    mystack.deleteHead();
    BOOST_CHECK_EQUAL(mystack.head->val, "1");
    BOOST_CHECK_EQUAL(mystack.head->next, nullptr);
}

BOOST_AUTO_TEST_CASE(test_print) {
    Stack mystack;
    mystack.addHead("1");
    mystack.addHead("2");
    mystack.addHead("3");
    string file = "stack.data";
    string namestruct = "@mystack";
    mystack.print(file, namestruct);
    ifstream in(file);
    string line;
    getline(in, line);
    BOOST_CHECK_EQUAL(line, namestruct);
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "3");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "2");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "1");
    in.close();
    remove(file.c_str());
}