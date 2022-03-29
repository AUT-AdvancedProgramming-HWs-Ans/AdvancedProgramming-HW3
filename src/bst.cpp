/**
 * @file bst.cpp
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.0.1
 * @date 2022-03-29
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
