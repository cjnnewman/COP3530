// File: destinationsGraph.cpp
// Dev: Caleb Newman
// Desc: Class .cpp file for the graph structure holding destinations and
// distances.
// -----------------------------------------------------------------------

#include "Graph.hpp"

std::vector<std::string> Graph::readFileIntersectionNames() {
    std::string line;
    std::fstream textFile;
    std::vector<std::string> intersectionNamesVector;

    textFile.open("HWGraphUCFcampus.txt", std::ios::in);

    while(std::getline(textFile, line)){
        std::string intersectionNameSubstring;
        intersectionNameSubstring = line.substr(0, line.find(' '));
        intersectionNamesVector.push_back(intersectionNameSubstring);
    }

    textFile.close();

    return intersectionNamesVector;
}

std::vector<std::string> Graph::mergeSortVector(std::vector<std::string> listOfIntersections) {
    std::vector<std::string> leftHalf;
    std::vector<std::string> rightHalf;
    int sizeOfVector = listOfIntersections.size();
    int middleIndex = sizeOfVector / 2;

    if (sizeOfVector <= 1){
        return listOfIntersections;
    }

    for (int i = 0; i < middleIndex; i++){
        leftHalf.push_back(listOfIntersections[i]);
    }
    for (int j = middleIndex; j < sizeOfVector; j++){
        rightHalf.push_back(listOfIntersections[j]);
    }

    leftHalf = mergeSortVector(leftHalf);
    rightHalf = mergeSortVector(rightHalf);

    return mergeVectors(leftHalf, rightHalf);
}

std::vector<std::string> Graph::mergeVectors(std::vector<std::string> leftHalf, std::vector<std::string> rightHalf) {
    std::vector<std::string> sortedIntersectionsVector;

    while ((leftHalf.size() > 0) && (rightHalf.size() > 0)){
        if (leftHalf[0] <= rightHalf[0]){
            sortedIntersectionsVector.push_back(leftHalf[0]);
            leftHalf.erase(leftHalf.begin());
        }
        else {
            sortedIntersectionsVector.push_back(rightHalf[0]);
            rightHalf.erase(rightHalf.begin());
        }
    }
    while (leftHalf.size() > 0){
        sortedIntersectionsVector.push_back(leftHalf[0]);
        leftHalf.erase(leftHalf.begin());
    }
    while (rightHalf.size() > 0){
        sortedIntersectionsVector.push_back(rightHalf[0]);
        rightHalf.erase(rightHalf.begin());
    }

    return sortedIntersectionsVector;
}

std::vector<std::string> Graph::removeDuplicates(std::vector<std::string> sortedList) {
    std::vector<std::string> sortedListNoDuplicates;

    sortedList.erase(std::unique(sortedList.begin(), sortedList.end()), sortedList.end());
    sortedListNoDuplicates = sortedList;

    return sortedListNoDuplicates;
}

void Graph::populateVertices(std::vector<std::string> list) {
    for (auto i : list ){
        adjList.push_back(Vertex(i));
    }
}

void Graph::addEdges() {
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
        adjList[getVertexIndex(intersection)].edges.push_back(Edge(route, destination, direction, distance, speed));
    }

    textFile.close();

}

int Graph::getVertexIndex(std::string vertexName) {
    bool foundIntersection = false;
    int index = 0;

    while (!foundIntersection){
        if (adjList[index].name.find(vertexName) != std::string::npos){
            foundIntersection = true;
        }
        else {
            index++;
        }
    }

    return index;
}

void Graph::dijkstras(std::string startingIntersection, std::string endingIntersection) {
    int startingIntersectionIndex = getVertexIndex(startingIntersection);
    int endingIntersectionIndex = getVertexIndex(endingIntersection);
    adjList[startingIntersectionIndex].totalDistance = 0;
    adjList[startingIntersectionIndex].prevVertex = nullptr;
    Vertex* startingVertex = &adjList[startingIntersectionIndex];

    while (existsUnvisitedNodes()){
        int currentIndex = getSmallestCostNode();
        adjList[currentIndex].visited = true;
        updateDistances(currentIndex);

    }

    Vertex* currentVertex = &adjList[endingIntersectionIndex];
    std::vector<std::string> route;
    route.push_back(currentVertex->name);
    do {
        route.insert(route.begin(), currentVertex->prevVertex->name);
        currentVertex = currentVertex->prevVertex;
    } while (currentVertex != startingVertex);
    for (auto i : route){
        std::cout << i << "\n";
    }
    prettyPrintRoute(route);

}

int Graph::getSmallestCostNode() {
    float smallestCost = 1000;
    int smallestCostIndex = -1;

    for (auto i : adjList){
        if (!i.visited) {
            if (i.totalDistance < smallestCost) {
                smallestCost = i.totalDistance;
                smallestCostIndex = getVertexIndex(i.name);
            }
        }
    }

    return smallestCostIndex;
}


void Graph::updateDistances(int currentIndex){
    Vertex* currentVertex = &adjList[currentIndex];
    for (auto i  : adjList[currentIndex].edges){
        if ((adjList[currentIndex].totalDistance + i.distance) < adjList[getVertexIndex(i.destination)].totalDistance) {
            int destIndex = getVertexIndex(i.destination);
            adjList[destIndex].totalDistance = (adjList[currentIndex].totalDistance + i.distance);
            adjList[getVertexIndex(i.destination)].prevVertex = currentVertex;
            currentVertex->shortestRouteName = i.route;
            currentVertex->shortestRouteDir = i.direction;
            currentVertex->shortestRouteDistance = i.distance;
            currentVertex->shortestRouteDest = i.destination;
        }
    }
}

bool Graph::existsUnvisitedNodes() {
    for (auto i : adjList){
        if (!i.visited){
            return true;
        }
    }
    return false;
}

void Graph::setupTest() {
    std::vector<std::string> sortedList = mergeSortVector(readFileIntersectionNames());

    std::cout << "\nDisplaying sorted list ... \n\n";
    for (auto i : sortedList){
        std::cout << i << "\n";
    }

    std::cout << "\nDisplaying list with no duplicates... \n\n";

    std::vector<std::string> sortedListNoDuplicates = removeDuplicates(sortedList);
    for (auto j : sortedListNoDuplicates){
        std::cout << j << "\n";
    }

    std::cout << "\nPopulating vertices ...\n\n";

    populateVertices(sortedListNoDuplicates);

    for (int k = 0; k < adjList.size(); k++){
        std::cout << "Vertex: " << adjList[k].name << "\n";
    }

    std::cout << "\nAdding edges ...\n\n";
    addEdges();
}

void Graph::prettyPrintRoute(std::vector<std::string> route) {
    int endIndex = (route.size() - 1);
    int counter = 1;
    std::cout << "\n\tRoute from " << route[0] << " to " << route[endIndex] << " is:\n\n";
    for (auto i : route){
        std::cout << counter << ". " << i << "\n";
        counter++;
    }

}

