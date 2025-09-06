/*
    Christian Falucho
    CMPR 131 - Fall 2025
    Sept 1, 2025
    Homework #1 
    Collaboration: None
*/
#pragma once
#include <iostream>
using namespace std;

class DArray
{
private:
    /* data */
    int *a = nullptr;
    int capacity = 0;
    int numOfElements = 0;
public:
    DArray(/* args */);
    DArray(int newCapacity);
    void addElement(int newElement);
    int getNumOfElements() const;
    int getCapacity() const;
    ~DArray();
    void replaceElementAt(int newElement, int idx) const;
    bool compareArrays(const DArray& otherArray) const;
    bool isSorted() const;
    DArray(const DArray& otherArray);
    DArray& operator=(const DArray& rightSide);
    friend ostream& operator<<(ostream& out, const DArray& myArray);
    int findElement(const int& key);
    DArray& operator +=(const DArray& right);
};


