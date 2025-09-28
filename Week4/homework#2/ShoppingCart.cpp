#include <iostream>
#include <fstream>
#include "ShoppingCart.h"

using namespace std;
ShoppingCart::ShoppingCart(){
    capacity = 5;
    num_of_elements = 0;
    ptr = new string[capacity];
    // Call function to check if memory allocated successfully
    isMemAllocSuccessful(ptr);
}
void ShoppingCart::addItem(string item){
    const double PERCENT_100 = 100;
    const double PERCENT_50  = 0.5 * 100;

    // check the usage of memory
    double memory = memoryUsage();
    
    // if memory is 100%, display to user why
    if (memory == PERCENT_100){
        cout << "Capacity is full. Cannot add item.\n";
        return;
    }
    // memory more than half
    // resizing memory to increase capacity
    else if (PERCENT_50 <= memory && memory < PERCENT_100){
        resize();
        ptr[num_of_elements++] = item;
        return;
    }
    else{
        ptr[num_of_elements++] = item;
        return;
    }
}
void ShoppingCart::removeItem(string item) {
    int first_element = 0;
    int last_element = num_of_elements - 1;
    int item_location = 0;

    // Call function to check if cart is empty
    if (isCartEmpty()){
        cout << "Cart is empty.\n";
        return;
    }
    
    // If cart is not empty
    // Check if item is in the list, then return the index location
    // and reallocate the elements to a new array
    item_location = itemFound(item);
    if (first_element <= item_location && item_location < last_element){
        realloc(item_location);
        num_of_elements--;
        return;
    }
    else if (item_location == last_element){
        num_of_elements--;
        return;
    }
    
    else{
        cout << item << " not found.\n";
        return;
    }
}

int ShoppingCart::itemFound(string item) const{
    int item_location = -1;

    for (int index = 0; index < num_of_elements; index++){
        if (item == ptr[index]){
            item_location = index;
            cout << item << " found and is going to be removed.\n";
            return item_location;
        }
    }
    return item_location;
}

// Moving all elements to a new 8 
// except the item to delete.
void ShoppingCart::realloc(int delete_item){
    int index_begins = 0;                           // First element of the array
    int index_after = delete_item + 1;              // Element after the item to delete
    string* new_arr = new string[capacity];         // Create new pointer array on heap

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
}


bool ShoppingCart::isCartEmpty() const{
    // Check if cart is empty
    if(num_of_elements == 0){
        cout << "Cart is empty.\n";
        return true;
    }else{
        return false;
    }
}

void ShoppingCart::listItems() const{
    cout << "\n====================================================================\n"
         << "| No. Of Elements: " << num_of_elements << "  |" 
         << "  Capacity: " << capacity << "  |"
         << "  Memory Usage: " << memoryUsage() << "%     |"
         << "\n====================================================================\n\n";
    
        for (int index = 0; index < capacity; index++){
        cout << index << ": " << ptr[index] << "\n";
    }
}

int ShoppingCart::getCapacity() const{
    return capacity;
}
int ShoppingCart::getNumOfItems() const{
    return num_of_elements;
}
void ShoppingCart::clearCart(){
    char user_input = 'n';
    cout << "Are you sure you want to clear the cart? (Y/N) ";
    cin >> user_input;
    
    if (toupper(user_input) == 'Y')
    {
        cout << "\nEmptying the items in the cart.\n";
        num_of_elements = 0;
        delete[] ptr;
    }else{
        return;
    }
    return;
}
void ShoppingCart::saveCart() const{
    fstream save_file;
    string filename = "Cart.txt";
    save_file.open(filename, ios::out);

    if (isCartEmpty()) {
        return;
    }

    cout << "Saving shopping cart list to a file.\n";
    save_file << "  Item Name \t\t" << "# of items: " << num_of_elements
              << "\n-------------------------------------\n";
    for (int index = 0; index < num_of_elements; index++){
        save_file << index + 1 << ". " << ptr[index] << "\n";
    }
    cout << "Items has been saved to " << filename << "\n"; 
}

ostream& operator<<(ostream& out, const ShoppingCart& cart){
    cout << "=========================================\n";
    cout << "|  Shopping Cart   |  # of items: " << cart.num_of_elements << "    |\n";
    cout << "=========================================\n";
    for (int index = 0; index < cart.num_of_elements; index++){
        cout << index + 1 << ". " << cart.ptr[index] << "\n";
    }
    return out;
}


double ShoppingCart::memoryUsage() const{
    double memory_usage = (static_cast<double>(num_of_elements) / capacity) * 100;
    return memory_usage;
}

void ShoppingCart::resize(){
    const int DOUBLE = 2;
    int new_capacity = capacity * DOUBLE;             // Capacity doubles
    string* new_ptr = new string[new_capacity];       // Create new pointer array on the heap

    if (isMemAllocSuccessful(new_ptr)){
        // copy elements from old array to new array
        for (int index = 0; index < num_of_elements; index++){
            new_ptr[index] = ptr[index];
        }
        delete[] ptr;
        ptr = new_ptr;
        capacity = new_capacity;
        return;
    }
    else{
        return; 
    }
}

bool ShoppingCart::isMemAllocSuccessful(string*& ptr) const{
    if(ptr){
        cout << "Memory allocation successful.\n\n";
        return true;
    }else{
        cout << "Failed memory allocation.\n\n";
        return false;
    }
}
