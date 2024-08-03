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

    // Adds another currency value to the current one, normalizes the result
    void add(const Currency& other) {
        whole += other.whole;
        fractional += other.fractional;
        normalize();
    }

    // Checks if another currency is of the same type
    bool isSameType(const Currency& other) const {
        return typeid(*this) == typeid(other);
    }

    // Subtracts another currency value from the current one, normalizes the result
    void subtract(const Currency& other) {
        whole -= other.whole;
        fractional -= other.fractional;
        normalize();
    }

    // Checks if the current currency is greater than another currency
    bool isGreater(const Currency& other) const {
        if (whole > other.whole) return true;
        if (whole == other.whole && fractional > other.fractional) return true;
        return false;
    }

    // Checks if the current currency is equal to another currency
    bool isEqual(const Currency& other) const {
        return whole == other.whole && fractional == other.fractional;
    }

    // Converts the currency value to a string with two decimal places
    std::string toString() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << whole << '.' << std::setw(2) << std::setfill('0') << fractional;
        return oss.str();
    }
};

#endif // CURRENCY_H
