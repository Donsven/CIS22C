/*
LAB NUMBER: LAB 5
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: USE INPUT SEED DATA TO CREATE A SEARCHABLE HASH TABLE
*/

#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

class Currency {
private:
    int whole;
    int fractional;

    // Normalizes the currency values to ensure fractional part is within 0-99
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

    // Constructor to initialize with a double value
    // Normalizes the fractional part
    Currency(double amount) {
        whole = static_cast<int>(amount);
        fractional = static_cast<int>(round((amount - whole) * 100));
        normalize();
    }

    // Copy constructor
    Currency(const Currency& other) : whole(other.whole), fractional(other.fractional) {}

    // Destructor
    virtual ~Currency() {}

    // Setter for whole part
    void setWholePart(int wholePart) { whole = wholePart; }

    // Setter for fractional part, normalizes after setting
    void setFractionalPart(int fractionalPart) { fractional = fractionalPart; normalize(); }

    // Getter for whole part
    int getWholePart() const { return whole; }
    // Getter for fractional part
    int getFractionalPart() const { return fractional; }

    /*
    This function adds another Currency object to this one.
    Pre:    other -- The Currency object to add.
    Post: The value of this Currency object is increased by the value of the other Currency object.
    Return: 
    Throws: std::invalid_argument if the other Currency object is not of the same type.
    */
    void add(const Currency& other) {
        whole += other.whole;
        fractional += other.fractional;
        normalize();
    }

    /*
    Check if another Currency object is of the same type.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if the other Currency object is of the same type, false otherwise.
    Throws: 
    */
    bool isSameType(const Currency& other) const {
        return typeid(*this) == typeid(other);
    }

    /*
    This function Subtract another Currency object from this one.
    Pre:    other -- The Currency object to subtract.
    Post:   The value of this Currency object is decreased by the value of the other Currency object.
    Return: 
    Throws: std::invalid_argument if the other Currency object is not of the same type or is greater than this Currency object.
    */
    void subtract(const Currency& other) {
        whole -= other.whole;
        fractional -= other.fractional;
        normalize();
    }

    /*
    Check if this Currency object is greater than another one.
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if this Currency object is greater than the other, false otherwise.
    Throws: 
    */
    bool isGreater(const Currency& other) const {
        if (whole > other.whole) return true;
        if (whole == other.whole && fractional > other.fractional) return true;
        return false;
    }

    /*
    Check if another Currency object is equal
    Pre:    other -- The Currency object to compare.
    Post:   
    Return: True if the other Currency object is equal, false otherwise.
    Throws: 
    */
    bool isEqual(const Currency& other) const {
        return whole == other.whole && fractional == other.fractional;
    }

    /*
    Convert the Currency object to a string representation.
    Pre: 
    Post:   
    Return: A string representation of the Currency object in the format "whole.fractional CurrencyName".
    Throws: 
    */
    std::string toString() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << whole << '.' << std::setw(2) << std::setfill('0') << fractional;
        return oss.str();
    }
};

#endif // CURRENCY_H
