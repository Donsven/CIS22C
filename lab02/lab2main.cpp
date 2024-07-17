/*
LAB NUMBER: LAB 2
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: UTILIZIING A SMALL COIN PROGRAM TO DEMONSTRATE CLASSES, INHERITANCE, AND POLYMORPHISM IN CODE
*/

#include <iostream>
#include <string>
#include "currency.h"
#include "dollar.h"
#include "pound.h"

int main() {
    Currency* currencies[2];    // Declare an array of 2 pointers to Currency objects
    currencies[0] = new Pound(); // Initialize the first element with a new Pound object
    currencies[1] = new Dollar(); // Initialize the second element with a new Dollar object

    std::cout << currencies[0]->toString() << " " << currencies[1]->toString() << std::endl; // Print the initial state

    std::string command; // Declare a string to store the user command
    while (std::cin >> command) { // Loop to read commands until 'q' is entered
        try {
            if (command == "a") { // If the command is 'a' for add
                char type; // Declare a char to store the type (p or d)
                double value; // Declare a double to store the value
                std::string currencyType; // Declare a string to store the currency type
                std::cin >> type >> value >> currencyType; // Read the type, value, and currency type from input
                if (type == 'p' && currencyType == "pound") { // If type is 'p' and currency type is "pound"
                    Pound temp(value); // Create a temporary Pound object with the given value
                    currencies[0]->add(temp); // Add the temporary Pound object to the Pound object in the array
                } else if (type == 'd' && currencyType == "dollar") { // If type is 'd' and currency type is "dollar"
                    Dollar temp(value); // Create a temporary Dollar object with the given value
                    currencies[1]->add(temp); // Add the temporary Dollar object to the Dollar object in the array
                } else {
                    std::cout << "Invalid addition" << std::endl; // Print invalid addition message
                }
                std::cout << currencies[0]->toString() << " " << currencies[1]->toString() << std::endl; // Print the current state
            } else if (command == "s") { // If the command is 's' for subtract
                char type; // Declare a char to store the type (p or d)
                double value; // Declare a double to store the value
                std::string currencyType; // Declare a string to store the currency type
                std::cin >> type >> value >> currencyType; // Read the type, value, and currency type from input
                if (type == 'p' && currencyType == "pound") { // If type is 'p' and currency type is "pound"
                    Pound temp(value); // Create a temporary Pound object with the given value
                    currencies[0]->subtract(temp); // Subtract the temporary Pound object from the Pound object in the array
                } else if (type == 'd' && currencyType == "dollar") { // If type is 'd' and currency type is "dollar"
                    Dollar temp(value); // Create a temporary Dollar object with the given value
                    currencies[1]->subtract(temp); // Subtract the temporary Dollar object from the Dollar object in the array
                } else {
                    std::cout << "Invalid subtraction" << std::endl; // Print invalid subtraction message
                }
                std::cout << currencies[0]->toString() << " " << currencies[1]->toString() << std::endl; // Print the current state
            } else if (command == "q") { // If the command is 'q' to quit
                break; // Exit the loop
            }
        } catch (const std::invalid_argument& e) { // Catch any invalid_argument exceptions
            std::cout << e.what() << std::endl; // Print the exception message
            std::cout << currencies[0]->toString() << " " << currencies[1]->toString() << std::endl; // Print the current state
        }
    }

    delete currencies[0]; // Delete the Pound object to free the allocated memory
    delete currencies[1]; // Delete the Dollar object to free the allocated memory

    return 0; // Return 0 to indicate successful execution
}
