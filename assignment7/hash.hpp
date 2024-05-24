#include <String>
#include <sstream>


using std::string;
using std::stringstream;

class HashTable {
    public:
        HashTable(int initialCapacity);
        int hash(string input_string);
        bool insert(string input_string);
        bool contains(string input_string);
        string toString();
    
    private:
        int capacity = 10;
        int size = 0;
        string *storage = nullptr;

        bool resize();
};