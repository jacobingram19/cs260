#include <sstream>
#include "hash.hpp"

using std::stringstream;

// constructor
HashTable::HashTable(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;

    storage = new string[capacity]; // size of string times number of capacity
}

// hash calculates an index
// takes in a string input and outputs an integer index
int HashTable::hash(string input_string){

    int result = 0;
    for (char character : input_string) { // iterates over each character in the string
        result += character; // the 'result' will be the sum of all of the characters
    }

    // modulus will keep the result in the list. Share/spread out the weight of the values
    result %= capacity; // the string 'jacob' would be off of edge of list. J by itself is 10

    return result;
}

// insert function for HashTable
// only inserts the string if the string does not already exist at the hashed index
// returns whether or not the insertion was successful
// duration depends entirely on # of characters in string
bool HashTable::insert(string input_string){
    bool result = false;

    // hash key
    int hash_value = hash(input_string);

    // check if there is a collision
    if (storage[hash_value] != input_string) {
        result = true;
    }

    // place in storage
    storage[hash_value] = input_string;

    // check for resize
    // size = size + 1;
    // if (size >= capacity) {
    //     resize();
    // }

    return result; // if string was put in storage this will return true
}

bool HashTable::contains(string input_string){
    bool result = false;

    // hash
    int hash_value = hash(input_string);

    // check if value there is the same as our value
    if (storage[hash_value] == input_string) {
        result = true;
    }

    return result; // return the result
}


// increase capacity
bool HashTable::resize(){
    // doubles capacity
    int new_capacity = 2*capacity;
    capacity = new_capacity;

    // new array pointer with updated capacity
    string *new_storage = new string[new_capacity];

    // rehash old elements into new array
    stringstream result;
    for (int i = 0; i < capacity ; ++i) { // for each string in my storage
        result << storage[i]; // appends string at index 'i' to result
        if (result.str() != ""){ // if the string is not empty... insert it
            int hash_value = hash(result.str());
            new_storage[hash_value] = result.str();
        }
    }

    storage = new_storage;

    return true; // successfully resized
}

// returns values in hash table as a string
string HashTable::toString() {
    stringstream result; // stream that can manipulate strings

    for (int i = 0; i < capacity ; ++i) { // for each string in my storage
        result << storage[i] << ", "; // result gets inserted at string
    }

    return result.str(); // turns result into a string
}