/*
    Christian Falucho
    CMPR 131 - Fall 2025
    Sept 1, 2025
    Homework #1 
    Collaboration: None
*/
#include <iostream>
#pragma once
#include "DArray.h"
using namespace std;

// Default Constructor
DArray::DArray(){
    capacity = 50;
    a = new int[capacity]();
    isMemAllocSuccess(a);
}

// Overloaded Constructor
DArray::DArray(int newCapacity){
    capacity = newCapacity;
    a = new int[capacity]();
    cout << "Constructor executed with capacity = " << newCapacity << "\n";

    isMemAllocSuccess(a);
}
void DArray::addElement(int newElement){
    if (numOfElements != capacity){
        a[numOfElements++] = newElement;
    }
    else{
        cout << "Cannot add additional elements. Capacity full.\n";
    }
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
    if (idx > capacity || idx < 0)
    {
        cout << "index " << idx << " goes out of array's capacity. Please try again.";
    }
    else{
        a[idx] = newElement;
    }
    
}
bool DArray::compareArrays(const DArray& otherArray) const{    
    if (numOfElements != otherArray.numOfElements){
        return false;
    }   
    else{
        for (int index = 0; index < numOfElements; index++){
            if (a[index] != otherArray.a[index]){
                return false;
            }
        }
    }
    return true;
}
bool DArray::isSorted() const{
    for (int front = 0, back = 1; front < numOfElements - 1; front++, back++){
        if (a[front] <= a[front + 1] || 
            a[numOfElements - 1 - back] <= a[numOfElements - 1 - front]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
// Copy Constructor
// Used when a new object is created
// and need to copy from another object
DArray::DArray(const DArray& otherArray){
    cout << "Copy constructor executed\n";
    capacity = otherArray.capacity;
    numOfElements = otherArray.numOfElements;
    a = new int[capacity];

    for (int index = 0; index < numOfElements; index++){
        a[index] = otherArray.a[index];
    }
}

// Move Constructor
// Used to move an object to a newly created object
// without having to use a loop to move all the elements
DArray::DArray(DArray&& otherArray){
    cout << "Move constructor executed\n";
    capacity = otherArray.capacity;
    numOfElements = otherArray.numOfElements;
    a = otherArray.a;
    otherArray.a = nullptr;
}


// Overloaded assignment operator
// Used when object are already created
// and an object needs to be assigned(copied) to another object
DArray& DArray::operator=(const DArray& rightSide){
    cout << "Copy assignment operator executed\n";
    if (a != rightSide.a){
        delete [] a;
        capacity = rightSide.capacity;
        numOfElements = rightSide.numOfElements;
        a = new int[capacity];
    
        for (int index = 0; index < numOfElements; index++){
            a[index] = rightSide.a[index];
        }       
    }
    return *this;
}



// // Move assignment
DArray& DArray::operator=(DArray&& right){
    cout << "Move assignment operator executed\n";
    if (this != &right){
        delete [] a;
        capacity = right.capacity;
        numOfElements = right.numOfElements;
        a = right.a;
        right.a = nullptr;
    }
    return *this;
}


ostream& operator<<(ostream& out, const DArray& myArray){
    out << "[";
    for (int index = 0; index < myArray.numOfElements; index++){
        out << myArray.a[index];
        if (index != myArray.numOfElements - 1)
        {
            out << ", ";
        }
    }
    out << "]\n";  
    return out;
}
int DArray::findElement(const int& key){
    for (int index = 0; index < numOfElements; index++){
        if (a[index] == key){
            return index;
        }
    }   
    return 0;
}
DArray& DArray::operator+=(const DArray& right){
    for (int index = 0; index < right.numOfElements; index++){
        a[index] += right.a[index];
    }
    return *this;
}


void DArray::isMemAllocSuccess(int* a){
    if (a){
        cout << "Memory allocation successful.\n\n";
    }
    else{
        cout << "Error: memory allocation failed.\n\n";
    }
}

int& DArray::operator[](int i){
    return a[i];
};
