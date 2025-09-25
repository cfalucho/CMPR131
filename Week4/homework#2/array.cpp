#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void addItem(string*&, string);
void removeItem(string*&, string);
void listItems(string*);
int getNumOfItems();
void clearCart(string*&);
// void saveCart();

void realloc(string*&, int);
void resizeMemory(string*&);
bool isMemAllocSucc(string*&);
double isMemoryUsage();
int itemFound(string*&, string);


int capacity = 5;             // initialize size of 5
int numOfElements = 0;

int main(){
    
    string* ptr = new string[capacity];

    
    
    addItem(ptr, "Watermelon");
    listItems(ptr);

    addItem(ptr, "Green Apple");
    listItems(ptr);

    addItem(ptr, "Oranges");
    listItems(ptr);

    addItem(ptr, "Cherry");
    listItems(ptr);

    addItem(ptr, "Strawberry");
    listItems(ptr);

    addItem(ptr, "Bananas");
    listItems(ptr);

    addItem(ptr, "Raspberry");
    listItems(ptr);


    // cout << itemFound(ptr, "Oranges") << "\n";
    // removeItem(ptr, "cherry");
    removeItem(ptr, "Cherry");
    removeItem(ptr, "Watermelon");
    removeItem(ptr, "Raspberry");
    removeItem(ptr, "Green Apple");
    removeItem(ptr, "Oranges");
    removeItem(ptr, "Strawberry");
    removeItem(ptr, "Bananas");
    removeItem(ptr, "Bananas");
    removeItem(ptr, "cherry");
  
    listItems(ptr);

} 



void addItem(string*& ptr, string item){
    // Check the usage of memory
    double memory = isMemoryUsage();
   
    if(memory == 100){
        cout << "Cannot add item. Capacity is full.\n";
        EXIT_FAILURE;
    }
    else if (memory >= 90 && memory < 100){
        cout << "Low memory space.\n";
        ptr[numOfElements++] = item;
        return;
    }
    else if (memory >= 50 && memory < 90 ){
        cout << "Resizing memory to increase capacity...\n";
        resizeMemory(ptr);
        ptr[numOfElements++] = item;
        return;
    }
    else{
        ptr[numOfElements++] = item;
        return;
    }
}

int getNumOfItems(){
    return numOfElements;
}

void removeItem(string*& ptr, string item){
    int itemLocation = itemFound(ptr, item);
    int lastElement = numOfElements - 1;

    // Check if cart is empty
    if (numOfElements == 0)
    {
        cout << "Cart is empty.\n";
        return;
    }
    
    if (itemLocation >= 0 && itemLocation <= lastElement)
    {
        realloc(ptr, itemLocation);
        numOfElements--;
    }
    else{
        cout << item << " not found.\n";
    }
}

int itemFound(string*& ptr, string item){
    int itemLocation = 0;

    for (int index = 0; index < numOfElements; index++)
    {
        if (item == ptr[index]){
            itemLocation = index;
            cout << item << " found in index " << itemLocation << "\n";
            return itemLocation;
        }
    }
    return -1;
}

void resizeMemory(string*& ptr){
    int newCapacity = capacity * 2;                 // Capacity doubles
    string* newArr = new string[newCapacity];       // Create new pointer array on the heap

    if (isMemAllocSucc(newArr)){
        // copy old array elements to new array
        for (int i = 0; i < numOfElements; i++){
            newArr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newArr;
        capacity = newCapacity;
    }
    else{
        cout << "No new memory created.\n";   
    }
}

void listItems(string* ptr){
    for (int i = 0; i < capacity; i++){
        cout << i << ": " << ptr[i] << "\n";
    }
    cout << "\n";
    cout << "# of Elems: " << numOfElements 
         << "\t" << "Capacity: " << capacity 
         << "\t" << "Memory usage: " << isMemoryUsage() << "%"
         << "\n\n";
}   

bool isMemAllocSucc(string*& ptr){
    if(ptr){
        cout << "Memory allocation on heap successful.\n";
        return true;
    }else{
        cout << "Failed memory allocation.\n";
        return false;
    }
}

double isMemoryUsage(){
    double isMemoryUsage = (static_cast<double>(numOfElements) / capacity) * 100;
    return isMemoryUsage;
}

void clearCart(string*& ptr){
    cout << "Emptying the items in the cart.\n";
    numOfElements = 0;
    delete[] ptr;
}


void realloc(string*& ptr, int itemToDelete){
    int indexBeforeItem = 0;                            // First element of the array
    int indexAfterItem = itemToDelete + 1;              // Element after the item to delete
    string* newArr = new string[capacity];              // Create new pointer array on heap

    cout << "Moving all elements to a new array pointer except"
         << " the item to delete.\n";

    // Copy first element to itemToDelete - 1
    for (; indexBeforeItem < itemToDelete; indexBeforeItem++){
        newArr[indexBeforeItem] = ptr[indexBeforeItem];
    }

    // Copy element after the itemToDelete to last element
    for (; indexAfterItem < numOfElements; indexAfterItem++){
        newArr[indexAfterItem - 1] = ptr[indexAfterItem];
    }
    delete [] ptr;
    ptr = newArr;
}
