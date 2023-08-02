// File: destinationsGraph.cpp
// Dev: Caleb Newman
// Desc: Class .hpp file for the graph structure holding destinations and
// distances.
// -----------------------------------------------------------------------

#include <fstream>
#include <vector>
#include <iostream>
#include <array>
#include <sstream>
#include <queue>

#ifndef HOMEWORK5_DESTINATIONSGRAPH_HPP
#define HOMEWORK5_DESTINATIONSGRAPH_HPP


class destinationsGraph {
private:
    struct Edge {
        std::string route;
        std::string destination;
        std::string direction;
        float distance;
        float speed;

        // Edge struct constructor with passed values for all components of an edge
        Edge(std::string rt, std::string dt, std::string dr, float ds=0.0, float sp=0.0){
            this->route = rt;
            this->destination = dt;
            this->direction = dr;
            this->distance = ds;
            this->speed = sp;
        }

    };

    struct Vertex {
        std::string name;
        std::vector<Edge> edges;
        int prevVertexIndex;
        int totalDistance;
        bool visited;

        Vertex(std::string intersectionName){
            this->name = intersectionName;
            this->totalDistance = 1000;
            this->visited = false;
        }
    };

    std::vector<std::string> intersectionsList;
    //std::vector<std::string> intersectionListSorted;
    std::vector<Vertex> adjList;
    std::vector<std::string> fileDetails;
    void _privateSetGraphVertices(std::vector<std::string>);
    bool existsUnvisitedNodes();
    int getVertexIndex(std::string);
    void dijkstras(int);
    int getSmallestNodeIndex();
    std::vector<std::string> mergeSortAlphabetically(std::vector<std::string>);
    std::vector<std::string> mergeSortedLists(std::vector<std::string> left, std::vector<std::string> right);

public:
    std::vector<std::string> readSortRemoveDupes();
    void setGraphVertices();
    void readFileDetails();
    void addEdge(std::string, std::string, std::string, std::string, float, float);
    void testPrint();
    void calculateRoute(std::string, std::string);

};


#endif //HOMEWORK5_DESTINATIONSGRAPH_HPP
