/*main.cpp
Name: Jacob Ingram
Student ID: x00505201
Date: 6/10/2024

This is the driver file for the graph project. There are some tests and examples showing how the graph works. 3 different graphs have been made.
I tested the shortest_path() function from the Graph class on "alphabet_graph".
I tested the min_spanning_tree() function from the Graph class on "alphabet_graph_2".
I tested the shortest_path() and min_spanning_tree() functions from the Graph class on "vvardenfell_graph".

*/

#include <iostream>

#include "graph.h"
#include "graph_node.h"

using namespace std;

int main() {
    // testing simple edge situations
    cout << "------Creating 'test_edge'. Expected: source=nullptr ; destination=nullptr ; weight=13------" << endl;
    edge *test_edge = new edge{nullptr, nullptr, 13};
    cout << "test_edge->source: " << test_edge->source << endl;
    cout << "test_edge->destination: " << test_edge->destination << endl;
    cout << "test_edge->weight: " << test_edge->weight << endl;

    // create a simple node to test
    cout << "\n------Creating 'test_node'. Expected: name=town name ; size=0 ; distance=max int------" << endl;
    GraphNode *test_node = new GraphNode("town name");
    cout << "test_node->get_name(): " << test_node->get_name() << endl;
    cout << "test_node->get_neighbors().size(): " << test_node->get_neighbors().size() << endl;
    cout << "test_node->get_distance(): " << test_node->get_distance() << endl;

    // add edge to node
    cout << "\n------Adding edge to 'test_node'------" << endl;
    test_node->add_edge(test_node, 1);
    cout << "test_node->get_neighbors().size(): " << test_node->get_neighbors().size() << endl;
    cout << "test_node->get_neighbors().at(0)->destination->get_name(): " << test_node->get_neighbors().at(0)->destination->get_name() << endl;

    // delete node
    cout << "\n------Deleting 'test_node' and 'test_edge'------" << endl;
    delete test_edge;
    delete test_node;

    cout << "\n------Creating 'alphabet_graph' (this graph will look like the one in my design for shortest path)------" << endl;
    Graph alphabet_graph;

    cout << "\n------Adding nodes: A, B, C, D, E, F------" << endl;
    alphabet_graph.add_node("A");
    alphabet_graph.add_node("B");
    alphabet_graph.add_node("C");
    alphabet_graph.add_node("D");
    alphabet_graph.add_node("E");
    alphabet_graph.add_node("F");

    cout << "\n------Testing that the nodes have been added to alphabet_graph------" << endl;
    cout << "alphabet_graph.get_size(): " << alphabet_graph.get_size() << endl;
    cout << "alphabet_graph.get_nodes().at(0)->get_name(): " << alphabet_graph.get_nodes().at(0)->get_name() << endl;
    cout << "alphabet_graph.get_nodes().at(5)->get_name(): " << alphabet_graph.get_nodes().at(5)->get_name() << endl;

    cout << "\n------Connecting nodes------" << endl;
    alphabet_graph.connect_nodes("A", "C", 3);
    alphabet_graph.connect_nodes("A", "D", 1);
    alphabet_graph.connect_nodes("B", "C", 2);
    alphabet_graph.connect_nodes("B", "D", 2);
    alphabet_graph.connect_nodes("B", "E", 2);
    alphabet_graph.connect_nodes("C", "D", 1);
    alphabet_graph.connect_nodes("C", "E", 6);
    alphabet_graph.connect_nodes("D", "E", 5);

    cout << "\n------Testing that the nodes have been connected. Expected: source=A ; destination=C ; weight=3------" << endl;
    cout << "alphabet_graph.get_nodes().at(0)->get_neighbors().at(0)->source->get_name(): " << alphabet_graph.get_nodes().at(0)->get_neighbors().at(0)->source->get_name() << endl;
    cout << "alphabet_graph.get_nodes().at(0)->get_neighbors().at(0)->destination->get_name(): " << alphabet_graph.get_nodes().at(0)->get_neighbors().at(0)->destination->get_name() << endl;
    cout << "alphabet_graph.get_nodes().at(0)->get_neighbors().at(0)->weight: " << alphabet_graph.get_nodes().at(0)->get_neighbors().at(0)->weight << endl;

    cout << "\n------Testing shortest path------" << endl;
    cout << alphabet_graph.shortest_path("A") << endl;

    cout << "------Creating 'alphabet_graph_2' (this graph will look like the one in my design for minimum spanning tree)------" << endl;
    Graph alphabet_graph_2;

    cout << "\n------Adding nodes: A, B, C, D, E------" << endl;
    alphabet_graph_2.add_node("A");
    alphabet_graph_2.add_node("B");
    alphabet_graph_2.add_node("C");
    alphabet_graph_2.add_node("D");
    alphabet_graph_2.add_node("E");

    cout << "\n------Testing that the nodes have been added to alphabet_graph_2------" << endl;
    cout << "alphabet_graph_2.get_size(): " << alphabet_graph_2.get_size() << endl;
    cout << "alphabet_graph_2.get_nodes().at(0)->get_name(): " << alphabet_graph_2.get_nodes().at(0)->get_name() << endl;
    cout << "alphabet_graph_2.get_nodes().at(3)->get_name(): " << alphabet_graph_2.get_nodes().at(3)->get_name() << endl;

    cout << "\n------Connecting nodes------" << endl;
    alphabet_graph_2.connect_nodes("A", "B", 10);
    alphabet_graph_2.connect_nodes("A", "C", 5);
    alphabet_graph_2.connect_nodes("A", "D", 3);
    alphabet_graph_2.connect_nodes("B", "C", 4);
    alphabet_graph_2.connect_nodes("B", "D", 1);
    alphabet_graph_2.connect_nodes("C", "E", 1);
    alphabet_graph_2.connect_nodes("D", "E", 2);

    cout << "\n------Testing that the nodes have been connected. Expected: source=D ; destination=B ; weight=1------" << endl;
    cout << "alphabet_graph_2.get_nodes().at(3)->get_neighbors().at(1)->source->get_name(): " << alphabet_graph_2.get_nodes().at(3)->get_neighbors().at(1)->source->get_name() << endl;
    cout << "alphabet_graph_2.get_nodes().at(3)->get_neighbors().at(1)->destination->get_name(): " << alphabet_graph_2.get_nodes().at(3)->get_neighbors().at(1)->destination->get_name() << endl;
    cout << "alphabet_graph_2.get_nodes().at(3)->get_neighbors().at(1)->weight: " << alphabet_graph_2.get_nodes().at(3)->get_neighbors().at(1)->weight << endl;

    cout << "\n------Testing minimum spanning tree------" << endl;
    cout << alphabet_graph_2.min_spanning_tree() << endl;

    cout << "------Creating Vvardenfell graph------" << endl;
    Graph vvardenfell_graph;

    cout << "\n------Adding nodes------" << endl;
    vvardenfell_graph.add_node("Ald'ruhn");
    vvardenfell_graph.add_node("Balmora");
    vvardenfell_graph.add_node("Caldera");
    vvardenfell_graph.add_node("Dagon Fel");
    vvardenfell_graph.add_node("Ebonheart");
    vvardenfell_graph.add_node("Gnaar Mok");
    vvardenfell_graph.add_node("Gnisis");
    vvardenfell_graph.add_node("Hla Oad");
    vvardenfell_graph.add_node("Khuul");
    vvardenfell_graph.add_node("Maar Gan");
    vvardenfell_graph.add_node("Molag Mar");
    vvardenfell_graph.add_node("Sadrith Mora");
    vvardenfell_graph.add_node("Seyda Neen");
    vvardenfell_graph.add_node("Suran");
    vvardenfell_graph.add_node("Tel Aruhn");
    vvardenfell_graph.add_node("Tel Branora");
    vvardenfell_graph.add_node("Tel Mora");
    vvardenfell_graph.add_node("Vivec City");
    vvardenfell_graph.add_node("Vos");

    cout << "\n------Connecting nodes------" << endl;
    vvardenfell_graph.connect_nodes("Ebonheart", "Seyda Neen", 56);
    vvardenfell_graph.connect_nodes("Ebonheart", "Vivec City", 51);
    vvardenfell_graph.connect_nodes("Vivec City", "Suran", 47);
    vvardenfell_graph.connect_nodes("Vivec City", "Molag Mar", 112);
    vvardenfell_graph.connect_nodes("Molag Mar", "Suran", 81);
    vvardenfell_graph.connect_nodes("Molag Mar", "Tel Branora", 61);
    vvardenfell_graph.connect_nodes("Hla Oad", "Seyda Neen", 64);
    vvardenfell_graph.connect_nodes("Hla Oad", "Balmora", 48);
    vvardenfell_graph.connect_nodes("Balmora", "Seyda Neen", 80);
    vvardenfell_graph.connect_nodes("Molag Mar", "Tel Aruhn", 148);
    vvardenfell_graph.connect_nodes("Molag Mar", "Sadrith Mora", 154);
    vvardenfell_graph.connect_nodes("Balmora", "Caldera", 47);
    vvardenfell_graph.connect_nodes("Caldera", "Gnaar Mok", 69);
    vvardenfell_graph.connect_nodes("Ald'ruhn", "Gnaar Mok", 83);
    vvardenfell_graph.connect_nodes("Ald'ruhn", "Caldera", 56);
    vvardenfell_graph.connect_nodes("Ald'ruhn", "Maar Gan", 57);
    vvardenfell_graph.connect_nodes("Khuul", "Maar Gan", 88);
    vvardenfell_graph.connect_nodes("Dagon Fel", "Khuul", 189);
    vvardenfell_graph.connect_nodes("Seyda Neen", "Vivec City", 56);
    vvardenfell_graph.connect_nodes("Sadrith Mora", "Tel Aruhn", 23);
    vvardenfell_graph.connect_nodes("Tel Aruhn", "Vos", 103);
    vvardenfell_graph.connect_nodes("Sadrith Mora", "Tel Mora", 111);
    vvardenfell_graph.connect_nodes("Tel Mora", "Vos", 16);
    vvardenfell_graph.connect_nodes("Dagon Fel", "Vos", 116);
    vvardenfell_graph.connect_nodes("Dagon Fel", "Tel Mora", 113);
    vvardenfell_graph.connect_nodes("Dagon Fel", "Maar Gan", 159);

    cout << "\n------Finding shortest path from Vivec City to all other cities------" << endl;
    cout << vvardenfell_graph.shortest_path("Vivec City") << endl;

    cout << "------Finding minimum spanning tree------" << endl;
    cout << vvardenfell_graph.min_spanning_tree() << endl;

    cout << "End of program." << endl;
    
    return 0;
}