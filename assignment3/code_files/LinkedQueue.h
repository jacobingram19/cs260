#include "node.h";

using std::runtime_error;

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

        // enqueue
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

        // dequeue
        // attempting to change heads values to the second nodes values
        int dequeue() {
            if (head != nullptr){
                if (head->next != nullptr){
                    static int original_head_val = head->value;
                    head->value = head->next->value;
                    head->next = head->next->next;
                    return original_head_val;
                } else {
                    head = nullptr;
                    return 0;
                }
            } else {
                return -1;
            }
        }
};
