// File: List.cpp
// Dev: Caleb Newman
// Desc: cpp file for the List class
// -----------------------------------------------------------------------
#include "linkedlist.hpp"

void List::isHeadNull(){
    if (head == nullptr){
        std::cout << "null \n";
    }
    else if (head != nullptr){
        std::cout << "not null \n";
    }
    else{
        std::cout << "neither?? \n";
    }
}

int List::removeRearInt() {
    int value;

    if (head == nullptr){
        std::cout << "List is empty, add something!";
        return -1;
    }
    else if (head->next != nullptr){
        Node* pNode = head;
        while (pNode->next != nullptr) {
            pNode = pNode->next;
        }
        value = pNode->value;
        pNode->prev->next = nullptr;
        delete pNode;
        return value;
    }
    return 0;
}

void List::insertRear(int data) {
    if (head == nullptr){
        head = new Node;
        head->value = data;
    }
    else if (head->next != nullptr){
        Node* pNode = head;
        while (pNode->next != nullptr) {
            pNode = pNode->next;
        }
        Node* temp = new Node{data, nullptr, pNode};
        pNode->next = temp;
    }
    else {
        Node* pNode = head;
        Node* temp = new Node{data, nullptr, pNode};
        head->next = temp;
    }
}

void List::insertFront(int data) {
    if (head == nullptr){
        head = new Node;
        head->value = data;
    }
    else {
        Node* temp = head;
        Node* new_front = new Node{data, temp, nullptr};
        head = new_front;
        temp->prev = head;
    }

}

int List::removeFrontInt() {
    int value;

    if (head == nullptr){
        std::cout << "List is empty, add something!\n";
        return -1;
    }
    else if (head->next != nullptr){
        Node* temp = head;
        head = head->next;
        value = temp->value;
        delete temp;
        return value;
    }
    else {
        value = head->value;
        head = nullptr;

        return value;
    }
}

int List::size() {
    int listSize = 0;
    if (head == nullptr){
        std::cout << "List is empty.\n";
        return listSize;
    }
    else{
        listSize++;
        Node* pNode = head;
        while (pNode->next != nullptr){
            pNode = pNode->next;
            listSize++;
        }
    }

    return listSize;
}

void List::makeEmpty() {
    Node* pNode;
    Node* temp;
    pNode = head;

    if (head == nullptr){
        std::cout << "List is already empty!" << "\n";
    }
    else if (head->next != nullptr) {
        while (pNode->next != nullptr) {
            pNode = pNode->next;
        }
        while (pNode->prev != nullptr) {
            temp = pNode;
            pNode = pNode->prev;
            pNode->next = nullptr;
            delete temp;
        }
        head = nullptr;

        std::cout << "List is empty, start over!\n";
    }
}

void List::printList() {
    std::cout << "List size: " << size() << "\n";
    if (head == nullptr){
        std::cout << "List is empty!\n";
    }
    else if (head->next != nullptr){
        Node* pNode = head;
        std::cout << pNode->value << "\n";
        while (pNode->next != nullptr) {
            pNode = pNode->next;
            std::cout << pNode->value << "\n";
        }
    }
    else{
        std::cout << head->value << "\n";
    }
}

bool List::insertAt(int data, int index) {
    if (index > size() || index < 0){
        std::cout << "Index invalid, try again.\n";
        return false;
    }
    else {
        Node* pNode = head;
        for (int i = 0; i < index; i++){
            pNode = pNode->next;
        }
        Node* temp_prev = pNode->prev;
        Node* temp = new Node{data, pNode, temp_prev};
        pNode->prev = temp;
        temp_prev->next = temp;
    }
    return true;
}

int List::removeAt(int index) {
    int value;

    if (index > size() || index < 0){
        std::cout << "Index invalid, try again.\n";
        return -1;
    }
    else {
        Node* pNode = head;
        for (int i = 0; i < index; i++){
            pNode = pNode->next;
        }
        value = pNode->value;
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }
    return value;
}

int List::findIndex(int data) {
    int index = 0;
    Node* pNode = head;

    if (head == nullptr){
        std::cout << "There is nothing in the list, add something to search for silly!\n";
        return -1;
    }

    do {
        if (pNode->value == data){
            std::cout << "Value found at index: " << index << "\n";
            return index;
        }
        else {
            index++;
            pNode = pNode->next;
        }
    } while (pNode->next != nullptr);

    if (pNode->value == data){
        std::cout << "Value found at index: " << index << "\n";
        return index;
    }
    else {
        std::cout << "Failed search \n";
    }

    return -1;
}