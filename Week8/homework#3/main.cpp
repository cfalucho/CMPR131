/*
    Christian Falucho
    CMPR 131 - Fall 2025
    October 28, 2025
    Homework #2
    Collaboration: None
*/
#include <iostream>
#include "ShoppingCart.h"
#include "ShoppingCart.cpp"
using namespace std;



int main(){
    ShoppingCart List1;
    string item_to_remove = "";
    
    // Add items to list
    cout << "Add items to list.\n"; 
    List1.addItem("Nike Pegasus 41", 23.21);
    List1.addItem("Nike Wildhorse 10", 12.31);
    List1.addItem("Adizero EVO SL Shoes", 7.23);
    List1.addItem("Galaxy 7 Running Shoes", 7.23);
    List1.addItem("Numeric Linear Logo T-Shirt", 7.23);
    List1.addItem("Numeric Linear Logo T-Shirt", 7.23);
    List1.addItem("Athletics French Terry Crew", 7.23);
    List1.addItem("Nike Wildhorse 10", 7.23);
    List1.addItem("Nike Wildhorse 10", 7.23);
    List1.addItem("Ultraboost 5X Shoes", 100.23);
    List1.addItem("New Balance", 200.1);

    cout << "\n-------------------------------------------------------------\n\n";
    cout << "Display list.\n";
    List1.listItems();

    cout << "\n-------------------------------------------------------------\n\n";

    cout << "Add 4 more items and display list\n";
    List1.addItem("Adidas 57", 104.23);
    List1.addItem("Nike Sportswear Club", 44.23);
    List1.addItem("Nike Sportswear Windrunner", 190.23);
    List1.addItem("Nike Peak", 99.99);

    cout << List1;

    cout << "\n-------------------------------------------------------------\n\n";
    
    cout << "Remove an item: ";

    getline(cin, item_to_remove);
    List1.removeItem(item_to_remove);
    cout << "\n";
    cout << List1;


    cout << "\n-------------------------------------------------------------\n\n";

    // Saving cart to a file.
    List1.saveCart();

    cout << "\n-------------------------------------------------------------\n\n";

    // Clearing cart
    cout << "Clearing the cart...\n";
    List1.clearCart();
    cout << List1;

    return 0;
}