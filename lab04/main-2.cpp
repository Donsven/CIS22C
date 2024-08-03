#include "BST.h"
#include <iostream>
#include <fstream>

int main() {
    // Open output file
    std::ofstream outFile("bst_output.txt");

    // Create a BST and insert Dollar objects
    BST bst;
    Dollar dollars[] = {
        Dollar(57.12), Dollar(23.44), Dollar(87.43), Dollar(68.99), Dollar(111.22),
        Dollar(44.55), Dollar(77.77), Dollar(18.36), Dollar(543.21), Dollar(20.21),
        Dollar(345.67), Dollar(36.18), Dollar(48.48), Dollar(101.00), Dollar(11.00),
        Dollar(21.00), Dollar(51.00), Dollar(1.00), Dollar(251.00), Dollar(151.00)
    };

    for (const auto& dollar : dollars) {
        bst.insert(dollar);
    }

    // Perform traversals and write to screen and file
    std::cout << "Breadth-First Traversal:\n";
    outFile << "Breadth-First Traversal:\n";
    bst.breadthFirstTraversal(std::cout);
    bst.breadthFirstTraversal(outFile);

    std::cout << "\nIn-Order Traversal:\n";
    outFile << "\nIn-Order Traversal:\n";
    bst.inOrderTraversal(std::cout);
    bst.inOrderTraversal(outFile);

    std::cout << "\nPre-Order Traversal:\n";
    outFile << "\nPre-Order Traversal:\n";
    bst.preOrderTraversal(std::cout);
    bst.preOrderTraversal(outFile);

    std::cout << "\nPost-Order Traversal:\n";
    outFile << "\nPost-Order Traversal:\n";
    bst.postOrderTraversal(std::cout);
    bst.postOrderTraversal(outFile);

    // Interactive user input for adding/searching/deleting
    char option;
    do {
        std::cout << "\nEnter option (A: Add, S: Search, D: Delete, P: Print, E: Exit): ";
        std::cin >> option;

        if (option == 'A' || option == 'a') {
            double value;
            std::cout << "Enter dollar value to add: ";
            std::cin >> value;
            Dollar newDollar(value);
            bst.insert(newDollar);
            std::cout << "Dollar added.\n";
            outFile << "Added: " << newDollar.toString() << "\n";
        } else if (option == 'D' || option == 'd') {
            double value;
            std::cout << "Enter dollar value to delete: ";
            std::cin >> value;
            Dollar deleteDollar(value);
            bst.deleteDollar(deleteDollar);
            std::cout << "Dollar deleted.\n";
            outFile << "Deleted: " << deleteDollar.toString() << "\n";
        } else if (option == 'P' || option == 'p') {
            std::cout << "\nBreadth-First Traversal:\n";
            outFile << "\nBreadth-First Traversal:\n";
            bst.breadthFirstTraversal(std::cout);
            bst.breadthFirstTraversal(outFile);

            std::cout << "\nIn-Order Traversal:\n";
            outFile << "\nIn-Order Traversal:\n";
            bst.inOrderTraversal(std::cout);
            bst.inOrderTraversal(outFile);

            std::cout << "\nPre-Order Traversal:\n";
            outFile << "\nPre-Order Traversal:\n";
            bst.preOrderTraversal(std::cout);
            bst.preOrderTraversal(outFile);

            std::cout << "\nPost-Order Traversal:\n";
            outFile << "\nPost-Order Traversal:\n";
            bst.postOrderTraversal(std::cout);
            bst.postOrderTraversal(outFile);
        }
    } while (option != 'E' && option != 'e');

    std::cout << "Exiting program...\n";
    outFile.close();

    return 0;
}
