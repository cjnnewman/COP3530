// File: destinationsGraph.cpp
// Dev: Caleb Newman
// Desc: Class .hpp file for the Graph structure holding destinations and
// distances.
// -----------------------------------------------------------------------

#ifndef HW5_CLEAN_GRAPH_HPP
#define HW5_CLEAN_GRAPH_HPP

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

class Graph {
private:
    struct Edge {
        std::string route;
        std::string destination;
        std::string direction;
        float distance;
        float speed;

        // Edge struct constructor with passed values for all components of an edge
        Edge(std::string rt, std::string dt, std::string dr, float ds=0.0, float sp=0.0){
            this->route = std::move(rt);
            this->destination = std::move(dt);
            this->direction = std::move(dr);
            this->distance = ds;
            this->speed = sp;
        }

    };

    struct Vertex {
        std::string name;
        std::vector<Edge> edges;
        Vertex *prevVertex;
        float totalDistance;
        bool visited;
        std::string shortestRouteName;
        std::string shortestRouteDir;
        std::string shortestRouteDest;
        float shortestRouteDistance;

        Vertex(std::string intersectionName){
            this->name = std::move(intersectionName);
            this->totalDistance = 1000;
            this->visited = false;
        }
    };

    //private variables/ds
    std::vector<Vertex> adjList;

    //private functions
    std::vector<std::string> readFileIntersectionNames();
    std::vector<std::string> mergeSortVector(std::vector<std::string>);
    std::vector<std::string> mergeVectors(std::vector<std::string>, std::vector<std::string>);
    std::vector<std::string> removeDuplicates(std::vector<std::string>);
    std::vector<std::string> sortedNoDupes;
    int getCheapestEdge();
    void populateVertices(std::vector<std::string>);
    void addEdges();
    void updateDistances(int);
    void prettyPrintRoute(std::vector<std::string>);
    int getVertexIndex(std::string, int, int);
    int getSmallestCostNode();
    bool existsUnvisitedNodes();

public:
    void setupTest();
    void dijkstras(std::string, std::string);

};


#endif //HW5_CLEAN_GRAPH_HPP
