// File: List.h
// Dev: Caleb Newman
// Desc: Header file for the List class
// -----------------------------------------------------------------------
#ifndef LINKED_LISTS_LIST_H
#define LINKED_LISTS_LIST_H


class List {

    struct Node {
        int value;
        Node* next;
        Node* prev;
    };


public:
    void insertFront(int data);
    void insertRear(int data);
    int removeFrontInt();
    int removeRearInt();
    int size();
    void makeEmpty();
    bool insertAt(int data, int index);
    int removeAt(int index);
    int findIndex(int data);

private:
    Node* head = new Node{5, nullptr, nullptr};

};


#endif //LINKED_LISTS_LIST_H
