/**
 * @file bst.cpp
 * @author Erfan Rasti (erfanrasty@gmail.com)
 * @brief
 * @version 1.0.2
 * @date 2022-03-30
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