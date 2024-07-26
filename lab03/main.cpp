/*
LAB NUMBER: LAB 3
NAME: NELSON LEE, YIJIANG MA
PURPOSE OF THIS ASSIGNMENT: UTILIZIING A LARGER COIN PROGRAM TO DEMONSTRATE THE DATA STRUCTURES LISTS, STACKS, AND QUEUES
*/

#include <iostream>
#include "Currency.h"
#include "Dollar.h"
#include "LinkNode.h"
#include "DoublyLinkedList.h"
#include "LLStack.h"
#include "LLQueue.h"

int main() {
    std::cout << "Welcome to the demonstration of Lists, Stacks and Queues by Yijiang Ma & Nelson Lee" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    // Create an array of Dollar objects
    Dollar dollars[] = {
        Dollar(57.12), Dollar(23.44), Dollar(87.43), Dollar(68.99), Dollar(111.22),
        Dollar(44.55), Dollar(77.77), Dollar(18.36), Dollar(543.21), Dollar(20.21),
        Dollar(345.67), Dollar(36.18), Dollar(48.48), Dollar(101.00), Dollar(11.00),
        Dollar(21.00), Dollar(51.00), Dollar(1.00), Dollar(251.00), Dollar(151.00)
    };

    // Create a DoublyLinkedList object and perform operations
    DoublyLinkedList list;
    for (int i = 6; i >= 0; --i) {
        list.addCurrency(&dollars[i], 0);
    }
    std::cout << "|LINKED LISTS|" << std::endl;
    std::cout << "List after adding first 7 Dollar objects in reverse order: " << list.printList() << std::endl;

    int index = list.findCurrency(&dollars[2]);
    std::cout << "Finding $87.43: Index = " << index << std::endl;

    index = list.findCurrency(&dollars[5]);
    std::cout << "Finding $44.55: Index = " << index << std::endl;

    list.removeCurrency(&dollars[4]);
    list.removeCurrency(2);
    std::cout << "List after removing $111.22 and index 2: " << list.printList() << std::endl;

    list.removeCurrency(list.getCount() % 5);
    list.removeCurrency(list.getCount() / 3);
    std::cout << "List after additional removals: " << list.printList() << std::endl;

    std::cout << std::endl << "|STACKS|" << std::endl;
    // Create an LLStack object and perform operations
    LLStack stack;
    for (int i = 13; i < 20; ++i) {
        stack.push(&dollars[i]);
    }

    std::cout << "Top of the stack after pushing 7 Dollar objects: " << stack.peek()->toString() << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();

    for (int i = 0; i < 5; ++i) {
        stack.push(&dollars[i]);
    }

    stack.pop();
    stack.pop();
    std::cout << "Stack contents after 3 pops, 5 pushes and two pops again: " << stack.toString() << std::endl;

    std::cout << std::endl << "|QUEUES|" << std::endl;
    // Create an LLQueue object and perform operations
    LLQueue queue;
    for (int i = 5, count = 0; i < 20 && count < 7; i += 2, ++count) {
        queue.enqueue(&dollars[i]);
    }

    std::cout << "Front of the queue: " << queue.peekFront()->toString() << std::endl;
    std::cout << "Rear of the queue: " << queue.peekRear()->toString() << std::endl;

    queue.dequeue();
    queue.dequeue();

    for (int i = 10; i < 15; ++i) {
        queue.enqueue(&dollars[i]);
    }

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    std::cout << "Queue contents after 2 dequeues, 5 enqueues and 3 more dequeues: " << queue.toString() << std::endl;

    std::cout << std::endl << "Thanks for observing our program. Goodbye!" << std::endl;

    return 0;
}
