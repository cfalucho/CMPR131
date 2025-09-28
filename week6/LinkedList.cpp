
#include "LinkedList.h"

#include<iostream>
using namespace std;

LinkedList::LinkedList()
{ 
	first = nullptr;
	last = nullptr;
	noe = 0;
}


void LinkedList::add(int newData)
{

	Node* temp = new Node;
	if (temp) // Allocation is successful
	{


	}
	else
	{
		cout << "ERROR: ALLOCATION FAILE\n";
	}









}
void LinkedList::remove(int key)
{
	// the ful implemetation goes here

}
bool LinkedList::search(int key) const
{
	// the ful implemetation goes here

	return false;
}
void LinkedList::display() const
{
	// the ful implemetation goes here

}
void LinkedList::destroyList()
{
	// the ful implemetation goes here

}

LinkedList::~LinkedList()
{
	// the ful implemetation goes here

}