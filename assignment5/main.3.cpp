#include <iostream>
#include <random>
#include "LinkedQueue.3.h"

using namespace std;

int random(){
    int max_num = 10;
    int random_value = rand() % max_num;
    return random_value;
}

int main() {
    LinkedQueue *my_queue = new LinkedQueue();

    srand(time(0));

    for (int i=1; i<=10; i++){
        my_queue->enqueue(random(),1);
    }

    my_queue->update_indices();
    cout << "------Enqueueing 10 nodes with random values from 0 to 9------" << endl;
    my_queue->display();
    
    my_queue->sort();
    cout << "------Sorting linked queue using bubble sort------" << endl;
    my_queue->display();

    cout << "------Searching for 5------" << endl;
    my_queue->search(5);

    cout << "------Searching for 11------" << endl;
    my_queue->search(11);

    cout << "------Searching for -1------" << endl;
    my_queue->search(-1);

    return 0;
};