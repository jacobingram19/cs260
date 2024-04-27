#include <iostream>

using namespace std;

#include "node.2.h";

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
        void enqueue(int new_value, int new_index) { 
            node *temp_ptr = new node; // creates a pointer to the new node
            temp_ptr -> value = new_value;
            temp_ptr -> index = new_index;
            temp_ptr -> next = nullptr; // the node at the end of queue must point to nullptr

            if (tail == nullptr) { // if the queue is empty then the tail is going to be the same node as the head
                head = tail = temp_ptr;
            } else { // if the queue is not empty then update the previous tails "next"
                tail->next = temp_ptr;
                tail = temp_ptr;
            }

        }

        // dequeue first node in queue
        int dequeue() {
            node *temp_ptr = head; // creates a temporary pointer to the current head of queue

            if (temp_ptr != nullptr){ // if the queue is not empty
                head=head->next; // make the head pointer point to the second node in the queue
                return temp_ptr->value; // return the value of the original leading node
                delete temp_ptr; // delete original head

            } else {
                head = nullptr; // reconstruct the queue if it is empty
                tail = nullptr;
                cout << "The queue is already empty!" << endl;
                return -1;
            }
        }

        // updates indices of all nodes
        void update_indices(){
            node *temp_ptr = head;
            int count = 1;
            while (temp_ptr != nullptr){
                temp_ptr->index = count; // change current node's index to count
                temp_ptr = temp_ptr->next;
                count = count + 1;
            }
        }

        // display nodes in queue
        void display () {
            int count = 1;
            node *temporary_ptr = head;
            while(temporary_ptr != nullptr){
                cout << "NODE " << count << endl;
                cout << "Value: " << temporary_ptr->value << endl;
                cout << "Index: " << temporary_ptr->index << endl;
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

        // return values of node at index
        int peek(int desired_index){
            node *temp_ptr = head;
            while (temp_ptr != nullptr){
                if(temp_ptr->index == desired_index){ // if current index equals desired index
                    cout << "PEEK VALUE: " << temp_ptr->value << endl;
                    return temp_ptr->value;
                } else {
                    ;
                }
                temp_ptr = temp_ptr -> next;
            }
            if (temp_ptr == nullptr){ // if the desired index does not exist withing queue
                return -1;
            } else {
                ;
            }
        }

        // inserts new node at certain index. All nodes previously at the index or past the index get moved down the queue.
        void insert(int new_value, int new_index){
            // define values for new node
            node *temp_ptr = new node; // creates a pointer to the new node
            temp_ptr->value = new_value;
            temp_ptr->index = new_index;

            node *temp_ptr_2 = head;
            while (temp_ptr_2 != nullptr){ // while loop to set new node's next
                if(temp_ptr_2->index == new_index){ // if current index equals desired index
                    temp_ptr->next= temp_ptr_2;
                } else {
                    ;
                }
                temp_ptr_2 = temp_ptr_2->next;
            }

            // update previous nodes next
            node *temp_ptr_3 = head;
            while (temp_ptr_3 != nullptr){
                if(temp_ptr_3->index == new_index - 1){
                    temp_ptr_3->next= temp_ptr;
                } else {
                    ;
                }
                temp_ptr_3 = temp_ptr_3->next; 
            }

            // update all following nodes positions
            temp_ptr = temp_ptr->next;
            while (temp_ptr != nullptr){
                new_index = new_index + 1;
                temp_ptr->index = new_index;
                temp_ptr = temp_ptr->next;
            }
        }

        int remove(int new_index){
            node *temp_ptr = head;
            for (int i = 1; i < new_index; i = i + 1){ // for loop that creates a pointer to the node to be deleted
                temp_ptr = temp_ptr -> next;
            }

            // update previous node's next
            node *temp_ptr_2 = head;
            while (temp_ptr_2 != nullptr){
                if(temp_ptr_2->index == new_index - 1){
                    temp_ptr_2->next = temp_ptr->next;
                } else {
                    ;
                }
                temp_ptr_2 = temp_ptr_2->next; 
            }

            // update all following nodes indices
            node *temp_ptr_3 = temp_ptr;
            temp_ptr_3 = temp_ptr_3->next;
            while (temp_ptr_3 != nullptr){
                temp_ptr_3->index = new_index;
                new_index = new_index + 1;
                temp_ptr_3 = temp_ptr_3->next;
            }

            return temp_ptr->value;
            delete temp_ptr;

        }
};