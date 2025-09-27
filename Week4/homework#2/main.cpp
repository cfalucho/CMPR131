#include <iostream>
#include "ShoppingCart.h"
#include "ShoppingCart.cpp"
using namespace std;

int main(){
    ShoppingCart List1;

    List1.addItem("Nike Pegasus 41");
    List1.addItem("Nike Wildhorse 10");
    List1.addItem("New Balance");
    List1.addItem("Adidas 57");
    List1.addItem("Nike Sportswear Club");
    List1.addItem("Nike Sportswear Windrunner");
    List1.addItem("Nike Peak");


    // List1.listItems();
    // List1.removeItem("Bananas");
    // List1.listItems();

    // List1.listItems();
    
    List1.listItems();
    List1.removeItem("Adidas 57");
    List1.saveCart();






    return 0;
}