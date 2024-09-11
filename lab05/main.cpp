/*
LAB NUMBER: LAB 5
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: USE INPUT SEED DATA TO CREATE A SEARCHABLE HASH TABLE
*/

#include "HashTable.h"
#include <iostream>

int main() {
    // Seed data from Lab 4 (BST homework)
    Dollar dollars[] = {
        Dollar(57.12), Dollar(23.44), Dollar(87.43), Dollar(68.99), Dollar(111.22),
        Dollar(44.55), Dollar(77.77), Dollar(18.36), Dollar(543.21), Dollar(20.21),
        Dollar(345.67), Dollar(36.18), Dollar(48.48), Dollar(101.00), Dollar(11.00),
        Dollar(21.00), Dollar(51.00), Dollar(1.00), Dollar(251.00), Dollar(151.00)
    };

    int tableSize = 29;
    HashTable hashTable(tableSize);

    // Insert seed data into the hash table
    for (const auto& dollar : dollars) {
        hashTable.insert(dollar);
    }

    // Print the results
    std::cout << "Number of data items loaded: " << hashTable.getNumElements() << std::endl;
    std::cout << "Load factor: " << hashTable.getLoadFactor() << std::endl;
    std::cout << "Number of collisions: " << hashTable.getNumCollisions() << std::endl;

    // User interaction loop
    char choice;
    do {
        double value;
        std::cout << "Enter a dollar value to search for: ";
        std::cin >> value;
        Dollar searchDollar(value);

        int index = hashTable.search(searchDollar);
        if (index != -1) {
            std::cout << "Dollar found at index " << index << std::endl;
        } else {
            std::cout << "Invalid Data" << std::endl;
        }

        std::cout << "Would you like to search again? (Y/N): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
