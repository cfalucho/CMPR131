#include <iostream>
using namespace std;

class ShoppingCart{
    private:
        vector<string> cartList;
  
    public:
        ShoppingCart();
        void addItem(string);
        void removeItem(string) const;
        void listItems() const;
        int getCapacity() const;
        int getNumOfItems();
        // void clearCart();
        // void saveCart();
        friend ostream& operator<<(ostream&, const vector<string>);





};