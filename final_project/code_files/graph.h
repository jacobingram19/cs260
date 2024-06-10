/*graph.h
Name: Jacob Ingram
Student ID: x00505201
Date: 6/10/2024

This file implements the Graph class. This class represents a graph that can store nodes.

*/

#pragma once // defines once
#include <iostream>
#include <algorithm>

#include "graph_node.h"

using namespace std;

// represents a graph
class Graph {
    public:
    // constructor
    Graph() {
        nodes;
    }

    // destructor
    ~Graph() {

    }
    
    // add node
    void add_node(string new_name) {
        GraphNode *new_node = new GraphNode(new_name); // create node
        nodes.push_back(new_node); // add to nodes list
    }

    // add edge
    void connect_nodes(string source_name, string dest_name, int weight) {
        GraphNode *source_node = nullptr;
        GraphNode *dest_node = nullptr;

        // find source and destination node addresses
        for(auto current : nodes) {
            if(source_name == current->get_name()) {
                source_node = current;
            }

            if(dest_name == current->get_name()) {
                dest_node = current;
            }
        }

        // connect source to destination (will need to add it both ways) (undirected graph)
        // this method creates two edge objects. So... not very efficient
        if (source_node != nullptr && dest_node != nullptr) {
            source_node->add_edge(dest_node, weight);
            dest_node->add_edge(source_node, weight);
        }
    }

    int get_size() {
        return nodes.size();
    }

    // shortest path (implements Dijkstra's algorithm)
    string shortest_path(string source_name) {
        GraphNode *source_node = nullptr;

        // find source node addresses
        for(auto current : nodes) {
            if(source_name == current->get_name()) {
                source_node = current;
            }
            current->set_distance(numeric_limits<int>::max());
            current->set_previous(nullptr);
        }

        // set source node's distance to 0
        source_node->set_distance(0);

        // queue of unvisited nodes
        vector<GraphNode *> queue = nodes;

        // finds the shortest distance from the source node to all other nodes
        GraphNode *current = source_node;
        while (queue.size() != 0) {
            
            for (auto edge : current->get_neighbors()) { // iterates through "current's" neighbors
                GraphNode *dest = edge->destination; // create destination node
                if (dest->get_distance() > current->get_distance() + edge->weight) { // if a shorter path is found
                    dest->set_distance(current->get_distance() + edge->weight); // update destination's distance
                    dest->set_previous(current); // update destination's previous
                }
            }

            int count = 0;
            int current_index = 0;
            for (auto node : queue) {
                if (node == current) { // finds index of the current
                    current_index = count;
                }
                count += 1;
            }

            queue.erase(queue.begin() + current_index); // removes current from unvisited list
            
            GraphNode *next_current = new GraphNode("Next Current");

            for (auto node : queue) {
                if (node->get_distance() < next_current->get_distance()) { // next current should be unvisited and have the smallest distance
                    next_current = node;
                }
            }

            current = next_current;
        }

        string output = "";

        // this for loop creates the output string
        for (auto node : nodes) {
            string str_distance = to_string(node->get_distance());
            if (node->get_distance() == numeric_limits<int>::max()) {
                output = output + node->get_name() + " cannot reach " + source_node->get_name() + ".";
            } else {
                output = output + node->get_name() + "'s shortest distance to " + source_node->get_name() + " = " + str_distance + " km";
            }

            if (node->get_previous() == nullptr) {
                if (node == source_node) {
                    output = output + "  |  Path from " + source_node->get_name() + " to " + node->get_name() + " is " + node->get_name() + " <- " + source_node->get_name() + "\n";
                } else {
                    output = output + "\n";
                }
            } else {
                output = output + "  |  Path from " + source_node->get_name() + " to " + node->get_name() + " is " + node->get_name() + " <- " + node->get_previous()->get_name();
                if (node->get_previous() != source_node) {
                    GraphNode *temp = node->get_previous();
                    while (temp != source_node) {
                        output = output + " <- " + temp->get_previous()->get_name();
                        temp = temp->get_previous();
                }
                }
                output = output + "\n";
            }
        }

        return output;
    }

    // minimum spanning tree (implements Prim's algorithm)
    string min_spanning_tree() {
        GraphNode *source_node = nodes[0]; // source node is the first node added to the graph
        vector<GraphNode *> visited; // list of visited nodes
        visited.push_back(source_node);
        vector<edge *> tree_edges; // list of edges in the minimum spanning tree
        GraphNode *current = source_node;

        int floating_nodes = 0;
        for (auto node : nodes) { // checking if there are any nodes not connected to the graph
            int neighbor_size = node->get_neighbors().size();
            if (neighbor_size < 1) {
                floating_nodes += 1;
            }
        }

        while (visited.size() < nodes.size() - floating_nodes) { // might not work if there is a disconnected node
            edge *lightest_edge_1 = new edge(); // lightest edge 1
            edge *lightest_edge_2 = new edge(); // lightest edge 2
            if (visited.size() > 1) {
                for (auto visited_node : visited) { // finds the edge with the lowest weight
                    for (auto neighbor : visited_node->get_neighbors()) {
                        bool contains = false;
                        for (auto tree_edge : tree_edges) { // checks if neighbor is a tree edge
                            if (tree_edge == neighbor) {
                                contains = true;
                            }
                        }
                        for (auto node : visited) { // checks if destination has already been visited
                            if (node == neighbor->destination) {
                                contains = true;
                            }
                        }
                        if (contains == false) {
                            if (neighbor->weight < lightest_edge_1->weight) {
                                lightest_edge_1 = neighbor;
                                lightest_edge_2->weight = lightest_edge_1->weight;
                                lightest_edge_2->destination = lightest_edge_1->source;
                                lightest_edge_2->source = lightest_edge_1->destination;
                            }
                        }
                    }
                }
            } else {
                for (auto neighbor : source_node->get_neighbors()) { // finds the edge with the lowest weight
                    if (neighbor->weight < lightest_edge_1->weight) {
                        lightest_edge_1 = neighbor;
                        lightest_edge_2->weight = lightest_edge_1->weight;
                        lightest_edge_2->destination = lightest_edge_1->source;
                        lightest_edge_2->source = lightest_edge_1->destination;
                    }
                }
            }
            tree_edges.push_back(lightest_edge_1);
            tree_edges.push_back(lightest_edge_2);
            current = lightest_edge_1->destination;
            visited.push_back(current);
        }

        string output = "";
        int count = -1;
        int one_two_count = 1;
        int count2 = 0;
        int total_weight = 0;

        for (auto tree_edge : tree_edges) {
            total_weight += tree_edge->weight;
            count += 1;
            one_two_count = (count % 2) + 1;
            if (count % 2 == 0) {
                count2 += 1;
            }
            string str_count = to_string(count);
            string str_weight = to_string(tree_edge->weight);
            string str_one_two_count = to_string(one_two_count);
            string str_count2 = to_string(count2);
            output = output + "Edge " + str_count2 + "." + str_one_two_count + ": weight = " + str_weight + " | source = " + tree_edge->source->get_name() + " | destination = " + tree_edge->destination->get_name() + "\n";
        }
        total_weight = total_weight / 2;
        string str_total_weight = to_string(total_weight);

        output = output + "Total weight: " + str_total_weight + " km" + "\n";

        return output;
    }

    private:
    // stores the GraphNode's
    vector<GraphNode *> nodes;
};