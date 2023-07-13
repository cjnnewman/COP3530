// File: List.hpp
// Dev: Caleb Newman
// Desc: Header file for the List class
// -----------------------------------------------------------------------
#ifndef LINKED_LISTS_LIST_HPP
#define LINKED_LISTS_LIST_HPP

#include <iostream>

class List {
public:
        List();
    ~List();
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
    int peek();

private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    int _size = 0;


};


#endif //LINKED_LISTS_LIST_HPP