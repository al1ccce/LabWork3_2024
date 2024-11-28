#define BOOST_TEST_MODULE FullBinaryTreeTest
#include <boost/test/included/unit_test.hpp>
#include "tree.h"

BOOST_AUTO_TEST_CASE(test_insert_search) {
    FullBinaryTree tree;

    tree.insert(tree.root, 5);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 4);

    BOOST_CHECK(tree.search(5) != nullptr);
    BOOST_CHECK(tree.search(1) == nullptr);
}

BOOST_AUTO_TEST_CASE(test_is_full) {
    FullBinaryTree tree;

    tree.insert(tree.root, 5);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 8);
    BOOST_CHECK(tree.isFull());

    tree.insert(tree.root, 1);
    BOOST_CHECK(!tree.isFull());
}

BOOST_AUTO_TEST_CASE(test_print) {
    FullBinaryTree tree;

    tree.insert(tree.root, 5);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 4);

    string file = "tree.data";
    string namestruct = "@mytree";

    // Вывод в файл
    tree.print(file, namestruct);
    ifstream in(file);
    string line;
    getline(in, line);
    BOOST_CHECK_EQUAL(line, namestruct);
    getline(in, line);
    BOOST_CHECK_EQUAL(line, "5 3 7 4 ");
    in.close();
}
