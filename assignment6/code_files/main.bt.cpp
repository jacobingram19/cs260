#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree *my_tree = new BinaryTree();

    cout << "------Inserting root node with value 5------" << endl;
    my_tree->insert(5);
    cout << "------Displaying tree in order------" << endl;
    my_tree->in_order(my_tree->get_roots_address());

    cout << "\n------Insert nodes values: 3, 8, 9, 3, 4, 1------" << endl;
    my_tree->insert(3);
    my_tree->insert(8);
    my_tree->insert(9);
    my_tree->insert(3);
    my_tree->insert(4);
    my_tree->insert(1);
    cout << "------Displaying tree in order------" << endl;
    my_tree->in_order(my_tree->get_roots_address());

    cout << "\n------Displaying tree pre order------" << endl;
    my_tree->pre_order(my_tree->get_roots_address());

    cout << "\n------Displaying tree post order------" << endl;
    my_tree->post_order(my_tree->get_roots_address());

    cout << "\n------Removing node with value 6, which is not in tree------" << endl;
    my_tree->remove(my_tree->get_roots_address(),6);

    cout << "------Removing node with value 1, which has no children------" << endl;
    my_tree->remove(my_tree->get_roots_address(),1);

    cout << "------Displaying tree in order------" << endl;
    my_tree->in_order(my_tree->get_roots_address());

    cout << "\n------Removing node with value 8, which has one child------" << endl;
    my_tree->remove(my_tree->get_roots_address(),8);

    cout << "------Displaying tree in order------" << endl;
    my_tree->in_order(my_tree->get_roots_address());

    cout << "\n------Insert nodes values: 7, 6, 8, 11, 10, 12------" << endl;
    my_tree->insert(7);
    my_tree->insert(6);
    my_tree->insert(8);
    my_tree->insert(11);
    my_tree->insert(10);
    my_tree->insert(12);
    cout << "------Displaying tree in order------" << endl;
    my_tree->in_order(my_tree->get_roots_address());

    cout << "\n------Removing node with value 9, which has two children------" << endl;
    my_tree->remove(my_tree->get_roots_address(),9);

    cout << "------Displaying tree in order------" << endl;
    my_tree->in_order(my_tree->get_roots_address());

    return 0;
};