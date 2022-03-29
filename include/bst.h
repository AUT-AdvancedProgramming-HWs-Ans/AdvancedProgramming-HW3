/**
 * @file bst.h
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BST_H
#define BST_H

// Importing the libraries
#include <functional>
#include <iostream>

class Node {
public:
    Node(int _value, Node* _left, Node* _right);
    Node() = default;
    Node(const Node& node);

    int value;
    Node* left;
    Node* right;
};

class BST : public Node {
public:
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

private:
    Node* root;
};

#endif // BST_H