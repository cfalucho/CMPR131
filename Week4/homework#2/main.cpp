#include <iostream>
#include "ShoppingCart.h"
#include "ShoppingCart.cpp"
using namespace std;

int main(){
    ShoppingCart List1;
    string item_to_remove = "";
    
    // Add items to list
    cout << "Add items to list.\n"; 
    List1.addItem("Nike Pegasus 41");
    List1.addItem("Nike Wildhorse 10");
    List1.addItem("Nike Wildhorse 10");
    List1.addItem("New Balance");

    cout << "\n-------------------------------------------------------------\n\n";
    cout << "Display list.\n";
    List1.listItems();

    cout << "\n-------------------------------------------------------------\n\n";

    cout << "Add 4 more items and display list\n";
    List1.addItem("Adidas 57");
    List1.addItem("Nike Sportswear Club");
    List1.addItem("Nike Sportswear Windrunner");
    List1.addItem("Nike Peak");

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
    List1.clearCart();
    cout << List1;


    return 0;
}