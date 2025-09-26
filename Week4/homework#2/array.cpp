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
void resize(string*&);
bool isMemAllocSucc(string*&);
bool isCartEmpty();
int itemFound(string*&, string);
double memoryUsage();


int capacity = 5;             // initialize size of 5
int num_of_elements = 0;

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

    addItem(ptr, "Mango");

  
    listItems(ptr);

   
} 



void addItem(string*& ptr, string item){
    const double PERCENT_100 =  100;
    const double PERCENT_50  =  0.5 * 100;

    // Check the usage of memory
    double memory = memoryUsage();
   
    // cannot add item. capacity is full.
    if(memory == PERCENT_100){
        return;
    }
    // memory more than half
    // resizing memory to increase capacity
    else if (PERCENT_50 <= memory && memory < PERCENT_100){
        resize(ptr);
        ptr[num_of_elements++] = item;
        return;
    }
    else{
        ptr[num_of_elements++] = item;
        return;
    }
}

int getNumOfItems(){
    return num_of_elements;
}

void removeItem(string*& ptr, string item){
    int first_element = 0;
    int last_element = num_of_elements - 1;
    int item_location = 0;

    // Call function to check if cart is empty
    if (isCartEmpty()){
        return;
    }
    
    // If cart is not empty
    // Return the location of the item to delete in the array 
    // and reallocate the elements to a new array
    item_location = itemFound(ptr, item);
    if (first_element <= item_location && item_location <= last_element){
        realloc(ptr, item_location);
        num_of_elements--;
        return;
    }
    else{
        cout << item << " not found.\n";
        return;
    }
}

int itemFound(string*& ptr, string item){
    int item_location = -1;

    for (int index = 0; index < num_of_elements; index++){
        if (item == ptr[index]){
            item_location = index;
            cout << item << " found in index " << item_location << "\n";
            return item_location;
        }
    }
    return item_location;
}

void resize(string*& ptr){
    const int DOUBLE = 2;
    int new_capacity = capacity * DOUBLE;            // Capacity doubles
    string* new_arr = new string[new_capacity];       // Create new pointer array on the heap

    if (isMemAllocSucc(new_arr)){
        // copy elements from old array to new array
        for (int index = 0; index < num_of_elements; index++){
            new_arr[index] = ptr[index];
        }
        delete[] ptr;
        ptr = new_arr;
        capacity = new_capacity;
        return;
    }
    else{
        cout << "No new memory created.\n";  
        return; 
    }
}

void listItems(string* ptr){
    for (int index = 0; index < capacity; index++){
        cout << index << ": " << ptr[index] << "\n";
    }
    cout << "\n"
         << "# of Elems: " << num_of_elements 
         << "\t" << "Capacity: " << capacity 
         << "\t" << "Memory usage: " << memoryUsage() << "%"
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

double memoryUsage(){
    double memory_usage = (static_cast<double>(num_of_elements) / capacity) * 100;
    return memory_usage;
}

bool isCartEmpty(){
    // Check if cart is empty
    if(num_of_elements == 0){
        cout << "Cart is empty.\n";
        return true;
    }else{
        return false;
    }
}

void clearCart(string*& ptr){
    cout << "Emptying the items in the cart.\n";
    num_of_elements = 0;
    delete[] ptr;
}

void realloc(string*& ptr, int delete_item){
    int index_begins = 0;                           // First element of the array
    int index_after = delete_item + 1;              // Element after the item to delete
    string* new_arr = new string[capacity];         // Create new pointer array on heap

    cout << "Moving all elements to a new array pointer except"
         << " the item to delete.\n";

    // Copy first element to itemToDelete - 1
    for (; index_begins < delete_item; index_begins++){
        new_arr[index_begins] = ptr[index_begins];
    }

    // Copy element after the itemToDelete to last element
    for (; index_after < num_of_elements; index_after++){
        new_arr[index_after - 1] = ptr[index_after];
    }
    delete [] ptr;
    ptr = new_arr;
    return;
}
