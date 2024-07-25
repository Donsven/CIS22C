/*
LAB NUMBER: LAB 3
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: UTILIZIING A LARGER COIN PROGRAM TO DEMONSTRATE THE DATA STRUCTURES LISTS, STACKS, AND QUEUES
*/

#ifndef LLQUEUE_H
#define LLQUEUE_H

#include "DoublyLinkedList.h"

class LLQueue : public DoublyLinkedList {
public:
    // Constructor
    LLQueue() : DoublyLinkedList() {}

    // Adds a currency to the end of the queue
    void enqueue(Currency* currency) {
        addCurrency(currency, getCount());
    }

    // Removes and returns the currency from the front of the queue
    Currency* dequeue() {
        return removeCurrency(0);
    }

    // Returns the currency at the front of the queue without removing it
    Currency* peekFront() const {
        return getCurrency(0);
    }

    // Returns the currency at the end of the queue without removing it
    Currency* peekRear() const {
        return getCurrency(getCount() - 1);
    }

    // Returns a string representation of the queue from front to end
    std::string toString() const {
        return printList();
    }
};

#endif // LLQUEUE_H
