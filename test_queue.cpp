#define BOOST_TEST_MODULE QueueTest
#include <boost/test/included/unit_test.hpp>
#include "queue.h"

BOOST_AUTO_TEST_CASE(test_push_pop) {
    Queue q;

    q.push("1");
    BOOST_CHECK_EQUAL(q.head->val, "1");
    BOOST_CHECK_EQUAL(q.tail->val, "1");

    q.push("2");
    BOOST_CHECK_EQUAL(q.head->val, "1");
    BOOST_CHECK_EQUAL(q.tail->val, "2");

    q.push("3");
    BOOST_CHECK_EQUAL(q.head->val, "1");
    BOOST_CHECK_EQUAL(q.tail->val, "3");

    q.pop();
    BOOST_CHECK_EQUAL(q.head->val, "2");
    BOOST_CHECK_EQUAL(q.tail->val, "3");

    q.pop();
    BOOST_CHECK_EQUAL(q.head->val, "3");
    BOOST_CHECK_EQUAL(q.tail->val, "3");

    q.pop();
    BOOST_CHECK(q.head == nullptr);
    BOOST_CHECK(q.tail == nullptr);
}

BOOST_AUTO_TEST_CASE(test_print) {
    Queue q;
    q.push("1");
    q.push("2");
    q.push("3");
    string file = "queue.data";
    string namestruct = "@q";
    q.print(file, namestruct);
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
