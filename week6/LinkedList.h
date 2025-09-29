#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


struct Node
{
	int data;
	Node* next = nullptr;

};

class LinkedList
{
public:

	LinkedList();                                   // default constructor
	LinkedList(const LinkedList&);                  // Copy constructor
	LinkedList& operator=(const LinkedList& RHS);   // Overloaded Assignment Operator

	void add(int newData);
	void remove(int key);
	bool search(int key) const;
	void display() const;
	void destroyList();

	~LinkedList();

private:
	Node* first;
	Node* last;
	int noe;


};


#endif

