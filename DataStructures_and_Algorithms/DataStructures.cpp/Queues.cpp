#include <iostream>
using namespace std;


class Queue{
    private:
        int capacity = 0;
        int* a = new int[capacity];
        int num_of_elements = 0;

        int first = 0;
        int last = capacity - 1;
    
    public:
        Queue(){
            capacity = 5;
            a = new int[capacity]();
        }
        void addQueue(int num){

            if (isFull()){
                cout << "Capacity is full.\n";
            }else{
                last = (last + 1) % capacity;
                cout << "Add " << num << " to the queue.\n";
                a[last] = num;
                num_of_elements++;
            }
        }
        void deleteQueue(){
            // check if queue is empty
            if (isEmpty()){
                cout << "Queue is empty.\n";
            }
            else{
                // delete element from the first element (First-In-First-Out)
                cout << "Delete " << a[first] << " from the queue.\n";
                a[first] = 0;
                first++;
                num_of_elements--;
            }
        }

        bool isFull() const{
            return (num_of_elements == capacity - 1);
        }

        bool isEmpty() const {
            return (num_of_elements == 0);
        }

        void displayQueue() const{
            for (int i = 0; i < capacity; i++){
                cout << i << ")" << a[i] << " ";
            }    
            cout << "\n";

            cout << "first: " << a[first] << "\n";
            cout << "last: " << a[last] << "\n";
            cout << "noe: " << num_of_elements << "\n";
            cout << "cap: " << capacity << "\n\n";
        }
};

int main(){
    
    Queue queue1;
    queue1.addQueue(5);
    queue1.addQueue(18);
    queue1.addQueue(7);
    queue1.addQueue(10);

    queue1.displayQueue();
    queue1.deleteQueue();
    queue1.displayQueue();

    queue1.deleteQueue();
    queue1.displayQueue();

    queue1.addQueue(20);
    queue1.displayQueue();

    queue1.addQueue(25);
    queue1.displayQueue();

    queue1.addQueue(55);
    queue1.displayQueue();


}