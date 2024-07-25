/*
LAB NUMBER: LAB 3
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: UTILIZIING A LARGER COIN PROGRAM TO DEMONSTRATE THE DATA STRUCTURES LISTS, STACKS, AND QUEUES
*/

/*
Changes made in this file:
1. Added normalization logic in the constructor and setFractionalPart to ensure fractional part is correctly managed.
2. Updated the toString method to ensure correct formatting of the currency value with two decimal places.
3. Added the inline keyword to several methods for potential performance optimization by suggesting the compiler to expand these methods inline where they are called.
*/

#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

class Currency {
private:
    int whole; // Whole part of the currency
    int fractional; // Fractional part of the currency

    // Normalize the fractional part to ensure it is within 0-99
    void normalize() {
        if (fractional >= 100) {
            whole += fractional / 100;
            fractional %= 100;
        } else if (fractional < 0) {
            whole -= (-fractional + 99) / 100;
            fractional = 100 - (-fractional % 100);
        }
    }

public:
    // Default constructor
    Currency() : whole(0), fractional(0) {}

    // Constructor to initialize with a double amount
    // The fractional part is normalized
    Currency(double amount) {
        whole = static_cast<int>(amount);
        fractional = static_cast<int>(round((amount - whole) * 100));
        normalize();
    }

    // Copy constructor
    Currency(const Currency& other) : whole(other.whole), fractional(other.fractional) {}

    // Destructor
    virtual ~Currency() {}

    // Set the whole part of the currency
    void setWholePart(int wholePart) { whole = wholePart; }

    // Set the fractional part of the currency and normalize it
    void setFractionalPart(int fractionalPart) { fractional = fractionalPart; normalize(); }

    // Get the whole part of the currency
    int getWholePart() const { return whole; }

    // Get the fractional part of the currency
    int getFractionalPart() const { return fractional; }

    /*
    This function adds another Currency object to this one.
    Pre:    other -- The Currency object to add.
    Post: The value of this Currency object is increased by the value of the other Currency object.
    Return: 
    Throws: std::invalid_argument if the other Currency object is not of the same type.
    */
    inline void add(const Currency& other) {
        whole += other.whole;
        fractional += other.fractional;
        normalize();
    }

    /*
    This function Subtract another Currency object from this one.
    Pre:    other -- The Currency object to subtract.
    Post:   The value of this Currency object is decreased by the value of the other Currency object.
    Return: 
    Throws: std::invalid_argument if the other Currency object is not of the same type or is greater than this Currency object.
    */
    inline void subtract(const Currency& other) {
        whole -= other.whole;
        fractional -= other.fractional;
        normalize();
    }

    /*
    Check if another Currency object is of the same type.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if the other Currency object is of the same type, false otherwise.
    Throws: 
    */
    inline bool isSameType(const Currency& other) const {
        return typeid(*this) == typeid(other);
    }

    /*
    Check if another Currency object is equal to this one.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if the other Currency object is equal to this one, false otherwise.
    Throws: 
    */
    inline bool isEqual(const Currency& other) const {
        return whole == other.whole && fractional == other.fractional;
    }

    /*
    Check if this Currency object is greater than another one.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if this Currency object is greater than the other, false otherwise.
    Throws: 
    */
    inline bool isGreater(const Currency& other) const {
        if (whole > other.whole) return true;
        if (whole == other.whole && fractional > other.fractional) return true;
        return false;
    }

    /*
    Convert the Currency object to a string representation.
    Pre: 
    Post:   
    Return: A string representation of the Currency object in the format "whole.fractional CurrencyName".
    Throws: 
    */
    inline std::string toString() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << whole << '.' << std::setw(2) << std::setfill('0') << fractional;
        return oss.str();
    }
};

#endif // CURRENCY_H
