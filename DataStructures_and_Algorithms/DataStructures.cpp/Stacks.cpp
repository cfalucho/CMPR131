#include <iostream>
using namespace std;

class Stacks{
    public:
        Stacks(int size){
            capacity = size;
            num_of_elements = 0;
            a = new int[capacity];  
        };

        void push(int num){
            // Check if stack is full
            if (!isFull()){
                a[num_of_elements++] = num;   
            }
        }

        void pop(){
            a[num_of_elements - 1] = 0;
            num_of_elements--;
        }

        bool isEmpty() const{
            return num_of_elements == 0;
        }

        bool isFull() const{
            return num_of_elements == capacity;
        }

        int get_capacity(){
            return capacity;
        }

        void display_stack() {
            for (int i = 0; i < capacity; i++){
                cout << a[i] << "\n";
            }
            cout << "top of stack: " << get_top();
        }

        int get_top(){
            return a[num_of_elements - 1];
        }

    private:
        int capacity;
        int num_of_elements;
        int top;
        int* a;
};

int main(){
    Stacks stacks1(5);


    stacks1.push(2);
    stacks1.push(4);
    stacks1.push(5);
    stacks1.push(1);
    stacks1.push(7);
    stacks1.display_stack();

    cout << "\nPop item..\n";
    stacks1.pop();
    stacks1.display_stack();


}