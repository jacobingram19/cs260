#include <iostream>

using namespace std;

#include "node.bt.h";

class BinaryTree {
    private:
        // variables
        node *root;

    public:
        // construct binary tree
        BinaryTree() {
            root = nullptr;
        }

        // recursvie add function. adds value to tree. Tree is sorted in ascending numerical order from left to right.
        // not entirely certain this function is working yet
        int recursive_insert(int new_value, node *parent) { 
            if (parent == nullptr){
                node new_node;
                new_node.value = new_value;
                new_node.left = nullptr;
                new_node.right = nullptr;
                if (root==nullptr){
                    root = &new_node;
                }
                return 0;
            } else if (parent->value >= new_value){
                if (parent->left == nullptr){
                    node new_node;
                    new_node.value = new_value;
                    new_node.left = nullptr;
                    new_node.right = nullptr;
                    parent->left = &new_node;
                    return 0;
                }
                recursive_insert(new_value, parent->left);
            } else if (parent->value < new_value){
                if (parent->right == nullptr){
                    node new_node;
                    new_node.value = new_value;
                    new_node.left = nullptr;
                    new_node.right = nullptr;
                    parent->right = &new_node;
                    return 0;
                }
                recursive_insert(new_value, parent->right);
            }
            return 0;
        }

        // non recursive add function. Tree is sorted in ascending numerical order from left to right.
        void insert(int new_value) {
            bool insert = false; // will set this to true when the value has been inserted
            node *temp = root; // pointer to node that will be iterated through the tree
            if (root == nullptr){ // if there is no root node make the value the root
                root = new node;
                root->value = new_value;
                root->left = nullptr;
                root->right = nullptr;
                insert = true;
            }
            while (insert==false){ 
                if (temp->value >= new_value){
                    if (temp->left == nullptr){ // if there is no left child make the value the left child
                        temp->left = new node;
                        temp->left->value = new_value;
                        temp->left->left = nullptr;
                        temp->left->right = nullptr;
                        insert = true;
                }
                    temp = temp->left; // if there is a left child keep going down the tree
                } else if (temp->value < new_value){
                    if (temp->right == nullptr){ // if there is no right child make the value the right child
                        temp->right = new node;
                        temp->right->value = new_value;
                        temp->right->left = nullptr;
                        temp->right->right = nullptr;
                        insert = true;
                    }
                    temp = temp->right; // if there is a right child keep going down the tree
                }
            }
        }

        void remove(node *root, int del_value){
            node *node_address;
            node_address = search(root, del_value);
            if (node_address == nullptr){
                cout << del_value << " was not found in tree... cannot be deleted." << endl;
            } else {
                if (leaf_check(node_address) == true){ // case 1: node has no children
                    node *parent;
                    parent = get_parent_address(node_address, root);
                    if (parent->right != nullptr){
                        if (parent->right->value == del_value){
                            parent->right = nullptr;
                            delete node_address;
                        } else {
                            parent->left = nullptr;
                            delete node_address;
                        }
                    } else {
                        parent->left = nullptr;
                        delete node_address;
                    }
                } else if (one_child_check(node_address) == true){ // case 2: node has one child
                    node *parent;
                    parent = get_parent_address(node_address, root);
                    if (parent->right != nullptr){
                        if (parent->right->value == del_value){
                            if (node_address->right != nullptr){
                                parent->right = node_address->right;
                            } else {
                                parent->right = node_address->left;
                            }
                            delete node_address;
                        }
                    } else {
                        if (node_address->right != nullptr){
                                parent->left = node_address->right;
                            } else {
                                parent->left = node_address->left;
                            }
                            delete node_address;
                    }
                } else { // case 3: node has 2 children
                    node *temp = node_address->right;
                    while (temp->left != nullptr){
                        temp = temp->left;
                    }
                    int new_value = temp->value;
                    remove(root, temp->value);
                    node_address->value = new_value;
                }
            }
        }

        // searches and returns address of node with certain value
        node* search(node *node, int search_value){
            if (node == nullptr){
                return nullptr;
            } else if (node->value == search_value){
                return node;
            } else if (node->value > search_value){
                return search(node->left,search_value);
            } else {
                return search(node->right,search_value);
            }
        }

        // checks if node is a leaf node
        bool leaf_check(node *node){
            if (node->left == nullptr && node->right == nullptr){
                return true;
            } else {
                return false;
            }
        }

        // checks if node has one child
        bool one_child_check(node *node){
            if (node->left != nullptr && node->right == nullptr){
                return true;
            } else if (node->left == nullptr && node->right != nullptr){ 
                return true;
            } else {
                return false;
            }
        }

        node* get_roots_address(){
            return root;
        }

        // searches for and returns address of parent of node
        node* get_parent_address(node *child, node *node){
            if (node == nullptr){
                return nullptr;
            } else if (node->left->value == child->value || node->right->value == child->value){
                return node;
            } else if (node->value > child->value){
                return get_parent_address(child,node->left);
            } else {
                return get_parent_address(child,node->right);
            }
        }

        // function from chatgpt. using this to test my code.
        void in_order(node *node) const {
            if (node != nullptr) {
                in_order(node->left);
                cout << node->value << " ";
                in_order(node->right);
            }
        }

        // displays tree pre order
        void pre_order(node *node) { 
            if (node != nullptr){
                cout << node->value << " "; // we want to display the node the first time we touch it. 
                pre_order(node->left);
                pre_order(node->right);
            }
        }

        // displays tree post order
        void post_order(node *node) {
            if (node != nullptr){
                pre_order(node->left);
                pre_order(node->right);
                cout << node->value << " "; // we want to display the node the third time we touch it.
            }
        }
};