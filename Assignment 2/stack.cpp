// File: stack.cpp
// Dev: Caleb Newman
// Desc: cpp file for stack class
// -----------------------------------------------------------------------

#include "stack.hpp"


void Stack::push(int data) {
    List::insertFront(data);
}

int Stack::pop() {
    return List::removeFrontInt();
}

int Stack::peek() {

    return List::peek();

    return 0;
}
