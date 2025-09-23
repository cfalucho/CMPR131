#pragma once
#include <iostream>
#include "ShoppingCart.h"
// #include  <vector>


ShoppingCart::ShoppingCart(){
    cartList = vector<string>(5);
}
void ShoppingCart::addItem(string name){

     cartList.begin();
}
void ShoppingCart::removeItem(string) const{

}
void ShoppingCart::listItems() const{
    for (int i = 0; i < cartList.size(); i++)
    {
        cout << cartList[i] << ",  ";
    }
}

int ShoppingCart::getCapacity() const{
    return cartList.capacity();
}
int ShoppingCart::getNumOfItems(){
    return cartList.size();
}
// void ShoppingCart::clearCart(){

// }
// void ShoppingCart::saveCart(){

// }
ostream& operator<<(ostream& out, const vector<string> cartList){
    out << "[";
    for (int i = 0; i < cartList.capacity(); i++)
    {
        out << cartList[i];
    }
    
    return out;
}