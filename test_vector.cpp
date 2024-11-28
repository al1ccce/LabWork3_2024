#define BOOST_TEST_MODULE VectorTest
#include <boost/test/included/unit_test.hpp>
#include "vector.h"

BOOST_AUTO_TEST_CASE(test_pushback_pushidx) {
    Vector vectorik(2);
    vectorik.push_back("1");
    BOOST_CHECK_EQUAL(vectorik.vec[vectorik.size-1], "1");
    vectorik.push_back("2");
    BOOST_CHECK_EQUAL(vectorik.vec[vectorik.size-1], "2");
    vectorik.push_idx("3", 0);
    BOOST_CHECK_EQUAL(vectorik.vec[0], "3");
}

BOOST_AUTO_TEST_CASE(test_deleteidx_exchange_get) {
    Vector vectorik;
    vectorik.push_back("0");
    vectorik.push_back("1");
    vectorik.push_back("2");
    vectorik.push_back("3");
    vectorik.delete_idx(0);
    BOOST_CHECK_EQUAL(vectorik.vec[0], "1");
    vectorik.delete_idx(1);
    BOOST_CHECK_EQUAL(vectorik.vec[1], "3");
    vectorik.exchange("ex", 1);
    BOOST_CHECK_EQUAL(vectorik.vec[1], "ex");
    BOOST_CHECK_EQUAL(vectorik.get(1), "ex");

}

BOOST_AUTO_TEST_CASE(test_getsize_print) {
    Vector vectorik;
    vectorik.push_back("0");
    vectorik.push_back("1");
    vectorik.push_back("2");
    vectorik.push_back("3");
    BOOST_CHECK_EQUAL(to_string(vectorik.get_size()), "4");
    string file = "array.data";
    string namestruct = "@myarray";
    vectorik.print(file, namestruct);
    ifstream in(file);
    string line;
    getline(in, line);
    BOOST_CHECK_EQUAL(line, namestruct);
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "0");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "1");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "2");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "3");
    in.close();
    remove(file.c_str());
}