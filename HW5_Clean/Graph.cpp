// File: destinationsGraph.cpp
// Dev: Caleb Newman
// Desc: Class .cpp file for the graph structure holding destinations and
// distances.
// -----------------------------------------------------------------------

#include "Graph.hpp"

// Function reads the file parsing only the first column of each line, enters these intersection
// names into a vector.
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

// Function will implement a merge sort algorithm on the list of intersection names, alphabetically sorting them.
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

// Function merges the vectors as part of the merge sort algo.
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

// Function will cycle through the vector of intersection names, creating a copy and pushing into a new vector
// if and only if the name does not already exist in the vector.
std::vector<std::string> Graph::removeDuplicates(std::vector<std::string> sortedList) {
    std::vector<std::string> sortedListNoDuplicates;
    std::string prevString = " ";

    for (int i = 0; i < sortedList.size(); i++){

        if (sortedList[i] != prevString){
            sortedListNoDuplicates.push_back(sortedList[i]);
            prevString = sortedList[i];
        }
        else {
            std::cout << "skipped " << sortedList[i] << "\n";
        }
    }

    sortedNoDupes = sortedListNoDuplicates;
    return sortedListNoDuplicates;
}

// Function to populate the adjacent list with each vertex, intersection names from the list vector.
void Graph::populateVertices(std::vector<std::string> list) {
    for (auto i : list ){
        adjList.push_back(Vertex(i));
    }
}

// Function will find each pertaining intersection, and populate the vector of Edges stored in that vertex
// to populate the list of connections.
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
        adjList[getVertexIndex(intersection, 0, (sortedNoDupes.size() - 1))].edges.push_back(Edge(route, destination, direction, distance, speed));
    }

    textFile.close();

}

// Function performs a basic O(n) search on the list of intersections to find an intersections index in the
// adjlist. (Sorry, i couldn't get the binary search to work :C)
int Graph::getVertexIndex(std::string vertexName, int startIndex, int endIndex) {
    int index = 0;
    bool foundIntersection = false;
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

// Implements dijkstras algorithm to find the shortest path between two vertices by distance or "cost"
void Graph::dijkstras(std::string startingIntersection, std::string endingIntersection) {
    int startingIntersectionIndex = getVertexIndex(startingIntersection, 0, (sortedNoDupes.size() - 1));
    int endingIntersectionIndex = getVertexIndex(endingIntersection, 0, (sortedNoDupes.size() - 1));
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

// finds the smallest remaining node that has not been visited by dijkstras
int Graph::getSmallestCostNode() {
    float smallestCost = 1000;
    int smallestCostIndex = -1;

    for (auto i : adjList){
        if (!i.visited) {
            if (i.totalDistance < smallestCost) {
                smallestCost = i.totalDistance;
                smallestCostIndex = getVertexIndex(i.name, 0, (sortedNoDupes.size() - 1));
            }
        }
    }

    return smallestCostIndex;
}

// updates distances from each note to it's edges based on the total distance traveled thus far
void Graph::updateDistances(int currentIndex){
    Vertex* currentVertex = &adjList[currentIndex];
    for (auto i  : adjList[currentIndex].edges){
        if ((adjList[currentIndex].totalDistance + i.distance) < adjList[getVertexIndex(i.destination, 0, (sortedNoDupes.size() - 1))].totalDistance) {
            int destIndex = getVertexIndex(i.destination, 0, (sortedNoDupes.size() - 1));
            adjList[destIndex].totalDistance = (adjList[currentIndex].totalDistance + i.distance);
            adjList[getVertexIndex(i.destination, 0, (sortedNoDupes.size() - 1))].prevVertex = currentVertex;
            currentVertex->shortestRouteName = i.route;
            currentVertex->shortestRouteDir = i.direction;
            currentVertex->shortestRouteDistance = i.distance;
            currentVertex->shortestRouteDest = i.destination;
        }
    }
}

// simply test to find if there remain vertices that are unvisited
bool Graph::existsUnvisitedNodes() {
    for (auto i : adjList){
        if (!i.visited){
            return true;
        }
    }
    return false;
}

// basic setup function for test purposes
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

// prints route intersections
void Graph::prettyPrintRoute(std::vector<std::string> route) {
    int endIndex = (route.size() - 1);
    int counter = 1;
    std::cout << "\n\tShortest route from " << route[0] << " to " << route[endIndex] << " is:\n\n";
    for (auto i : route){
        std::cout << counter << ". " << i << "\n";
        counter++;
    }

}

