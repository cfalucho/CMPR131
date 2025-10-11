#include <iostream>
#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

struct Node{
    string data;
    Node* nextPtr = nullptr;
};

class LinkedList{
    public:

    private:
        
        Node* first;
        Node* last;
        int num_of_elements;
        
};

#endif
