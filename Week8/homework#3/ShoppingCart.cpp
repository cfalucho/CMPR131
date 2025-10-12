/*
    Christian Falucho
    CMPR 131 - Fall 2025
    October 10, 2025
    Homework #3
    Collaboration: None
*/
#include <iostream>
#include <fstream>
#include "ShoppingCart.h"
#include <iomanip>

using namespace std;
ShoppingCart::ShoppingCart(){
    first = nullptr;
    last = nullptr;
    num_of_elements = 0;
    total_price_for_items = 0;    
}
void ShoppingCart::addItem(string item, double price){
    total_price_for_items += price;
    // Create a node
    Node* temp = new Node;

    isMemAllocSuccessful(temp);

    // Check if there's a first node
    // If not, make the first node
    if (first == nullptr){
        temp->item_name = item;
        temp->item_price = price;
        num_of_elements++;
        first = temp;
        last = temp;
        temp = nullptr;
    // Connect the newly created node
    }else{
        temp->item_name = item;
        temp->item_price = price;
        num_of_elements++;
        last->next = temp;
        last = temp;
        temp = nullptr;
    }
}
void ShoppingCart::removeItem(string item) {
    Node* prevPtr;                          // previous node
    Node* currPtr = first;                  // traverse the list of nodes
    // Check if its the first node
    if (currPtr->item_name == item){
        first = first->next;
        num_of_elements--;
        delete currPtr;
        currPtr = first;
    }
    while (currPtr != nullptr && currPtr->item_name != item){
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }

    // If currPtr finds the item to remove
    if (currPtr){
         prevPtr->next = currPtr->next;
         num_of_elements--;
         total_price_for_items -= currPtr->item_price;
         delete currPtr;
    }
}

void ShoppingCart::listItems() const{
    int index = 1;
    Node* node = first;
    cout << showpoint << setprecision(2) << fixed;
    cout << "=========================================\n"
         << "|  Shopping Cart                        |\n"
         << "=========================================\n";
         
        while (node != nullptr){
            cout << index++ << ": " << node->item_name << " | price: $" 
                                  << node->item_price << "\n";
            node = node->next;
        }

    cout << "\n=========================================\n"
         << "# of items: " << num_of_elements << " | Total cost: $" << getCartTotalPrice() << "    |\n"
         << "=========================================\n";
}

double ShoppingCart::getCartTotalPrice() const{
    return total_price_for_items;
}
int ShoppingCart::getNumOfItems() const{
    return num_of_elements;
}
void ShoppingCart::clearCart(){
    Node* curr = first;         // point currPtr to first node
	while (curr){
        first = first->next;
        delete curr;
        curr = first;
    }
    num_of_elements = 0;
    total_price_for_items = 0.0;
}
void ShoppingCart::saveCart() const{
    int index = 1;
    Node* node = first;
    fstream save_file;
    string filename = "Cart.txt";
    save_file.open(filename, ios::out);

    if (isCartEmpty()) {
        return;
    }

    cout << "Saving shopping cart list to a file.\n";
    save_file << "=========================================\n"
              << "|  Shopping Cart                        |\n"
              << "=========================================\n";
    while (node){
        save_file << index++ << ". " << node->item_name << " | price: $" << node->item_price << "\n";
        node = node->next;
    }

    save_file << "\n=========================================\n"
              << "# of items: " << num_of_elements << " | Total cost: $" << getCartTotalPrice() << "    |\n"
              << "=========================================\n";
    
    cout << "Items has been saved to " << filename << "\n"; 
}

ostream& operator<<(ostream& out, const ShoppingCart& cart){
    int index = 1;
    Node* node = cart.first;
    cout << "=========================================\n"
         << "|  Shopping Cart                        |\n"
         << "=========================================\n";

    while(node){
        cout << index++ << ". " << node->item_name << " | price: $" << node->item_price << "\n";
        node = node->next;
    }
    cout << "\n=========================================\n"
         << "# of items: " << cart.num_of_elements << " | Total cost: $" << cart.getCartTotalPrice() << "    |\n"
         << "=========================================\n";
    return out;
}


bool ShoppingCart::isMemAllocSuccessful(Node*& ptr) const{
    if(!ptr){
        cout << "Failed memory allocation.\n\n";
    }
    return false;
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
