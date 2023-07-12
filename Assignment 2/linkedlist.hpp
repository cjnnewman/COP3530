// File: List.hpp
// Dev: Caleb Newman
// Desc: Header file for the List class
// -----------------------------------------------------------------------
#ifndef LINKED_LISTS_LIST_HPP
#define LINKED_LISTS_LIST_HPP

#include <iostream>

class List {

    struct Node {
        int value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };


public:
    void isHeadNull();
    void insertFront(int data);
    void insertRear(int data);
    int removeFrontInt();
    int removeRearInt();
    int size();
    void makeEmpty();
    void printList();
    bool insertAt(int data, int index);
    int removeAt(int index);
    int findIndex(int data);

private:
    Node* head = nullptr;


};


#endif //LINKED_LISTS_LIST_HPP