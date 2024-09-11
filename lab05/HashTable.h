/*
LAB NUMBER: LAB 5
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: USE INPUT SEED DATA TO CREATE A SEARCHABLE HASH TABLE
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Dollar.h"
#include <iostream>
#include <vector>

class HashTable {
private:
    std::vector<Dollar*> table;
    int size;
    int numElements;
    int numCollisions;

    /*    
    Calculates the hash value for a given Dollar object using its whole and fractional parts.
    Pre:    whole -- The whole part of the Dollar object.
            fractional -- The fractional part of the Dollar object.
    Post:   
    Return: The hash value calculated using the whole and fractional parts.
    Throws: 
    */
    int hashFunction(int whole, int fractional) const {
        int m = 2, n = 3;
        return (m * whole + n * fractional) % size;
    }

    /*    
    Calculates the new index for quadratic probing.
    Pre:    index -- The initial index.
            i -- The current probe iteration.
    Post:   
    Return: The new index calculated using quadratic probing.
    Throws: 
    */
    int quadraticProbe(int index, int i) const {
        return (index + i * i) % size;
    }

public:
    // Constructor
    HashTable(int tableSize) : size(tableSize), numElements(0), numCollisions(0) {
        table.resize(size, nullptr);
    }

    /*    
    Method to insert a Dollar object into the hash table
    Pre:    dollar -- The Dollar object to be inserted.
    Post:   The Dollar object is inserted into the hash table.
    Return: 
    Throws: 
    */
    void insert(const Dollar& dollar) {
        int index = hashFunction(dollar.getWholePart(), dollar.getFractionalPart());
        int i = 0;
        while (table[index] != nullptr) {
            numCollisions++;
            i++;
            index = quadraticProbe(index, i);
        }
        table[index] = new Dollar(dollar);
        numElements++;
    }

    /*    
    Method to search for a Dollar object in the hash table
    Pre:    dollar -- The Dollar object to be searched for.
    Post:   
    Return: The index of the Dollar object if found, otherwise -1.
    Throws: 
    */
    int search(const Dollar& dollar) const {
        int index = hashFunction(dollar.getWholePart(), dollar.getFractionalPart());
        int i = 0;
        while (table[index] != nullptr && !table[index]->isEqual(dollar)) {
            i++;
            index = quadraticProbe(index, i);
        }
        if (table[index] != nullptr && table[index]->isEqual(dollar)) {
            return index;
        } else {
            return -1; // Not found
        }
    }

    // Method to print the hash table
    void printTable() const {
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                std::cout << "Index " << i << ": " << table[i]->toString() << std::endl;
            } else {
                std::cout << "Index " << i << ": [empty]" << std::endl;
            }
        }
    }

    // Getter for the number of elements
    int getNumElements() const {
        return numElements;
    }

    // Getter for the number of collisions
    int getNumCollisions() const {
        return numCollisions;
    }

    // Getter for the load factor
    double getLoadFactor() const {
        return static_cast<double>(numElements) / size;
    }

    // Destructor to free memory
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            delete table[i];
        }
    }
};

#endif // HASHTABLE_H
