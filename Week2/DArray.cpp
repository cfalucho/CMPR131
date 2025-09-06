/*
    Christian Falucho
    CMPR 131 - Fall 2025
    Sept 1, 2025
    Homework #1 
    Collaboration: None
*/
#include <iostream>
#include "DArray.h"
using namespace std;

// Default Constructor
DArray::DArray(/* args */){
    capacity = 50;
    a = new int[capacity]();
    if (a)
    {
        cout << "Memory allocation successful.\n"; 
    }
    else{
        cout << "Error: memory allocation failed.\n";
    }
}

// Overloaded Constructor
DArray::DArray(int newCapacity){
    capacity = newCapacity;
    a = new int[capacity]();
    if (a)
    {
        cout << "Memory allocation successful.\n\n";
    }
    else{
        cout << "Error: memory allocation failed.\n\n";
    }
}
void DArray::addElement(int newElement){
    a[numOfElements++] = newElement;
}
int DArray::getNumOfElements() const{
    return numOfElements;
}
int DArray::getCapacity() const{
    return capacity;
}
DArray::~DArray(){
    delete [] a;
    a = nullptr;
};
void DArray::replaceElementAt(int newElement, int idx) const{
    a[idx] = newElement;
}
bool DArray::compareArrays(const DArray& otherArray) const{    
    if (numOfElements != otherArray.numOfElements)
    {
        return false;
    }   
    else{
        for (int i = 0; i < numOfElements; i++)
        {
            if (a[i] != otherArray.a[i])
            {
                return false;
            }
        }
    }
    return true;
}
bool DArray::isSorted() const{
    for (int asce = 0, desc = 1; asce < numOfElements - 1; asce++, desc++)
    {
        if (a[asce] <= a[asce + 1] || a[numOfElements - 1 - desc] <= a[numOfElements - 1 - asce])
        {
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
DArray::DArray(const DArray& otherArray){
    capacity = otherArray.capacity;
    numOfElements = otherArray.numOfElements;
    a = new int[capacity];

    for (int i = 0; i < numOfElements; i++)
    {
        a[i] = otherArray.a[i];
    }
}
DArray& DArray::operator=(const DArray& rightSide){
    delete [] a;
    capacity = rightSide.capacity;
    numOfElements = rightSide.numOfElements;
    a = new int[capacity];

    for (int i = 0; i < numOfElements; i++)
    {
        a[i] = rightSide.a[i];
    }
    return *this;
}
ostream& operator<<(ostream& out, const DArray& myArray){
    out << "[";
    for (int i = 0; i < myArray.numOfElements; i++)
    {
        out << myArray.a[i];
        if (i != myArray.numOfElements - 1)
        {
            out << ",";
        }
    }
    out << "]\n";  
    return out;
}
int DArray::findElement(const int& key){
    for (int index = 0; index < numOfElements; index++)
    {
        if (a[index] == key)
        {
            return index;
        }
    }   
    return -1;
}
DArray& DArray::operator+=(const DArray& right){
    for (int i = 0; i < right.numOfElements; i++)
    {
        a[i] += right.a[i];
    }
    return *this;
}



