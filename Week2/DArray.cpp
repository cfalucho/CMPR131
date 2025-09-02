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
    int numOfElements = otherArray.numOfElements;
    return (a[0] == otherArray.a[0] &&
            this->numOfElements == numOfElements);
}
bool DArray::isSorted() const{
    int valueSorted = 0;
    for (int asce = 0, desc = 1; asce < numOfElements - 1; asce++, desc++)
    {
        if (a[asce] <= a[asce + 1] && a[numOfElements - 1] - desc <= a[numOfElements - 1] - asce)
        {
            valueSorted += 1;
        }
        else{
            return false;
        }
    }
    // Checks if all values sorted equals number of elements
    // in the array
    if (valueSorted == numOfElements - 1)
    {
        return true;
    }
    return false;
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
    for (int i = 0; i < myArray.numOfElements; i++)
    {
        out << myArray.a[i] << " ";
    }
    out << "\n";
    // out << "Capacity: " << myArray.capacity << "\n";
    // out << "# of elements: " << myArray.numOfElements << "\n";
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



