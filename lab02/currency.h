/*
LAB NUMBER: LAB 2
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: UTILIZIING A SMALL COIN PROGRAM TO DEMONSTRATE CLASSES, INHERITANCE, AND POLYMORPHISM IN CODE
*/

#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>           // Include the string library for using the string class
#include <stdexcept>        // Include the standard exception library for using exceptions
#include <sstream>          // Include the sstream library for using stringstream
#include <iomanip>          // Include the iomanip library for using setw and setfill
#include <cmath>            // Include cmath for rounding functions

class Currency {
protected:
    int wholePart; // Integer to store the whole part of the currency
    int fractionalPart; // Integer to store the fractional part of the currency

public:
    Currency(); // Default constructor
    Currency(double value); // Constructor with a double parameter
    Currency(const Currency& other); // Copy constructor

    virtual ~Currency(); // Virtual destructor

    void setWholePart(int whole); // Setter for wholePart
    void setFractionalPart(int fractional); // Setter for fractionalPart

    int getWholePart() const; // Getter for wholePart
    int getFractionalPart() const; // Getter for fractionalPart

    virtual std::string getName() const = 0; // Pure virtual function to get the currency name

    /*
    This function adds another Currency object to this one.
    Pre:    other -- The Currency object to add.
    Post: The value of this Currency object is increased by the value of the other Currency object.
    Return: 
    Throws: std::invalid_argument if the other Currency object is not of the same type.
    */
    void add(const Currency& other); // Method to add another Currency object

    /*
    This function Subtract another Currency object from this one.
    Pre:    other -- The Currency object to subtract.
    Post:   The value of this Currency object is decreased by the value of the other Currency object.
    Return: 
    Throws: std::invalid_argument if the other Currency object is not of the same type or is greater than this Currency object.
    */
    void subtract(const Currency& other); // Method to subtract another Currency object

    /*
    Check if another Currency object is of the same type.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if the other Currency object is of the same type, false otherwise.
    Throws: 
    */
    bool isSameType(const Currency& other) const; // Method to check if another Currency object is of the same type

    /*
    Check if another Currency object is equal to this one.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if the other Currency object is equal to this one, false otherwise.
    Throws: 
    */
    bool isEqual(const Currency& other) const; // Method to check if another Currency object is equal

    /*
    Check if this Currency object is greater than another one.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if this Currency object is greater than the other, false otherwise.
    Throws: 
    */
    bool isGreater(const Currency& other) const; // Method to check if another Currency object is greater

    /*
    Convert the Currency object to a string representation.
    Pre: 
    Post:   
    Return: A string representation of the Currency object in the format "whole.fractional CurrencyName".
    Throws: 
    */
    std::string toString() const; // Method to convert the Currency object to a string
};

// Implementations

Currency::Currency() : wholePart(0), fractionalPart(0) {} // Default constructor initializing members to 0

Currency::Currency(double value) {
    if (value < 0) throw std::invalid_argument("Negative value not allowed."); // Throw exception for negative value
    wholePart = static_cast<int>(value); // Assign whole part
    fractionalPart = static_cast<int>(round((value - wholePart) * 100)); // Assign fractional part with proper rounding
}

Currency::Currency(const Currency& other) : wholePart(other.wholePart), fractionalPart(other.fractionalPart) {} // Copy constructor

Currency::~Currency() {} // Destructor

void Currency::setWholePart(int whole) {
    if (whole < 0) throw std::invalid_argument("Negative value not allowed."); // Throw exception for negative value
    wholePart = whole; // Set whole part
}

void Currency::setFractionalPart(int fractional) {
    if (fractional < 0 || fractional >= 100) throw std::invalid_argument("Invalid fractional part."); // Throw exception for invalid fractional part
    fractionalPart = fractional; // Set fractional part
}

int Currency::getWholePart() const {
    return wholePart; // Return whole part
}

int Currency::getFractionalPart() const {
    return fractionalPart; // Return fractional part
}

void Currency::add(const Currency& other) {
    if (!isSameType(other)) throw std::invalid_argument("Invalid addition"); // Check for same type
    wholePart += other.wholePart; // Add whole parts
    fractionalPart += other.fractionalPart; // Add fractional parts
    if (fractionalPart >= 100) { // Handle overflow in fractional part
        wholePart++;
        fractionalPart -= 100;
    }
}

void Currency::subtract(const Currency& other) {
    if (!isSameType(other)) throw std::invalid_argument("Invalid subtraction"); // Check for same type
    if (isGreater(other) || isEqual(other)) { // Ensure no negative result
        wholePart -= other.wholePart; // Subtract whole parts
        fractionalPart -= other.fractionalPart; // Subtract fractional parts
        if (fractionalPart < 0) { // Handle underflow in fractional part
            wholePart--;
            fractionalPart += 100;
        }
    } else {
        throw std::invalid_argument("Invalid subtraction"); // Throw exception for invalid subtraction
    }
}

bool Currency::isSameType(const Currency& other) const {
    return getName() == other.getName(); // Check if currency types are the same
}

bool Currency::isEqual(const Currency& other) const {
    return wholePart == other.wholePart && fractionalPart == other.fractionalPart; // Check if values are equal
}

bool Currency::isGreater(const Currency& other) const {
    if (wholePart > other.wholePart) return true; // Compare whole parts
    if (wholePart == other.wholePart && fractionalPart > other.fractionalPart) return true; // Compare fractional parts
    return false; // Return false otherwise
}

std::string Currency::toString() const {
    std::ostringstream oss; // Create a stringstream object
    oss << wholePart << "." << std::setw(2) << std::setfill('0') << fractionalPart << " " << getName(); // Format the string
    return oss.str(); // Return the formatted string
}

#endif // CURRENCY_H
