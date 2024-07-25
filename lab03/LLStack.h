#ifndef LLSTACK_H
#define LLSTACK_H

#include "DoublyLinkedList.h"

class LLStack : public DoublyLinkedList {
public:
    // Constructor
    LLStack() : DoublyLinkedList() {}

    // Adds a currency to the top of the stack
    void push(Currency* currency) {
        addCurrency(currency, 0);
    }

    // Removes and returns the currency from the top of the stack
    Currency* pop() {
        return removeCurrency(0);
    }

    // Returns the currency at the top of the stack without removing it
    Currency* peek() const {
        return getCurrency(0);
    }

    // Returns a string representation of the stack from top to bottom
    std::string toString() const {
        return printList();
    }
};

#endif // LLSTACK_H
