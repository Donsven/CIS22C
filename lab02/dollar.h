// Name Block
// Lab Number: 2
// Name: Yijiang Ma & N  fill your name pls!!!
// Purpose: Define the derived class Dollar

#ifndef DOLLAR_H
#define DOLLAR_H

#include "currency.h" // Include the header file for the base class Currency

class Dollar : public Currency {
private:
    std::string name; // String to store the name of the currency

public:
    Dollar(); // Default constructor
    Dollar(double value); // Constructor with a double parameter
    Dollar(const Dollar& other); // Copy constructor

    ~Dollar(); // Destructor

    std::string getName() const override; // Override the pure virtual function to get the currency name
};

// Implementations

Dollar::Dollar() : Currency(), name("Dollar") {} // Default constructor initializing name

Dollar::Dollar(double value) : Currency(value), name("Dollar") {} // Constructor with a double parameter initializing name

Dollar::Dollar(const Dollar& other) : Currency(other), name("Dollar") {} // Copy constructor

Dollar::~Dollar() {} // Destructor

std::string Dollar::getName() const {
    return name; // Return the name of the currency
}

#endif // DOLLAR_H
