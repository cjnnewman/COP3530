// File: main.cpp
// Dev: Caleb Newman
// Desc: Main file for the HW5 graph homework
// -----------------------------------------------------------------------

#include <iostream>
#include "Graph.hpp"

int main() {
    Graph graph;
    int userChoice;
    std::string userStart;
    std::string userDestination;
    graph.setupTest();

    std::cout << "Enter 1 to run basic test case, enter 2 to specify your own start and destination: ";
    std::cin >> userChoice;

    switch (userChoice){
        case 1:
            graph.dijkstras("Union", "Arena");
            break;
        case 2:
            std::cout << "Enter your starting intersection: ";
            std::cin >> userStart;

            std::cout << "Enter your destination intersection: ";
            std::cin >> userDestination;

            graph.dijkstras(userStart, userDestination);

    }


    return 0;
}
