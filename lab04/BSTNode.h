/*
LAB NUMBER: LAB 4
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: DECLARE AND CREATE A BINARY SEARCH TREE, IMPLEMENTING THE FOUR TRAVERSAL METHODS AND MORE
*/

#ifndef BSTNODE_H
#define BSTNODE_H

#include "Dollar.h"

class BSTNode {
private:
    Dollar data;       // Data held by the node
    BSTNode* left;     // Pointer to the left child node
    BSTNode* right;    // Pointer to the right child node

public:
    // Constructor to initialize the node with a Dollar object
    BSTNode(const Dollar& dollar) : data(dollar), left(nullptr), right(nullptr) {}

    // Getter for the data attribute
    Dollar getData() const { return data; }

    // Setter for the data attribute
    void setData(const Dollar& dollar) { data = dollar; }

    // Getter for the left child pointer
    BSTNode* getLeft() const { return left; }

    // Setter for the left child pointer
    void setLeft(BSTNode* node) { left = node; }

    // Getter for the right child pointer
    BSTNode* getRight() const { return right; }

    // Setter for the right child pointer
    void setRight(BSTNode* node) { right = node; }
};

#endif // BSTNODE_H
