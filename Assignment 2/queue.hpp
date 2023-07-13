// File: queue.hpp
// Dev: Caleb Newman
// Desc: Header file for queue class
// -----------------------------------------------------------------------

#ifndef ASSIGNMENT_2_QUEUE_HPP
#define ASSIGNMENT_2_QUEUE_HPP
#include "linkedlist.hpp"


class Queue : public List {
    public:
        void enqueue (int data);
        int dequeue();
        int peek();

    private:
        int size;

};


#endif //ASSIGNMENT_2_QUEUE_HPP
