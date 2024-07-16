// Name Block
// Lab Number: 2
// Name: Yijiang Ma & N  fill your name pls!!!
// Purpose: Define the derived class Pound

#ifndef POUND_H
#define POUND_H

#include "currency.h" // Include the header file for the base class Currency

class Pound : public Currency {
private:
    std::string name; // String to store the name of the currency

public:
    Pound(); // Default constructor
    Pound(double value); // Constructor with a double parameter
    Pound(const Pound& other); // Copy constructor

    ~Pound(); // Destructor

    std::string getName() const override; // Override the pure virtual function to get the currency name
};

// Implementations

Pound::Pound() : Currency(), name("Pound") {} // Default constructor initializing name

Pound::Pound(double value) : Currency(value), name("Pound") {} // Constructor with a double parameter initializing name

Pound::Pound(const Pound& other) : Currency(other), name("Pound") {} // Copy constructor

Pound::~Pound() {} // Destructor

std::string Pound::getName() const {
    return name; // Return the name of the currency
}

#endif // POUND_H
