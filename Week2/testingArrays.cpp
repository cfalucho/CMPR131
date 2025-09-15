#include <iostream>
using namespace std;

class Dog{
    private:
        string name;

    public:
        void setName(string name){
            this->name = name;
        }

        string getName() const{
            return name;
        }

        void bark() const{
            cout << "Woof!";
        }
};

int main(){
    
    Dog dog1;
    dog1.setName("Logan");
    cout << dog1.getName();
    cout << endl;
    dog1.bark();
    
    return 0;
}