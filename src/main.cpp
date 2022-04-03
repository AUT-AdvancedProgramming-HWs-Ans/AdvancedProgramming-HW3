/**
 * @file main.cpp
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.1.2
 * @date 2022-04-04
 *
 * @copyright Copyright (c) 2022
 *
 */

// Importing the libraries
#include "bst.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        // Initializing the testing framework
        /////////////////////////////////
        // BST bst { 20, 10, 25, 5, 15, 4, 6, 13, 11, 14, 12 };

        // std::cout << "BST: " << bst << std::endl;

        // bst.delete_node(20);

        // std::cout << "BST: " << bst << std::endl;

        ////////////////////////////////
        // BST bst {};
        // bst.add_node(-5);
        // bst.add_node(-6);
        // bst.add_node(10);
        // bst.add_node(11);
        // bst.add_node(-17);

        // std::cout << bst << std::endl;
        // bst = std::move(bst);
        // std::cout << bst << std::endl;

        // std::cout << **(bst.find_node(10)) << std::endl;

        // BST bst {};
        // bst.add_node(5);
        // bst.add_node(10);
        // bst.add_node(50);

        // std::cout << bst << std::endl;

        // int test_value { bst.get_root()->right->value };
        // BST::Node* adddress_of_root { *bst.find_node(5) };

        // BST move { std::move(bst) };
        // std::cout << bst << std::endl;
        // std::cout << move << std::endl;

        // BST::Node node{};
        // std::cout<<node.value<<std::endl;

        // BST bst {};
        // bst.add_node(5);

        // bst.add_node(3);

        // bst.find_node(5);
        // std::cout << bst << std::endl;
        // // BST bst1 {};
        // // bst1.add_node(*(bst.find_node(5)));

        // bst.find_node(5);
        // std::cout << bst << std::endl;

        // bst.delete_node(5);

        // std::cout << bst << std::endl;

        // int** a{};

        // a= nullptr;

        // if((*a)==nullptr)
        // {
        //     std::cout << "a is nullptr" << std::endl;
        // }
        // else
        // {
        //     std::cout << "a is not nullptr" << std::endl;
        // }

        // BST bst {};

        // bst.find_node(1) == nullptr ? std::cout << "find_node(1) is nullptr"
        //                                         << std::endl
        //                             : std::cout
        //         << "find_node(1) is not nullptr" << std::endl;
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

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}