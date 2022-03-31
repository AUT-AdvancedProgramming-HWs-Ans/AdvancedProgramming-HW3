/**
 * @file bst.cpp
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.0.3
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022
 *
 */

// Adding header files
#include "bst.h"

Node::Node(int _value, Node* _left, Node* _right)
    : value(_value)
    , left(_left)
    , right(_right)
{
    /**
     * @brief Construct a new Node object
     *
     * @param _value Value of the node
     * @param _left Left child of the node
     * @param _right Right child of the node
     */
}

Node::Node(const Node& node)
    : value(node.value)
    , left(node.left)
    , right(node.right)
{
    /**
     * @brief Copy constructor
     *
     * @param node Node to copy
     */
}

std::ostream& operator<<(std::ostream& stream, const Node& node)
{
    /**
     * @brief Overloaded << operator
     *
     * @param stream Stream to print
     * @param node Node to print
     * @return std::ostream&
     */

    stream << "adress of node: " << &node << std::endl;
    stream << "value of node: " << node.value << std::endl;
    stream << "adress of left child: " << node.left << std::endl;
    stream << "adress of right child: " << node.right << std::endl;

    return stream;
}

std::partial_ordering Node::operator<=>(const Node& node) const
{
    /**
     * @brief Overloaded operator <=>
     *
     * @param node Node to compare
     * @return std::partial_ordering
     */

    return value <=> node.value;
}

bool Node::operator==(const Node& node) const
{
    /**
     * @brief Overloaded operator ==
     *
     * @param node Node to compare
     * @return true
     * @return false
     */

    return value == node.value;
}

std::partial_ordering Node::operator<=>(int _value) const
{
    /**
     * @brief Overloaded operator <=>
     *
     * @param _value Value to compare
     * @return std::partial_ordering
     */

    return value <=> _value;
}

bool Node::operator==(int _value) const
{
    /**
     * @brief Overloaded operator ==
     *
     * @param _value Value to compare
     * @return true
     * @return false
     */

    return value == _value;
}

Node*& BST::get_root()
{
    /**
     * @brief Getter for root
     *
     * @return Node*&
     */

    return root;
}

void BST::bfs(std::function<void(Node*& node)> func) const
{
    /**
     * @brief Breadth first search
     *
     * @param func Function to call on each node
     */

    std::queue<Node*> queue;
    // queue for storing nodes to apply func on

    queue.push(root);

    while (!queue.empty()) {

        Node* node { queue.front() };

        // Popping the front element
        queue.pop();

        func(node);

        // Adding child nodes to the queue

        if (node->left != nullptr)
            queue.push(node->left);

        if (node->right != nullptr)
            queue.push(node->right);
    }
}

size_t BST::length() const
{
    /**
     * @brief Get the length of the tree
     *
     * @return size_t
     */

    size_t length { 0 };

    BST::bfs([&length](Node*& node) {
        length++;
    });

    return length;
}

bool BST::add_node(int _value)
{
    /**
     * @brief Add a node to the tree
     *
     * @param _value Value of the node
     * @return true
     * @return false
     */

    Node** node { &root };
    // node: copy of refrence of root

    while (true) {
        if ((*node) == nullptr) {
            // if node is nullptr, add the node
            (*node) = new Node(_value, nullptr, nullptr);
            return true;
        }

        if (_value < (*node)->value) {
            // if value is less than the node, go left
            if ((*node)->left == nullptr) {
                (*node)->left = new Node(_value, nullptr, nullptr);
                return true;
            } else {
                node = &((*node)->left);
            }
        } else if (_value > (*node)->value) {
            // if value is greater than the node, go right
            if ((*node)->right == nullptr) {
                (*node)->right = new Node(_value, nullptr, nullptr);
                return true;
            } else {
                node = &((*node)->right);
            }
        } else {
            return false;
        }
    }

    return false;
}