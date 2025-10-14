#include <iostream>
using namespace std;

class HashTable{
    public:
        HashTable(){

        }
        HashTable(int size){
            capacity = size;
            num_of_elements = 0;
            key = 0;
            a = new int[capacity];

            for (int i = 0; i < capacity; i++)
            {
                a[i] = -1;
            }
        }

        void display() const{
            for (int i = 0; i < capacity; i++){
                cout << a[i] << ", ";
            }   
            cout << "\n";
        }

        void hashFunction(int value){
            key = value % capacity;
            
            if(a[key] == -1){
                a[key] = value;
            }
            else if(a[key] != -1){
                int increment = 0;
                while (a[key] != -1){
                    key = (value + increment) % capacity;
                    increment++;
                }
                a[key] = value;
            } 
        }

        int search(int value){
            
            int indexLocation = 0;
            for (key = value % capacity; key < capacity; key++){
                if (a[key] == value){
                    indexLocation = key;
                }      
            }
            return indexLocation;
        }
    private:
        int capacity;
        int num_of_elements;
        int* a;
        int key;
};

int main(){
    HashTable hash1(10);

    hash1.display();
    cout << "\n";

    hash1.hashFunction(6);
    hash1.display();
    cout << "\n";
    hash1.hashFunction(3);
    hash1.hashFunction(40);
    hash1.hashFunction(22);
    hash1.hashFunction(31);
    
    hash1.display();

    hash1.hashFunction(33);
    hash1.hashFunction(20);
    hash1.hashFunction(102);
    hash1.hashFunction(103);
    hash1.hashFunction(11);

    cout << "\n";
    hash1.display();


    cout << hash1.search(104);



}