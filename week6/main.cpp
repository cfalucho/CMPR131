#include<iostream>
#include"LinkedList.h"
using namespace std;

int main()
{

	LinkedList l1;
	LinkedList l3;
	
	l1.add(15);
	l1.add(40);
	l1.add(100);
	l1.add(23);
	l1.add(26);
	l1.add(73);
	l1.add(22);
	l1.add(55);
    cout << "\n------------------------------------------\n";
	// l1.display();

	LinkedList l2(l1);
	cout << "\nDisplaying l2 linkedlist...\n"; 
	l2.display();

	l3.add(1);
	l3.add(2);
	l3.add(3);
	l3.add(4);
	l3.add(5);

    cout << "\n------------------------------------------\n";
	l1 = l3;
	l1.display();

	return 0;
}