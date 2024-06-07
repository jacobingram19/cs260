#pragma once // defines once
#include <iostream>
#include <limits>
#include <algorithm>

#include "graph_node.h"

using namespace std;

class Graph {
    public:
    // constructor
    Graph() {
        
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

            queue.erase(queue.begin() + current_index);
            
            GraphNode *next_current = new GraphNode("Next Current");

            for (auto node : queue) {
                if (node->get_distance() < next_current->get_distance()) { // next current should be unvisited and have the smallest distance
                    next_current = node;
                }
            }

            current = next_current;
        }

        string output = "";

        for (auto node : nodes) {
            string str_distance = to_string(node->get_distance());
            if (node->get_distance() == numeric_limits<int>::max()) {
                output = output + node->get_name() + " cannot reach " + source_node->get_name();
            } else {
                output = output + node->get_name() + "'s shortest distance to " + source_node->get_name() + " = " + str_distance;
            }

            if (node->get_previous() == nullptr) {
                if (node == source_node) {
                    output = output + "  |  Path from " + source_node->get_name() + " to " + node->get_name() + " is " + node->get_name() + "<-" + source_node->get_name() + "\n";
                } else {
                    output = output + "\n";
                }
            } else {
                output = output + "  |  Path from " + source_node->get_name() + " to " + node->get_name() + " is " + node->get_name() + "<-" + node->get_previous()->get_name();
                if (node->get_previous() != source_node) {
                    GraphNode *temp = node->get_previous();
                    while (temp != source_node) {
                        output = output + "<-" + temp->get_previous()->get_name();
                        temp = temp->get_previous();
                }
                }
                output = output + "\n";
            }
        }

        return output;
    }

    // minimum spanning tree
    string min_spanning_tree() {

    }

    private:
    // some way of storing the data
    vector<GraphNode *> nodes;
};