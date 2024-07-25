// Changes made in this file:
// 1. Inherited from the updated Currency class to include normalization logic and correct formatting.
// 2. Added inline keyword to methods for potential performance optimization.

#ifndef DOLLAR_H
#define DOLLAR_H

#include "Currency.h"

class Dollar : public Currency {
public:
    // Default constructor
    Dollar() : Currency() {}

    // Constructor to initialize with a double amount
    Dollar(double amount) : Currency(amount) {}

    // Copy constructor
    Dollar(const Dollar& other) : Currency(other) {}

    // Destructor
    virtual ~Dollar() {}

    // Get the name of the currency
    inline std::string getName() const { return "Dollar"; }
};

#endif // DOLLAR_H
