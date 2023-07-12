// File: List.cpp
// Dev: Caleb Newman
// Desc: cpp file for the List class
// -----------------------------------------------------------------------
#include "List.h"

int List::removeRearInt() {
    return 0;
}

void List::insertRear(int data) {

}

void List::insertFront(int data) {
    if (head->next == nullptr){
        Node* temp = new Node{data, nullptr, head};
        head->next = temp;
    }
    else {
        Node* pNode = head->next;
        Node* temp = new Node{data, pNode, head};
    }
}

int List::removeFrontInt() {
    int value;

    if (head->next != nullptr) {
        Node *pNode = head->next;
        value = pNode->value;
        delete pNode;
    }
    else {
        return 0;
    }

    return value;
}

int List::size() {
    int listSize = 0;

    if (head->next != nullptr){
        Node* pNode = head;
        while (pNode->next != nullptr){
            pNode = pNode->next;
            listSize++;
        }
    }
    else{
        return listSize;
    }
    return listSize;
}

void List::makeEmpty() {
    int listSize = List::size();
    for (int i = 0; i < listSize; i++){

    }
}

bool List::insertAt(int data, int index) {
    return false;
}

int List::removeAt(int index) {
    return 0;
}

int List::findIndex(int data) {
    return 0;
}
