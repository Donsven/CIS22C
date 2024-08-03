/*
LAB NUMBER: LAB 4
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: DECLARE AND CREATE A BINARY SEARCH TREE, IMPLEMENTING THE FOUR TRAVERSAL METHODS AND MORE
*/

#ifndef DOLLAR_H
#define DOLLAR_H

#include "Currency.h"

class Dollar : public Currency {
public:
    // Default constructor
    Dollar() : Currency() {}

    // Constructor to initialize with a double value
    Dollar(double amount) : Currency(amount) {}

    // Copy constructor
    Dollar(const Dollar& other) : Currency(other) {}

    // Destructor
    virtual ~Dollar() {}

    // Returns the name of the currency as "Dollar"
    std::string getName() const {
        return "Dollar";
    }

    /*
    Method to compare Dollar objects for sorting in the BST.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if this Currency object is greater than the other, false otherwise.
    Throws: 
    */
    bool isGreater(const Dollar& other) const {
        return this->getWholePart() > other.getWholePart() ||
               (this->getWholePart() == other.getWholePart() && this->getFractionalPart() > other.getFractionalPart());
    }

    /*
    Method to check equality of Dollar objects.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if the other Currency object is equal to this one, false otherwise.
    Throws: 
    */
    bool isEqual(const Dollar& other) const {
        return this->getWholePart() == other.getWholePart() && this->getFractionalPart() == other.getFractionalPart();
    }
};

#endif // DOLLAR_H
