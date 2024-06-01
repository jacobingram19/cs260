#include <iostream>
#include "node.h"

using namespace std;
using std::stoi;

class HashTable {
    private:
        // variables
        node *root;

    public:
        // construct binary tree
        HashTable() {
            root = nullptr;
        }

        // finds a hash value for a string
        // takes in a string input and outputs a string that looks like an integer
        // only works with lowercase letters
        string hash(string input_string){

            string hash_value;

            for (int i = 0; i < input_string.size(); i++){

                int int_char = int(input_string[i])-96; // converts character to ASCII value then subtracts 96
                string str_int_char = to_string(int_char);

                if (int_char < 10) { // will concatonate 0 if the character is a through i
                    str_int_char = '0' + str_int_char; 
                }

                hash_value = hash_value + str_int_char;
            }

            return hash_value;
        }

        // non recursive add function. Tree is sorted in ascending numerical order from left to right.
        void insert(string str_value) {
            bool insert = false; // will set this to true when the value has been inserted
            int new_value = stoi(str_value); // converts string to integer

            bool result;
            result = contains(str_value);
            if (result == true) { // if there is a collision... make a linked list at the collision

                node *head;
                head = search(root, new_value);
                head->index = 1;
                node *tail = new node;
                tail->value = new_value;
                tail->next = nullptr;
                int count = 0;
                node *temp_ptr = head;
                while (temp_ptr->next != nullptr){ // will iteratre through linked list until the previous tail is found
                    count += 1;
                    temp_ptr = temp_ptr -> next;
                }
                temp_ptr->next = tail;
                tail->index = count;

                insert = true;
            } else { // if there is no collision
                node *temp = root; // pointer to node that will be iterated through the tree
                if (root == nullptr){ // if there is no root node make the value the root
                    root = new node;
                    root->value = new_value;
                    root->left = nullptr;
                    root->right = nullptr;
                    root->next = nullptr;
                    root->index = 1;
                    insert = true;
                }
                while (insert==false){ 
                    if (temp->value >= new_value){
                        if (temp->left == nullptr){ // if there is no left child make the value the left child
                            temp->left = new node;
                            temp->left->value = new_value;
                            temp->left->left = nullptr;
                            temp->left->right = nullptr;
                            temp->left->next = nullptr;
                            temp->left->index = 1;
                            insert = true;
                    }
                        temp = temp->left; // if there is a left child keep going down the tree
                    } else if (temp->value < new_value){
                        if (temp->right == nullptr){ // if there is no right child make the value the right child
                            temp->right = new node;
                            temp->right->value = new_value;
                            temp->right->left = nullptr;
                            temp->right->right = nullptr;
                            temp->right->next = nullptr;
                            temp->right->index = 1;
                            insert = true;
                        }
                        temp = temp->right; // if there is a right child keep going down the tree
                    }
                }
            }
        }

        // determines whether or not a hash value already exists in the binary search tree
        bool contains(string hash_value) {
            int int_hash_value = stoi(hash_value); // converts string to integer
            node *collision_node = search(root, int_hash_value);
            if (collision_node != nullptr) {
                return true;
            }
            return false;
        }

        // iterates through tree and returns dehashed values in order.
        void display_dehash(node *node) const {
            if (node != nullptr) {
                display_dehash(node->left);

                string string_value = to_string(node->value);

                if (string_value.size() % 2 == 1) {
                    string_value = '0' + string_value;
                }

                string result;
                
                for (int i = 0; i < string_value.size(); i+=2){

                    string char_str;
                    char_str = string_value[i];
                    char_str = char_str + string_value[i+1]; // two numbers in the hashed value as a string

                    int char_int = stoi(char_str); // turns string back into integer
                    for (char c = 'a'; c <= 'z'; c++){
                        int int_c = int(c)-96; // converts character to ASCII value then subtracts 96
                        if (int_c == char_int) {
                            result = result + c;
                        }
                    }
                }

                cout << result << endl;

                display_dehash(node->right);
            }
        }

        // displays chain
        void display_chain (string hash_value) {
            int int_hash_value = stoi(hash_value); // converts string to integer
            node *head;
            head = search(root, int_hash_value); // finds first occurance of hash value
            node *temporary_ptr = head;
            while(temporary_ptr != nullptr){
                cout << temporary_ptr->value << " ";
                temporary_ptr = temporary_ptr -> next;
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

        // displays tree in order
        void in_order(node *node) const {
            if (node != nullptr) {
                in_order(node->left);
                cout << node->value << " ";
                in_order(node->right);
            }
        }
};