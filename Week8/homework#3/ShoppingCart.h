/*
    Christian Falucho
    CMPR 131 - Fall 2025
    October 10, 2025
    Homework #3
    Collaboration: None
*/
#pragma once
using namespace std;

struct Node{
    string item_name;
    double item_price;
    Node* next = nullptr;
};
class ShoppingCart{
    private:
        int capacity;
        int num_of_elements;
        double total_price_for_items;

        Node* first;
        Node* last;

    public:
        ShoppingCart();
        void addItem(string, double);
        void removeItem(string);
        void listItems() const;
        double getCartTotalPrice() const;
        int getNumOfItems() const;
        void clearCart();
        void saveCart() const;
        friend ostream& operator<<(ostream&, const ShoppingCart& cart);

        //===============================
        //   HELPER MEMBER FUNCTIONS
        //===============================
        bool isMemAllocSuccessful(Node*&) const;
        bool isCartEmpty() const;
 
};