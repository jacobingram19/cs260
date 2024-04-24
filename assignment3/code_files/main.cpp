#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main() {
    LinkedQueue *my_queue = new LinkedQueue();

    my_queue->enqueue(8);
    my_queue->enqueue(2);
    my_queue->enqueue(3);
    cout << "------Enqueueing 3 nodes. With values 8, 2, 3 respectively------" << endl;
    my_queue->display();

    my_queue->dequeue();
    cout << "\n------Dequeueing the first node------" << endl;
    my_queue->display();

    my_queue->enqueue(5);
    cout << "\n------Enqueueing node with value 5------" << endl;
    my_queue->display();

    my_queue->dequeue();
    my_queue->dequeue();
    my_queue->dequeue();
    cout << "\n------Dequeueing all nodes------" << endl;
    my_queue->display();

    return 0;
};