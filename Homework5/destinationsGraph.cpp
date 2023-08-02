// File: destinationsGraph.cpp
// Dev: Caleb Newman
// Desc: Class .cpp file for the graph structure holding destinations and
// distances.
// -----------------------------------------------------------------------

#include "destinationsGraph.hpp"

std::vector<std::string> destinationsGraph::readSortRemoveDupes() {
    std::string line;
    std::fstream textFile;
    textFile.open("HWGraphUCFcampus.txt", std::ios::in);

    while (std::getline(textFile, line)){
        std::string intersectionNameSubString;
        intersectionNameSubString = line.substr(0, line.find(" "));
        intersectionsList.push_back(intersectionNameSubString);
    }
    intersectionsList.erase(std::unique(intersectionsList.begin(), intersectionsList.end()), intersectionsList.end());
    std::sort(intersectionsList.begin(), intersectionsList.end());
    //mergeSortAlphabetically(intersectionsList);

    return intersectionsList;
}

void destinationsGraph::_privateSetGraphVertices(std::vector<std::string> intersectionsList) {
    for (auto i : intersectionsList){
        adjList.push_back(Vertex(i));
    }

}

void destinationsGraph::setGraphVertices() {
    _privateSetGraphVertices(intersectionsList);
}

void destinationsGraph::readFileDetails(){
    std::string line;
    std::fstream textFile;
    textFile.open("HWGraphUCFcampus.txt", std::ios::in);

    std::string intersection;
    std::string route;
    std::string destination;
    std::string direction;
    float distance;
    float speed;

    while (std::getline(textFile, line)){
        std::stringstream iss(line);
        iss >> std::ws >> intersection >> route >> destination >> direction >> distance >> speed;
        addEdge(intersection, route, destination, direction, distance, speed);
    }

    textFile.close();

}

void destinationsGraph::addEdge(std::string intersection, std::string route, std::string destination, std::string direction, float distance, float speed) {
    int intersectionIndex = getVertexIndex(intersection);
    adjList[intersectionIndex].edges.push_back(Edge(route, destination, direction, distance, speed));
}

int destinationsGraph::getVertexIndex(std::string intersection) {
    bool foundIntersection = false;
    int index = 0;

    while (!foundIntersection){
        if (adjList[index].name.find(intersection) != std::string::npos){
            foundIntersection = true;
        }
        else {
            index++;
        }
    }

    return index;
}

void destinationsGraph::calculateRoute(std::string startingIntersection, std::string endingIntersection) {
    int startingIndex = getVertexIndex(startingIntersection);
    int endingIndex = getVertexIndex(endingIntersection);

    std::cout << "Start index is : " << startingIndex << " Ending index is: " << endingIndex << "\n";

}

void destinationsGraph::dijkstras(int startingIntersectionIndex) {
    adjList[startingIntersectionIndex].totalDistance = 0;
    adjList[startingIntersectionIndex].prevVertexIndex = startingIntersectionIndex;
    adjList[startingIntersectionIndex].visited = true;
    int currentNodeIndex = startingIntersectionIndex;
    while (existsUnvisitedNodes()){

    }

}

std::vector<std::string> destinationsGraph::mergeSortAlphabetically(std::vector<std::string> intersectionList) {
    int size = intersectionList.size();
    int midIndex = size / 2;
    if (intersectionList.size() <= 1){
        return intersectionList;
    }

}

std::vector<std::string> destinationsGraph::mergeSortedLists(std::vector<std::string> left, std::vector<std::string> right) {
    std::vector<std::string> sortedList;

    while ((left.size() > 0) && (right.size() > 0)){
        if (left[0] <= right[0]){
            sortedList.push_back(left[0]);
            left = {left[1], left[(left.size()-1)]};
        }
        else {
            sortedList.push_back(right[0]);
            right = {right[1], right[(right.size()-1)]};
        }
        if (!(left.empty())){
            sortedList.push_back(left[0]);
        }
        if (!(right.empty())){
            sortedList.push_back(right[0]);
        }
    }


    return sortedList;
}

void destinationsGraph::testPrint() {
    std::cout << adjList[12].edges.size() << "\n";
    std::cout << adjList[12].edges[0].distance << "\n";
    std::cout << adjList[12].edges[0].destination << "\n";
}

bool destinationsGraph::existsUnvisitedNodes() {
    for (auto i : adjList){
        if (i.visited = false){
            return true;
        }
    }
    return false;
}

int destinationsGraph::getSmallestNodeIndex() {
    int smallestNodeIndex;
    int
    for (auto i : adjList){

    }

    return 0;
}





