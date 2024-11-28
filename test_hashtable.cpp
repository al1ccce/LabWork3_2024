#define BOOST_TEST_MODULE HashTableTest
#include <boost/test/included/unit_test.hpp>
#include "hash.h"

BOOST_AUTO_TEST_CASE(test_insert_find) {
    HashTable ht(5);
    ht.insert("k1", "v1");
    ht.insert("blabla", "v2");
    ht.insert("bleble", "v3");
    ht.insert("qwezxc", "v2");
    ht.insert("cplusplus", "v3");

    BOOST_CHECK_EQUAL(ht.find("k1"), "v1");
    BOOST_CHECK_EQUAL(ht.find("blabla"), "v2");
    BOOST_CHECK_EQUAL(ht.find("bleble"), "v3");
    BOOST_CHECK_EQUAL(ht.find("k4"), ""); 
}

BOOST_AUTO_TEST_CASE(test_remove) {
    HashTable ht(5);

    ht.insert("k1", "v1");
    ht.insert("k2", "v2");
    ht.insert("k3", "v3");

    BOOST_CHECK(ht.remove("k1"));
    BOOST_CHECK_EQUAL(ht.find("k1"), ""); 
    BOOST_CHECK_EQUAL(ht.find("k2"), "v2");
    BOOST_CHECK_EQUAL(ht.find("k3"), "v3");
    BOOST_CHECK(!ht.remove("k4"));

}

BOOST_AUTO_TEST_CASE(test_print) {
    HashTable ht(5);

    // Вставка элементов
    ht.insert("k1", "v1");
    ht.insert("k2", "v2");
    ht.insert("k3", "v3");

    string file = "hash.data";
    string namestruct = "@ht";

    // Вывод в файл
    ht.print(file, namestruct);

    // Проверка содержимого файла
    ifstream in(file);
    string line;
    getline(in, line);
    BOOST_CHECK_EQUAL(line, namestruct);
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "k1 v1");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "k2 v2");
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "k3 v3");
    in.close();

    // Удаление файла
    remove(file.c_str());
}
