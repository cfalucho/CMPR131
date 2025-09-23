#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void addItem(string*&, string);
void removeItem(string*, string);
int getNumOfItems();
bool isHalfFull();
void resizeArr(string*&);
void listItems(string*);
bool checkMemAlloc(string*&);

int capacity = 5;             // initialize size of 5
int numOfElements = 0;

int main(){
    
    string* ptr = new string[capacity];
    
    addItem(ptr, "Watermelon");
    addItem(ptr, "Watermelon");
    addItem(ptr, "Watermelon");
    addItem(ptr, "Watermelon");
    addItem(ptr, "Watermelon");

   
  


    listItems(ptr);
} 


void addItem(string*& ptr, string item){
    // Check if capacity is full
    // if (numOfElements == capacity){
    //     cout << "Cannont add item. Capacity is full.";
    //     exit(EXIT_SUCCESS);
    // }
    
    if(isHalfFull()){
        resizeArr(ptr);
    }
    ptr[numOfElements++] = item;
}

int getNumOfItems(int numOfElements){
    return numOfElements;
}

bool isHalfFull(){
     bool isHalfFull       = false;
    
    if (numOfElements == capacity /2 ){
        isHalfFull = true;
    }
    return isHalfFull;
}

void resizeArr(string*& ptr){
    int newCapacity = capacity * 2;
    // Create new array on the heap
    string* newArr = new string[newCapacity];

    if (checkMemAlloc(newArr)){
        // copy old array elements to new array
        for (int i = 0; i < numOfElements; i++){
            newArr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newArr;
        capacity = newCapacity;

    }
    else{
        cout << "No new array created.\n";
   
    }
}

void listItems(string* ptr){
    for (int i = 0; i < capacity; i++)
    {
        cout << i << ": " << ptr[i] << "\n";
    }
    cout << "\n";
    cout << "# of Elems: " << numOfElements 
         << "\t\t" << "Capacity: " << capacity << "\n";
}   

bool checkMemAlloc(string*& ptr){
    if(ptr){
        cout << "Memory allocation on heap successful.\n";
        return true;
    }else{
        cout << "Failed memory allocation.\n";
        return false;
    }
}
