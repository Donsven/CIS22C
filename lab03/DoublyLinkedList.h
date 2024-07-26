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

    /*
    Destructor deletes all nodes to free memory
    Pre:  DoublyLinkedList exists
    Post: All nodes in the list are deleted, freeing memory
    Return: None
    Throws: None
    */
    ~DoublyLinkedList() {
        while (head != nullptr) {
            LinkNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /*
    Adds a currency node at a specific index
    Pre:  currency - pointer to Currency object
          index - int value
    Post: A new node containing the currency is added at the specified index
    Return: None
    Throws: Prints "Index out of bounds" if index is out of range
    */
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

    /*
    Removes a node containing the specified currency
    Pre:  currency - pointer to Currency object
    Post: If a node containing the currency is found, removed from list and currency is returned
    Return: Pointer to the removed Currency object, nullptr if not found
    Throws: None
    */
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

    /*
    Removes a node at a specific index
    Pre:  index - int value that needs to be between 0 and count - 1
    Post: If a node at the specified index is found, removed from list and currency is returned
    Return: Pointer to the removed Currency object, nullptr if index is out of range
    Throws: Prints "Index out of bounds" if index is out of range
    */
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

    /*
    Finds the index of a node containing the specified currency
    Pre:  currency - pointer to Currency object
    Post: None
    Return: Index of node containing the currency, or -1 if not found
    Throws: None
    */    
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

    /*
    Finds the index of a node containing the specified currency
    Pre:  currency - pointer to Currency object    
    Post: None
    Return: Index of node containing the currency, or -1 if not found
    Throws: None
    */
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

    /*
    // Returns a string representation of the list
    Pre:  None
    Post: None
    Return: A string representation of the list
    Throws: None
    */
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
