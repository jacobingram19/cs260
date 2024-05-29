#include <iostream>
#include "hash.h"

using namespace std;

int main() {
    HashTable htable(10);

    cout << "------Displaying empty table------" << endl;
    cout << "Hash Table Contents: " << htable.toString() << endl;

    cout << "------Inserting 'Margo'------" << endl;
    htable.insert("Margo");

    cout << "------Displaying table------" << endl;
    cout << "Hash Table Contents: " << htable.toString() << endl;

    cout << "------Inserting 'Ma'------" << endl;
    htable.insert("Ma");

    cout << "------Inserting 'aM'------" << endl;
    htable.insert("aM");

    cout << "------Displaying table------" << endl;
    cout << "Hash Table Contents: " << htable.toString() << endl;

    return 0;
};