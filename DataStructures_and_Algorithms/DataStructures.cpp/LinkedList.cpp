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

        void display_linkedlist(){
            Node* nodePtr = first;

            while (nodePtr){
              cout << "value: " << nodePtr->data <<  "\n";
              nodePtr = nodePtr->next;
            }
            
        }

};

int main(){
    LinkedList l1;

    l1.add_node(23);
    l1.add_node(44);
    l1.add_node(55);

    l1.display_linkedlist();


}

