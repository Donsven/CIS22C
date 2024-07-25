/*
LAB NUMBER: LAB 3
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: UTILIZIING A LARGER COIN PROGRAM TO DEMONSTRATE THE DATA STRUCTURES LISTS, STACKS, AND QUEUES
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkNode.h"
#include <iostream>
#include <sstream>

class DoublyLinkedList {
private:
    int count;      // Number of nodes in the list
    LinkNode* head; // Pointer to the first node
    LinkNode* tail; // Pointer to the last node

public:
    // Constructor initializes an empty list
    DoublyLinkedList() : count(0), head(nullptr), tail(nullptr) {}

    // Destructor deletes all nodes to free memory
    ~DoublyLinkedList() {
        while (head != nullptr) {
            LinkNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Adds a currency node at a specific index
    void addCurrency(Currency* currency, int index) {
        if (index < 0 || index > count) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }

        LinkNode* newNode = new LinkNode(currency);
        if (index == 0) { // Adding at the head
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        } else if (index == count) { // Adding at the tail
            newNode->prev = tail;
            if (tail != nullptr) {
                tail->next = newNode;
            }
            tail = newNode;
        } else { // Adding in the middle
            LinkNode* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        ++count;
    }

    // Removes a node containing the specified currency
    Currency* removeCurrency(Currency* currency) {
        LinkNode* current = head;
        while (current != nullptr) {
            if (current->data->isEqual(*currency)) {
                if (current == head) { // Removing the head
                    head = head->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (current == tail) { // Removing the tail
                    tail = tail->prev;
                    if (tail != nullptr) {
                        tail->next = nullptr;
                    }
                } else { // Removing from the middle
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                Currency* removedData = current->data;
                delete current;
                --count;
                return removedData;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Removes a node at a specific index
    Currency* removeCurrency(int index) {
        if (index < 0 || index >= count) {
            std::cerr << "Index out of bounds" << std::endl;
            return nullptr;
        }

        LinkNode* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        if (current == head) { // Removing the head
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else if (current == tail) { // Removing the tail
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else { // Removing from the middle
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        Currency* removedData = current->data;
        delete current;
        --count;
        return removedData;
    }

    // Finds the index of a node containing the specified currency
    int findCurrency(Currency* currency) const {
        LinkNode* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data->isEqual(*currency)) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1; // Not found
    }

    // Returns the currency at a specific index
    Currency* getCurrency(int index) const {
        if (index < 0 || index >= count) {
            std::cerr << "Index out of bounds" << std::endl;
            return nullptr;
        }

        LinkNode* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Returns a string representation of the list
    std::string printList() const {
        std::ostringstream oss;
        LinkNode* current = head;
        while (current != nullptr) {
            oss << current->data->toString();
            current = current->next;
            if (current != nullptr) {
                oss << "\t";
            }
        }
        return oss.str();
    }

    // Returns the number of nodes in the list
    int getCount() const {
        return count;
    }

    // Returns the head node of the list
    LinkNode* getHead() const {
        return head;
    }

    // Returns the tail node of the list
    LinkNode* getTail() const {
        return tail;
    }
};

#endif // DOUBLYLINKEDLIST_H
