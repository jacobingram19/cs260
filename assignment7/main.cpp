#include <iostream>
#include "hash.hpp"

using namespace std;

int main() {
    HashTable htable(10);

    cout << "------Displaying empty table------" << endl;
    cout << "Hash Table Contents: " << htable.toString() << endl;

    cout << "------Inserting 'Margo'------" << endl;
    htable.insert("Margo");

    cout << "------Displaying table------" << endl;
    cout << "Hash Table Contents: " << htable.toString() << endl;
    return 0;
}