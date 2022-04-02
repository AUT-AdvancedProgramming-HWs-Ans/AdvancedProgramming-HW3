/**
 * @file bst.h
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.1.1
 * @date 2022-04-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BST_H
#define BST_H

// Importing the libraries
#include <compare>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>

class BST {
public:
    class Node {
    public:
        Node();
        Node(int _value, Node* _left, Node* _right);
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

    BST();
    BST(const BST& bst);
    BST(BST&& bst);
    BST(std::initializer_list<int> list);

    ~BST();

    Node*& get_root() const;
    void bfs(std::function<void(Node*& node)> func) const;
    size_t length() const;
    bool add_node(int _value);
    Node** find_node(int _value) const;
    Node** find_parrent(int _value) const;
    Node** find_successor(int _value) const;
    bool delete_node(int _value) const;

    const BST& operator++() const;
    const BST operator++(int) const;

    BST& operator=(const BST& bst);
    BST& operator=(BST&& bst);

    friend std::ostream& operator<<(std::ostream& stream, const BST& bst);

private:
    Node* root;
};

#endif // BST_H