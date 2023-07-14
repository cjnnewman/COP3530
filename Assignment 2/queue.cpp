// File: queue.cpp
// Dev: Caleb Newman
// Desc: cpp file for queue class
// -----------------------------------------------------------------------

#include "queue.hpp"

void Queue::enqueue(int data) {
    List::insertRear(data);
}

int Queue::dequeue() {
    return List::removeFrontInt();
}

int Queue::peek() {
    return List::read(0);
}
