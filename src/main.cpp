/**
 * @file main.cpp
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.0.4
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Importing the libraries
#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
    // BST bst1{};
    // bst1.add_node(10);
    // bst1.add_node(20);
    // bst1.add_node(5);

    // BST *bst2{&bst1};


    // std::cout << bst1.get_root()->left->value << std::endl;
    // std::cout << bst1.get_root()->right->value << std::endl;
    // std::cout << (*bst2).get_root()->left->value << std::endl;
    // std::cout << (*bst2).get_root()->right->value << std::endl;

    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}