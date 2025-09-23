#include <iostream>
// #include "ShoppingCart.h"
#include "ShoppingCart.cpp"
#include <vector>

using namespace std;

int main(){
    ShoppingCart Cars;

    cout << Cars.getNumOfItems();

    Cars.addItem("Tesla");
    Cars.addItem("Honda");
 
    cout << "\n\n";
    cout << Cars.getNumOfItems();
    cout << "\n\n";
    Cars.listItems();
    cout << "\n\n";
    Cars.getCapacity();
    return 0;
}