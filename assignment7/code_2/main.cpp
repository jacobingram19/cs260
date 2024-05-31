#include <iostream>
#include "hash.h"

using namespace std;

int main() {
    HashTable *ht = new HashTable();
    string dog_hash = ht->hash("dog");
    string hi_hash = ht->hash("hi");
    string bye_hash = ht->hash("bye");
    string zap_hash = ht->hash("zap");
    string at_hash = ht->hash("at");
    string it_hash = ht->hash("it");

    cout << "------Inserting root node with value 41507------" << endl;
    ht->insert(dog_hash);
    cout << "------Displaying table in order------" << endl;
    ht->in_order(ht->get_roots_address());

    cout << "\n------Inserting nodes values: 809, 22505, 260116, 120------" << endl;
    ht->insert(hi_hash);
    ht->insert(bye_hash);
    ht->insert(zap_hash);
    ht->insert(at_hash);
    cout << "------Displaying table in order------" << endl;
    ht->in_order(ht->get_roots_address());

    cout << "\n------Checking if the table contains 'zap'------" << endl;
    bool result = ht->contains(zap_hash);
    if (result == true) {
        cout << "'zap' is in the hash table." << endl;
    } else {
        cout << "'zap' was not found." << endl;
    }

    cout << "------Checking if the table contains 'it'------" << endl;
    bool result2 = ht->contains(it_hash);
    if (result2 == true) {
        cout << "'it' is in the hash table." << endl;
    } else {
        cout << "'it' was not found." << endl;
    }

    cout << "------Dehashing table------" << endl;
    ht->display_dehash(ht->get_roots_address());

    cout << "------Inserting nodes values: 809, 809. This should cause a collision------" << endl;
    ht->insert(hi_hash);
    ht->insert(hi_hash);
    cout << "------Displaying tree in order------" << endl;
    ht->in_order(ht->get_roots_address());
    cout << "\n------Displaying linked list (chain) at node with hash value 809------" << endl;
    ht->display_chain(hi_hash);

    return 0;
};