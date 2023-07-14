// File: List.cpp
// Dev: Caleb Newman
// Desc: cpp file for the List class
// -----------------------------------------------------------------------
#include "linkedlist.hpp"

List::List() {
    new Node {0, nullptr, nullptr};
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    std::cout << "linked list object is being destroyed...\n";
    makeEmpty();

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
        tail = pNode->prev;
        delete pNode;
        _size--;
        return value;
    }
    return 0;
}

void List::insertRear(int data) {
    if (!head){
        head = new Node;
        tail = head;
        head->value = data;
        _size++;
    }
    else if (head->next){
        Node* pNode = head;
        while (pNode->next != nullptr) {
            pNode = pNode->next;
        }
        Node* temp = new Node{data, nullptr, pNode};
        pNode->next = temp;
        tail = temp;
        _size++;
    }
    else {
        Node* pNode = head;
        Node* temp = new Node{data, nullptr, pNode};
        head->next = temp;
        tail = temp;
        _size++;
    }
}

void List::insertFront(int data) {
    if (!head){
        head = new Node;
        head->value = data;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        _size++;
    }
    else {
        Node* temp = head;
        Node* new_front = new Node{data, temp, nullptr};
        head = new_front;
        temp->prev = head;
        _size++;
    }

}

int List::removeFrontInt() {
    int value;

    if (!head){
        return -1;
    }
    else if (head->next != nullptr){
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        value = temp->value;
        delete temp;
        _size--;
        return value;
    }
    else {
        value = head->value;
        head = nullptr;
        tail = nullptr;
        _size--;

        return value;
    }
}

int List::size() {

    return _size;
}

void List::makeEmpty() {
    Node* pNode;
    Node* temp;
    pNode = head;

    if (!head){

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
        tail = nullptr;
        _size = 0;
    }
    else {
        head = nullptr;
        delete head;
    }
}

void List::printList() {
    if (!head){

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
    else if (index == 0){
        insertFront(data);
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
        _size++;
    }
    return true;
}

int List::removeAt(int index) {
    int value;

    if (index > size() || index < 0){
        std::cout << "Index invalid, try again.\n";
        return -1;
    }
    else if (index == 0){
        Node* temp = new Node;
        temp = head;
        value = head->value;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        _size--;
        return value;
    }
    else if (index == (_size - 1)){
        Node* temp = new Node;
        temp = tail;
        value = tail->value;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        _size--;
        return value;
    }
    else {
        Node* pNode = head;
        for (int i = 0; i < index; i++){
            pNode = pNode->next;
        }
        value = pNode->value;
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
        _size--;
    }
    return value;
}

int List::findIndex(int data) {
    int index = 0;
    Node* pNode = head;

    if (!head){
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

int List::read(int index) {
    return priv_traverse(index)->value;
}

List::Node *List::priv_traverse(int index) {
    Node* pNode = new Node;
    pNode = head;
    for (int i = 0; i < index; i++){
        pNode = pNode->next;
    }

    return pNode;
}


