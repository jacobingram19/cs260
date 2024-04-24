#include <iostream>

using namespace std;

#include "node.h";

class LinkedQueue {
    private:
        // variables
        node *head;
        node *tail;

    public:
        // construct linked queue
        LinkedQueue() {
            head = nullptr;
            tail = nullptr;
        }

        // enqueue node to end of queue
        void enqueue(int new_value) { 
            node *temporary_ptr = new node; // creates a pointer to the new node
            temporary_ptr -> value = new_value;
            temporary_ptr -> next = nullptr; // the node at the end of queue must point to nullptr

            if (tail == nullptr) { // if the queue is empty then the tail is going to be the same node as the head
                head = tail = temporary_ptr;
            } else { // if the queue is not empty then update the previous tails "next"
                tail->next = temporary_ptr;
                tail = temporary_ptr;
            }

        }

        // dequeue first node in queue
        int dequeue() {
            node *temporary_ptr = head; // creates a temporary pointer to the current head of queue

            if (temporary_ptr != nullptr){ // if the queue is not empty
                head=head->next; // make the head pointer point to the second node in the queue
                return temporary_ptr->value; // return the value of the original leading node
                delete temporary_ptr; // delete original head
            } else {
                head = nullptr; // reconstruct the queue if it is empty
                tail = nullptr;
                cout << "The queue is already empty!" << endl;
                return -1;
            }
        }

        // display nodes in queue
        void display () {
            int count = 1;
            node *temporary_ptr = head;
            while(temporary_ptr != nullptr){
                cout << "NODE " << count << endl;
                cout << "Value: " << temporary_ptr->value << endl;
                cout << "Address: " << temporary_ptr << endl;
                if (temporary_ptr->next != nullptr){
                    cout << "Next address: " << temporary_ptr->next << "\n" << endl;
                } else {
                    cout << "Next address: nullptr" << "\n" << endl;
                }
                temporary_ptr = temporary_ptr -> next;
                count = count + 1;
            }
        }


};