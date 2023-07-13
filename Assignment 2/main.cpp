// File: main.cpp
// Dev: Caleb Newman
// Desc: Main file for linked List homework.
// -----------------------------------------------------------------------
#include <iostream>
#include "linkedlist.hpp"
#include "stack.hpp"
#include "queue.hpp"

int main() {
    //List linkedList;
    //Stack stackList;
    Queue queueList;
    int userMenuChoice;
    int userDataEntry;
    int userIndexEntry;

    for (int i = 0; i < 3; i++) {
        std::cout << "value to insert: ";
        std::cin >> userDataEntry;
        queueList.enqueue(userDataEntry);

        queueList.printList();
    }

    std::cout << "Position 1 is: " << queueList.peek() << "\n";

    /*for (int i = 0; i < 3; i++) {
        std::cout << "value to insert: ";
        std::cin >> userDataEntry;
        stackList.push(userDataEntry);

        stackList.printList();
    }

    for (int i = 0; i < 2; i++) {
        stackList.pop();

        stackList.printList();
    }
    */

    /*
    do {
        std::cout << "MENU \n";
        std::cout << "1. Insert into front of list\t2. Insert into rear of list\n"
                     "3. Remove from front of list\t4. Remove from rear of list\n"
                     "5. Insert at index of list\t6. Remove at index of list\n"
                     "7. Search list for data\t\t8. Delete List\n"
                     "9. Quit\n";
        std::cout << "Enter your menu choice: ";
        std::cin >> userMenuChoice;

        switch (userMenuChoice){
            case 1:
                std::cout << "Enter a value to insert in FRONT: ";
                std::cin >> userDataEntry;
                linkedList.insertFront(userDataEntry);
                break;
            case 2:
                std::cout << "Enter a value to insert in REAR: ";
                std::cin >> userDataEntry;
                linkedList.insertRear(userDataEntry);
                break;
            case 3:
                linkedList.removeFrontInt();
                break;
            case 4:
                linkedList.removeRearInt();
                break;
            case 5:
                std::cout << "Enter data to input into list: ";
                std::cin >> userDataEntry;
                std::cout << "Enter index to input data at: ";
                std::cin >> userIndexEntry;
                linkedList.insertAt(userDataEntry, userIndexEntry);
                break;
            case 6:
                std::cout << "Enter index to remove data from: ";
                std::cin >> userIndexEntry;
                linkedList.removeAt(userIndexEntry);
                break;
            case 7:
                std::cout << "Enter data to search from list: ";
                std::cin >> userDataEntry;
                linkedList.findIndex(userDataEntry);
                break;
            case 8:
                linkedList.makeEmpty();
                break;
            case 9:
                std::cout << "Goodbye!\n";
                return 0;
                break;
            default:
                std::cout << "Invalid entry, try again.\n";
                break;
        }
        std::cout << "List currently: \n";
        linkedList.printList();
    } while (true);
    */

    return 0;
}
