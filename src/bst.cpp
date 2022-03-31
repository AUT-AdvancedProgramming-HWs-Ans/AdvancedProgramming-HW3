/**
 * @file bst.cpp
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.0.5
 * @date 2022-04-01
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
     * @brief Overloaded operator <=> for Node
     *
     * @param node Node to compare
     * @return std::partial_ordering
     */

    return value <=> node.value;
}

bool Node::operator==(const Node& node) const
{
    /**
     * @brief Overloaded operator == with Node
     *
     * @param node Node to compare
     * @return true if equal
     * @return false if not equal
     */

    return value == node.value;
}

std::partial_ordering Node::operator<=>(int _value) const
{
    /**
     * @brief Overloaded operator <=> with int
     *
     * @param _value Value to compare
     * @return std::partial_ordering
     */

    return value <=> _value;
}

bool Node::operator==(int _value) const
{
    /**
     * @brief Overloaded operator == with int
     *
     * @param _value Value to compare
     * @return true if equal
     * @return false if not equal
     */

    return value == _value;
}

Node*& BST::get_root() const
{
    /**
     * @brief Getter for root
     *
     * @return Node*&
     */

    return const_cast<Node*&>(root);
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
     * @return true Node added successfully
     * @return false Node not added
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
Node** BST::find_node(int _value) const
{
    /**
     * @brief Find a node in the tree
     *
     * @param _value Value of the node
     * @return Node** Pointer to the node if found else nullptr
     */

    Node** node { const_cast<Node**>(&root) };
    // node: copy of refrence of root

    while (true) {
        if ((*node) == nullptr) {
            // if node is nullptr, return nullptr
            return nullptr;
        }

        if (_value < (*node)->value) {
            // if value is less than the node, go left
            node = &((*node)->left);

        } else if (_value > (*node)->value) {
            // if value is greater than the node, go right
            node = &((*node)->right);

        } else {
            return node;
        }
    }

    return nullptr;
}

Node** BST::find_parrent(int _value) const
{
    /**
     * @brief Find the parrent of a node
     *
     * @param _value Value of the node
     * @return Node** or nullptr
     */

    Node** node { const_cast<Node**>(&root) };
    Node** parrent { nullptr };
    // node: copy of refrence of root

    while (true) {
        if ((*node) == nullptr) {
            // if node is nullptr, return nullptr
            return nullptr;
        }

        if (_value < (*node)->value) {
            // if value is less than the node, go left
            parrent = node;
            node = &((*node)->left);

        } else if (_value > (*node)->value) {
            // if value is greater than the node, go right
            parrent = node;
            node = &((*node)->right);

        } else {
            return parrent;
        }
    }

    return nullptr;
}

Node** BST::find_successor(int _value) const
{
    /**
     * @brief Find the successor of a node
     *
     * @param _value Value of the node
     * @return Node** or nullptr
     */

    Node** node { find_node(_value) };

    if (node == nullptr)
        return nullptr;

    if ((*node)->left != nullptr) {
        // if node has a left child, return the rightmost child of the left child
        node = &((*node)->left);

        while ((*node)->right != nullptr)
            node = &((*node)->right);

        return node;

    } else {
        return node;
    }

    return nullptr;
}

bool BST::delete_node(int _value)
{
    /**
     * @brief Delete a node from the tree
     *
     * @param _value Value of the node
     * @return true Node deleted successfully
     * @return false Node not deleted
     */

    Node** node { find_node(_value) };

    if (node == nullptr)
        return false;

    if ((*node)->left == nullptr && (*node)->right == nullptr) {
        // if the node has no children, delete it
        delete (*node);
        (*node) = nullptr;

        return true;

    } else if ((*node)->left == nullptr) {
        // if the node has no left child, replace it with its right child
        Node* rightChildOfnode { (*node)->right };
        delete (*node);
        (*node) = rightChildOfnode;

        return true;

    } else if ((*node)->right == nullptr) {
        // if the node has no right child, replace it with its left child
        Node* leftChildOfnode { (*node)->left };
        delete (*node);
        (*node) = leftChildOfnode;

        return true;

    } else {
        // if the node has both children, replace it with its successor
        Node** successor { find_successor(_value) };
        (*node)->value = (*successor)->value;

        delete (*successor);
        (*successor) = nullptr;

        return true;
    }

    return false;
}