#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
    int data;
    Node* next = nullptr;
};

class LinkedList{
    public:

    private:
        Node* first;
        Node* last;
        int num_of_elements;
        
};

#endif
