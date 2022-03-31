/**
 * @file bst.h
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.0.3
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BST_H
#define BST_H

// Importing the libraries
#include <compare>
#include <functional>
#include <iostream>
#include <queue>

class Node {
public:
    Node(int _value, Node* _left, Node* _right);
    Node() = default;
    Node(const Node& node);

    friend std::ostream& operator<<(std::ostream& stream, const Node& node);

    std::partial_ordering operator<=>(const Node& node) const;
    bool operator==(const Node& node) const;

    std::partial_ordering operator<=>(int _value) const;
    bool operator==(int _value) const;

    int value;
    Node* left;
    Node* right;
};

class BST : public Node {
public:
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func) const;
    size_t length() const;
    bool add_node(int _value);
    Node** find_node(int _value) const;
    Node** find_parrent(int _value);
    Node** find_successor(int _value);
    bool delete_node(int _value);

    // BST& operator=(const BST& bst) = default;

private:
    Node* root;
};

#endif // BST_H