/*edge.h
Name: Jacob Ingram
Student ID: x00505201
Date: 6/10/2024

This file implements the edge struct. This class represents an edge in a graph. The edge has a source node, destination node, and weight.

*/

#pragma once // defines once

#include <iostream>
#include <algorithm>

#include "graph_node.h"

using namespace std;

class GraphNode; // forward declaration

// bidirectional edge
struct edge {
    GraphNode *source;
    GraphNode *destination;
    int weight = numeric_limits<int>::max();
};