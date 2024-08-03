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

    // Method to compare Dollar objects for sorting in the BST
    bool isGreater(const Dollar& other) const {
        return this->getWholePart() > other.getWholePart() ||
               (this->getWholePart() == other.getWholePart() && this->getFractionalPart() > other.getFractionalPart());
    }

    // Method to check equality of Dollar objects
    bool isEqual(const Dollar& other) const {
        return this->getWholePart() == other.getWholePart() && this->getFractionalPart() == other.getFractionalPart();
    }
};

#endif // DOLLAR_H
