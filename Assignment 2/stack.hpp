// File: stack.hpp
// Dev: Caleb Newman
// Desc: Header file for stack class
// -----------------------------------------------------------------------

#ifndef ASSIGNMENT_2_STACK_HPP
#define ASSIGNMENT_2_STACK_HPP
#include "linkedlist.hpp"


class Stack : public List {
public:
    void push (int data);
    int pop();
    int peek();

private:
    int size;

};


#endif //ASSIGNMENT_2_STACK_HPP
