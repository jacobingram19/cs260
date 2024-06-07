#pragma once // defines once

#include "graph_node.h"

class GraphNode; // forward declaration

// bidirectional edge
struct edge {
    GraphNode *source;
    GraphNode *destination;
    int weight;
};