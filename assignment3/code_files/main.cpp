#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main() {
    LinkedQueue *my_queue = new LinkedQueue();

    my_queue->enqueue(8);
    cout << "my_queue->dequeue(): " << my_queue->dequeue() << endl;

    my_queue->enqueue(2);
    cout << "my_queue->dequeue(): " << my_queue->dequeue() << endl;

    my_queue->enqueue(3);
    cout << "my_queue->dequeue(): " << my_queue->dequeue() << endl;

    return 0;
};