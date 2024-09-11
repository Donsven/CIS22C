/*
LAB NUMBER: LAB 4
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: DECLARE AND CREATE A BINARY SEARCH TREE, IMPLEMENTING THE FOUR TRAVERSAL METHODS AND MORE
*/


#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

class BST {
private:
    BSTNode* root;

    /*
    Inserts a new node with the given Dollar object into the Binary Search Tree.
    Pre:    node -- the root node of the BST or subtree
            dollar -- the Dollar object to be inserted
    Post:   
    Return: a pointer to the root node of the BST after the insertion
    Throws: 
*/
    BSTNode* insert(BSTNode* node, const Dollar& dollar) {
        if (node == nullptr) {
            return new BSTNode(dollar);
        }
        if (dollar.isGreater(node->getData())) {
            node->setRight(insert(node->getRight(), dollar));
        } else if (!dollar.isEqual(node->getData())) {
            node->setLeft(insert(node->getLeft(), dollar));
        }
        return node;
    }

    /*
    Performs in-order traversal of the BST and outputs the node data to the provided output stream.
    Pre:    node -- the root node of the BST or subtree
            os -- the output stream to which the node data is written
    Post:   
    Return: 
    Throws: 
    */
    void inOrderTraversal(BSTNode* node, std::ostream& os) const {
        if (node == nullptr) return;
        inOrderTraversal(node->getLeft(), os);
        os << node->getData().toString() << "\t";
        inOrderTraversal(node->getRight(), os);
    }

    /*
    Performs pre-order traversal of the BST and outputs the node data to the provided output stream.
    Pre:    node -- the root node of the BST or subtree
            os -- the output stream to which the node data is written
    Post:   
    Return: 
    Throws: 
    */
    void preOrderTraversal(BSTNode* node, std::ostream& os) const {
        if (node == nullptr) return;
        os << node->getData().toString() << "\t";
        preOrderTraversal(node->getLeft(), os);
        preOrderTraversal(node->getRight(), os);
    }

    /*
    Performs post-order traversal of the BST and outputs the node data to the provided output stream.
    Pre:    node -- the root node of the BST or subtree
            os -- the output stream to which the node data is written
    Post:   
    Return: 
    Throws: 
    */
    void postOrderTraversal(BSTNode* node, std::ostream& os) const {
        if (node == nullptr) return;
        postOrderTraversal(node->getLeft(), os);
        postOrderTraversal(node->getRight(), os);
        os << node->getData().toString() << "\t";
    }

    /*
    Finds the node with the minimum value in the BST.
    Pre:    node -- the root node of the BST or subtree
    Post:   
    Return: a pointer to the node with the minimum value in the BST
    Throws: 
    */
    BSTNode* minValueNode(BSTNode* node) {
        BSTNode* current = node;
        while (current && current->getLeft() != nullptr) {
            current = current->getLeft();
        }
        return current;
    }

    /*
    Deletes a node with the given Dollar object from the BST.
    Pre:    root -- the root node of the BST or subtree
            dollar -- the Dollar object to be deleted
    Post:   
    Return: a pointer to the root node of the BST after the deletion
    Throws: 
    */
    BSTNode* deleteNode(BSTNode* root, const Dollar& dollar) {
        if (root == nullptr) return root;

        if (dollar.isGreater(root->getData())) {
            root->setRight(deleteNode(root->getRight(), dollar));
        } else if (root->getData().isGreater(dollar)) {
            root->setLeft(deleteNode(root->getLeft(), dollar));
        } else {
            if (root->getLeft() == nullptr) {
                BSTNode* temp = root->getRight();
                delete root;
                return temp;
            } else if (root->getRight() == nullptr) {
                BSTNode* temp = root->getLeft();
                delete root;
                return temp;
            }

            BSTNode* temp = minValueNode(root->getRight());
            root->setData(temp->getData());
            root->setRight(deleteNode(root->getRight(), temp->getData()));
        }
        return root;
    }

    /*
    Performs breadth-first traversal of the BST and outputs the node data to the provided output stream.
    Pre:    node -- the root node of the BST or subtree
            os -- the output stream to which the node data is written
    Post:   
    Return: 
    Throws: 
    */
    void breadthFirstTraversal(BSTNode* node, std::ostream& os) const {
        if (node == nullptr) return;

        std::queue<BSTNode*> queue;
        queue.push(node);

        while (!queue.empty()) {
            BSTNode* current = queue.front();
            queue.pop();
            os << current->getData().toString() << "\t";

            if (current->getLeft() != nullptr) queue.push(current->getLeft());
            if (current->getRight() != nullptr) queue.push(current->getRight());
        }
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Method to insert a dollar into the BST
    void insert(const Dollar& dollar) {
        root = insert(root, dollar);
    }

    // Method to delete a dollar from the BST
    void deleteDollar(const Dollar& dollar) {
        root = deleteNode(root, dollar);
    }

    // Method to perform in-order traversal
    void inOrderTraversal(std::ostream& os) const {
        inOrderTraversal(root, os);
        os << std::endl;
    }

    // Method to perform pre-order traversal
    void preOrderTraversal(std::ostream& os) const {
        preOrderTraversal(root, os);
        os << std::endl;
    }

    // Method to perform post-order traversal
    void postOrderTraversal(std::ostream& os) const {
        postOrderTraversal(root, os);
        os << std::endl;
    }

    // Method to perform breadth-first traversal
    void breadthFirstTraversal(std::ostream& os) const {
        breadthFirstTraversal(root, os);
        os << std::endl;
    }

    // Method to check if the tree is empty
    bool isEmpty() const {
        return root == nullptr;
    }

    // Method to clear the tree
    void clear() {
        while (!isEmpty()) {
            deleteDollar(root->getData());
        }
    }
};

#endif // BST_H
