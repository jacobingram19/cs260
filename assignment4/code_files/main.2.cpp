#include <iostream>
#include "LinkedQueue.2.h"

using namespace std;

int main() {
    LinkedQueue *my_queue = new LinkedQueue();

    my_queue->enqueue(8,4);
    my_queue->enqueue(4,10);
    my_queue->enqueue(3,2);
    my_queue->update_indices();
    cout << "------Enqueueing 3 nodes. With values 8, 4, 3 respectively------" << endl;
    my_queue->display();

    cout << "------Peeking index 2------" << endl;
    my_queue->peek(2);

    my_queue->dequeue();
    my_queue->update_indices();
    cout << "\n------Dequeueing the first node------" << endl;
    my_queue->display();

    my_queue->enqueue(5,3);
    cout << "\n------Enqueueing node with value 5------" << endl;
    my_queue->display();

    my_queue->insert(9,2);
    cout << "\n------Inserting node with value 9 at index 2------" << endl;
    my_queue->display();

    my_queue->insert(6,4);
    cout << "\n------Inserting node with value 6 at index 4------" << endl;
    my_queue->display();

    cout << "\n------Removing node with index 3------" << endl;
    my_queue->remove(3);
    my_queue->display();

    return 0;
};