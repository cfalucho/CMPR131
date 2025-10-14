#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next = nullptr;
};

class LinkedList{
    private: 
        Node* first;
        Node* last;
        int num_of_elements;
    
    public:
        LinkedList(){
            first = nullptr;
            last = nullptr;
            num_of_elements = 0;
            // Node* temp = new Node;
        }

        void add_node(int value){
            Node* temp = new Node;             // Create a temp node

            // Check if this is the first node
            // If so, make this node the first node
            if (first == nullptr)
            {
                temp->data = value;
                first = temp;
                last = temp;
                num_of_elements++;
                temp = nullptr;
            }
            else{
                temp->data = value;
                last->next = temp;
                last = temp;
                
                num_of_elements++;
                temp = nullptr;
            }
        }

        void delete_node(int value){
            Node* prevPtr;                  // Pointer that follows currPtr
            Node* currPtr = first;          // Traverse the list
            
            if (currPtr->data == value){
                first = currPtr->next;
                delete currPtr;
            }

            // check every node in the middle
            // if the node is not null and does not equal the value to delete
            // continue on
            while (currPtr != nullptr && currPtr->data != value){
                prevPtr = currPtr;
                currPtr = currPtr->next;
            }
            
            // Once we find the value to delete
            // connect previous node to the next node
            if (currPtr){
                cout << "Deleting node..: " << currPtr << "\n";
                prevPtr->next = currPtr->next;
                delete currPtr;
            }
        }

        void destroy_list(){
            cout << "Destroying the list..\n";
            Node* currPtr = first;

            while (currPtr){
                first = first->next;
                delete currPtr;
                currPtr = first;
                last = nullptr;
            }
            
        }

        void display_linkedlist(){
            Node* nodePtr = first;

            cout << "first points to: " << first << "\n";
            cout << "last points to: " << last << "\n";
            while (nodePtr != nullptr){
              cout << "---------------------\n";
              cout << "Node memory address: " << nodePtr << "\n";
              cout << "---------------------\n";
              cout << "data: " << nodePtr->data <<  "\n";
              cout << "next: " << nodePtr->next << "\n";
              cout << "---------------------\n";
              nodePtr = nodePtr->next;
            }
        }

};

int main(){
    LinkedList l1;

    l1.add_node(23);
    l1.add_node(44);
    // l1.add_node(55);
    // l1.add_node(12);

    l1.display_linkedlist();

    // l1.delete_node(55);

    // l1.display_linkedlist();


    // l1.destroy_list();

    // l1.display_linkedlist();



}

