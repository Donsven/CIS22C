/*
LAB NUMBER: LAB 3
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: UTILIZIING A LARGER COIN PROGRAM TO DEMONSTRATE THE DATA STRUCTURES LISTS, STACKS, AND QUEUES
*/

#ifndef LINKNODE_H
#define LINKNODE_H

#include "Currency.h"

class LinkNode {
public:
    Currency* data;    // Pointer to the currency data
    LinkNode* next;    // Pointer to the next node
    LinkNode* prev;    // Pointer to the previous node

    // Constructor to initialize the node with currency data
    LinkNode(Currency* currency) : data(currency), next(nullptr), prev(nullptr) {}
};

#endif // LINKNODE_H
