/*
    Christian Falucho
    CMPR 131 - Fall 2025
    Sept 1, 2025
    Homework #1 
    Collaboration: None
*/
#include <iostream>
#include <iomanip>
#include "DArray.h"
using namespace std;

int main(){
    // ==================================================
    //  DArray() and DArray(int)
    //  
    //  Declaring object arrays
    // ==================================================
    cout << "==================================================\n"
         << "Declaring object arrays (array1 & array2) using Default Constructor and "
         << "Overloaded Constructor.\n\n";

    DArray array1;
    DArray array2(20);
    
    cout << "==================================================\n\n\n";

    // ==================================================
    //  addElement() 
    //  
    //  add elements to an object's array
    // ==================================================
    cout << "==================================================\n"
         << "addElement(), getNumOfElements(), getCapacity(): \n\n"
         << "array1 values: ";
    array1.addElement(3);
    array1.addElement(2);
    array1.addElement(1);
    array1.addElement(55);
    array1.addElement(6);
    array1.addElement(23);
    array1.addElement(3);
    array1.addElement(1);
    cout << array1;
    cout << "# of elemnents: " << array1.getNumOfElements() << "\n";
    cout << "Max Capacity : " << array1.getCapacity() << "\n\n";
    
    cout << "array2 values: "<< array2
         << "Adding elements to array2...\n";
    array2.addElement(1);
    array2.addElement(5);
    array2.addElement(83);
    array2.addElement(101);
    array2.addElement(156);
    array2.addElement(212);
    cout << "array2 values: " << array2;
    cout << "==================================================\n\n\n";

    cout << "==================================================\n";
    cout << "Creating new object array called 'array4'. \n\n";
    DArray array4(10);
    array4.addElement(1);
    array4.addElement(2);
    array4.addElement(22);
    array4.addElement(4);
    array4.addElement(5);
    array4.addElement(3);
    array4.addElement(77);
    array4.addElement(232);
    cout << "array4 values: " << array4;
    cout << "==================================================\n\n\n";

    // ==================================================
    //  replaceElementAt() 
    //  
    //  replace element at 'n' index
    // ==================================================
    cout << "==================================================\n";
    cout << "replaceElementAt(): \n\n" 
         << "Replacing the value on index '3' with value '15' in array1. \n\n";
    cout << "array1 values: " << array1 << "\n";
    array1.replaceElementAt(15, 3);

    cout << "array1 values after replacement: " << array1;
    cout << "==================================================\n\n\n";


    // ==================================================
    //  compareArrays() 
    //  
    //  returns true if two arrays have the same elements
    //  in the same order
    // ==================================================
    cout << "==================================================\n"
         << "compareArrays(): \n\n";
    
    cout << "Check if array1 is the same as array2.\n";
    if (array1.compareArrays(array2))
    {
        cout << "array1 is the same as array2.\n";
    }else{
        cout << "array1 is not the same as array2.\n";
    }

    cout << "\n";
    
    cout << "Check if array1 is the same as array4.\n";
    if (array1.compareArrays(array4))
    {
        cout << "array1 is the same as array4.\n";
    }else{
        cout << "array1 is not the same as array4\n";
    }
    cout << "==================================================\n\n\n";


    // ================================================
    //  isSorted()
    //  
    //  Checks if the array is sorted ascending 
    //  and descending order      
    // ================================================ 
    cout << "==================================================\n"
         << "isSorted(): \n\n";
         
    cout << "array1: " << array1 << "\n";
    cout << "array1 is ";
    if (array1.isSorted())
    {
        cout << " sorted\n";
    }else{
        cout << "not sorted\n";
    }

    cout << "\n";
    
    cout << "array2: " << array2 << "\n";
    cout << "array2 is ";
    if (array2.isSorted())
    {
        cout << "sorted\n";
    }else{
        cout << "not sorted\n";
    }
    cout << "==================================================\n\n\n";

    // ================================================
    //  Copy Constructor() and operator=
    //  
    //  Copies an object's pointer array with another object's
    //  pointer array  
    // ================================================ 
    cout << "==================================================\n"
         << "Copy Constructor and operator=: \n\n"
         << "Creating a new object called 'array3' \n\n"
         << "Copying object array1 to object array3.\n";

    DArray array3(array1);  
    cout << "array3 values after Copy Constructor: "
         << array3 << "\n";

    cout << "Using 'operator=' to assign array2 to array3 \n";
    array3.operator=(array2);
    cout << "array3 values: "<< array3;
    cout << "==================================================\n\n\n";
    
    // ================================================
    //  operator<<
    //  
    //  Overload Insertion Operator
    // ================================================ 
    cout << "==================================================\n";
    cout << "operator<<: \n\n";
    cout << "array1 values: ";
    cout << array1 << "\n";
    cout << "array2 values: ";
    cout << array2 << "\n";
    cout << "array3 values: ";
    cout << array3;
    cout << "==================================================\n\n\n";

    // ================================================
    //  findElement()
    //  
    //  search the array for the key
    //  return the index if found, else return -1
    // ================================================ 
    cout << "==================================================\n";
    cout << "findElement(): \n\n"
         << "Searching key in array1: "
         << array1 << "\n";
    
    int searchKey = 2;
    cout << "key: " << searchKey << setw(14) << "index: " << array1.findElement(searchKey) << "\n";
    
    searchKey = 55;
    cout << "key: " << searchKey << setw(13) << "index: " << array1.findElement(searchKey) << "\n";
    
    searchKey = 101;
    cout << "key: " << searchKey << setw(12) << "index: " << array1.findElement(searchKey) << "\n";

    searchKey = 300;
    cout << "==================================================\n\n\n";
    

    // ================================================
    //  operator+=:
    //  
    //  Overload operator +=
    //  Add to total
    // ================================================ 
    cout << "==================================================\n";
    cout << "operator+=: \n\n"
         << "Adding array2 object array with array1 object array \n\n"
         << array1.operator+=(array2) << "\n";

    cout << "Adding array3 object array with array2 object array \n\n"
         << array3.operator+=(array2);
    cout << "==================================================\n\n\n";

    // ================================================
    //  ~DArray():
    //  
    //  Deallocate memory that was dynamically allocated
    //  by the object at runtime
    // ================================================ 
    cout << "==================================================\n";
    cout << "~DArray(): \n\n";

    cout << "Performing ~DArray() on the following arrays...\n"
         << "array1, array2, array3, array4 \n";
    array1.~DArray();
    array2.~DArray();
    array3.~DArray();
    array4.~DArray();

    return 0;
}