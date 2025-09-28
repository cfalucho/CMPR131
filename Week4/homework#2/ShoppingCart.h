#pragma once
using namespace std;


class ShoppingCart{
    private:
        int capacity;
        int num_of_elements;
        string* ptr;

    public:
        ShoppingCart();
        void addItem(string);
        void removeItem(string);
        void listItems() const;
        int getCapacity() const;
        int getNumOfItems() const;
        void clearCart();
        void saveCart() const;
        friend ostream& operator<<(ostream&, const ShoppingCart& cart);

        //===============================
        //   HELPER MEMBER FUNCTIONS
        //===============================
        double memoryUsage() const;     
        bool isMemAllocSuccessful(string*&) const;
        bool isCartEmpty() const;
        int itemFound(string) const;
        void realloc(int);
        void resize();  
};