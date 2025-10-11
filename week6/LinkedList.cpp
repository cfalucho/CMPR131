
/*
    Christian Falucho
    CMPR 131 - Fall 2025
    Sept 28, 2025
    In-class exercise
    Collaboration: None
*/
#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){ 
	first = nullptr;
	last = nullptr;
	noe = 0;
}

LinkedList::LinkedList(const LinkedList& otherList){
    Node* temp;       // Create new node
    Node* currPtr;    // Traverse the list
    
    cout << "\nPerforming Copy Constructor...\n";
    
    // set the first nodes to null pointer
    first = nullptr;
    last = nullptr;
    noe = 0;
  
   
    currPtr = otherList.first;        // Point the otherList's first to currPtr;
    noe = otherList.noe;              // copy otherList's noe
    first = new Node;                 // create new first new and copy otherList's info
    first->data = currPtr->data;
    first->next = currPtr->next;

    last = first;                     // point last to first
    currPtr = currPtr->next;          // maker currPtr point to next node

    // copy all the other nodes
    while (currPtr != nullptr){
        temp = new Node;
        temp->data = currPtr->data;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
        currPtr = currPtr->next;
    }
    
    cout << "Copy Constructor completed.\n";
}

LinkedList& LinkedList::operator=(const LinkedList& RHS){
    cout << "\nPerforming Overloaded Assignment Operator...\n";

    Node* temp;       // Create new node
    Node* currPtr;    // Traverse the list

    if (this != &RHS){
        currPtr = RHS.first;              // Point the otherList's first to currPtr;
        noe = RHS.noe;                    // copy otherList's noe
        first = new Node;                 // create new first new and copy otherList's info
        first->data = currPtr->data;
        first->next = currPtr->next;

        last = first;                     // point last to first
        currPtr = currPtr->next;          // maker currPtr point to next node

        // copy all the other nodes
        while (currPtr != nullptr){
            temp = new Node;
            temp->data = currPtr->data;
            temp->next = nullptr;
            last->next = temp;
            last = temp;
            currPtr = currPtr->next;
        }        
    }
    return *this;
}

void LinkedList::add(int newData){
	Node* temp = new Node;	        // new node
    if (temp){ 
        // Allocation is successful{
        cout << "Memory allocation is successful.\n";
	}
	else{
		cout << "ERROR: ALLOCATION FAILED\n";
	}

    // if there is no node
    // make temp the first node
    if (first == nullptr){
        temp->data = newData;
        noe++;
        first = temp;
        last = temp;
        temp = nullptr;
    }
    else{
        // assign new data to temp
        // last points to temp
        temp->data = newData;
        noe++;
        last->next = temp;
        last = temp;
        temp = nullptr;
    }
}
void LinkedList::remove(int key)
{
    Node* prevPtr;                   // previous node
    Node* currPtr = first;           // traverse the list

    // check if the value is the first value
    if (currPtr->data == key){
       first = first->next;
       noe--;
       delete currPtr;
       currPtr = first;
    }
   
    // check every node
    while (currPtr != nullptr && currPtr->data != key ){
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
    
    // if currPtr finds the key
    // connect prevNode to currPtr->next
    if (currPtr){
        prevPtr->next = currPtr->next;
        noe--;
        delete currPtr;
    }

}
bool LinkedList::search(int key) const
{
    Node* nodePtr = first;

    // check if its the first node
    if (first->data == key){
        cout << "key is the first node\n";
        return true;
    }

    // check if it's the last node
    if (last->data == key){
        cout << "key is the last node\n";
        return true;
    }

    // check each node not equal to the data 
    while (nodePtr != nullptr && nodePtr->data != key){
        nodePtr = nodePtr->next;
    }

    // if node true, display memory location of where key is
    if (nodePtr){
        cout << "key found in " << &nodePtr->data << "\n";
        return true;
    }
	return false;
}
void LinkedList::display() const
{
	Node* curr = first;           // traverse the list

    cout << "------------------------------------------\n";
    cout << "Data \t | Next node memory location\n" ;
    cout << "------------------------------------------\n";
    while (curr){
        cout << curr->data << "\t | " << curr->next << "\n";
        curr = curr->next;
    }
    cout << "\n------------------------------------------\n";
    cout << "# of elements: " << noe << "\n";
    cout << "------------------------------------------\n";
    cout << "\n";

}
void LinkedList::destroyList(){
    Node* curr = first;         // point currPtr to first node
	while (curr){
        first = first->next;
        delete curr;
        curr = first;
    }
}

LinkedList::~LinkedList(){  
    destroyList();
    noe = 0;
    first = nullptr;
    last = nullptr;
}