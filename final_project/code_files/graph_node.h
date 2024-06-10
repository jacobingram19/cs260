/*graph_node.h
Name: Jacob Ingram
Student ID: x00505201
Date: 6/10/2024

This file implements the GraphNode class. This class represents a vertex. The vertex has a name,neighbor edges, distance from the source, and previous node in shortest path to source node.

*/

#pragma once // defines once
#include <string>
#include <vector>
#include <iostream>
#include <limits>

#include "edge.h"

using namespace std;
using std::string;
using std::vector;

// represents a vertex in a graph
class GraphNode {
    public:
    // constructor
    GraphNode(string new_name) {
        name = new_name;
        distance = numeric_limits<int>::max(); // maximum integer
        previous = nullptr;
    }

    // destructor
    ~GraphNode() {
        for (auto neighbor: neighbors) {
            delete neighbor;
        }
    }

    // add edge
    void add_edge(GraphNode *destination, int weight) {
        edge *new_edge = new edge{this, destination, weight};
        neighbors.push_back(new_edge);
    }

    // get name
    string get_name()  {
        return name;
    }

    // get distance
    int get_distance()  {
        return distance;
    }

    GraphNode *get_previous() {
        return previous;
    }

    // set distance
    void set_distance(int new_distance)  {
        distance = new_distance;
    }

    // set previous
    void set_previous(GraphNode *new_previous) {
        previous = new_previous;
    }

    // returns a list of neighbors
    vector<edge *> get_neighbors()  {
        return neighbors;
    }

    private:
    string name; // name of node
    int distance; // distance from node to source
    GraphNode *previous; // previous node in shortest path to source node

    // reference to neighbors
    vector<edge *> neighbors; // list of edges
};