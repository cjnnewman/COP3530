// File: main.cpp
// Dev: Caleb Newman
// Desc: Main file for the HW5 graph homework
// -----------------------------------------------------------------------

#include <iostream>
#include "Graph.hpp"

int main() {
    Graph graph;

    graph.setupTest();
    graph.dijkstras("Gemini&Orion", "RecCenter");


    return 0;
}
