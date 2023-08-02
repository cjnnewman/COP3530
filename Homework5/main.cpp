// File: main.cpp
// Dev: Caleb Newman
// Desc: Main file for the HW5 graph homework
// -----------------------------------------------------------------------
#include <iostream>
#include <string>
#include "destinationsGraph.hpp"

int main() {
    destinationsGraph mainGraph;
    std::string userStartingIntersection;
    std::string userEndingIntersection;

    mainGraph.readSortRemoveDupes();
    mainGraph.setGraphVertices();
    mainGraph.readFileDetails();


    std::cout << "Enter starting intersection: ";
    std::cin >> userStartingIntersection;

    std::cout << "Enter ending intersection: ";
    std::cin >> userEndingIntersection;


    mainGraph.calculateRoute(userStartingIntersection, userEndingIntersection);


    /*std::string currentIntersection;
    std::string destinationIntersection;

    std::cout << "What intersection are you currently at: ";
    std::cin >> currentIntersection;
    std::cout << "What is your desired intersection destination: ";
    std::cin >> destinationIntersection;
     */

    //std::cout << "Enter your map file name, WITHOUT extension: ";
    //std::cin >> userFilename;

    mainGraph.testPrint();


    return 0;
}
