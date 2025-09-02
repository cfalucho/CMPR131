#include <iostream>
using namespace std;

int main(){

    int *ptr = nullptr;
    // cout << "ptr's memory address:                        " << ptr << endl;
    // cout << "ptr's variable memory address:               " << &ptr << endl;
    ptr = new int[5]{1,2,3};

    cout << ptr[2];
    // cout << "ptr's mem addr after init array to pointer:  " << ptr << endl;
    // cout << "ptr's mem addr after init arr to ptr:        " << &ptr << endl;
    // cout << endl;
    // ptr[0] = 2;
    // ptr[1] = 3;
    // ptr[4] = 99;
    // int newElement = 4;
    // *ptr = newElement;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << &ptr[i] << ":  " << ptr[i] << "\n";
    // }
    // cout << endl << endl;
    // ptr++;
    // newElement = 25;
    // *ptr = newElement;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << &ptr[i] << ":  " << ptr[i] << "\n";
    // }

    // // for (int i = 0; i < 5; i++)
    // // {
    // //     cout << &ptr[i] << " ";
        
    // // }

    // cout << "index value of pointer array[0]:             " << ptr[0] << endl;
    // cout << "---------------------\n\n";
    // cout << "Deleting ptr array...\n\n";
    // delete [] ptr;
    // cout << "Displaying ptr[0]...:                        " << ptr[0] << endl;
    
    // ptr = nullptr;
    // cout << "Pointer array deleted and set to nullptr:    " << ptr << endl;
    // cout << endl << endl;

    // cout << "Initialize new array to pointer.\n";
    // ptr = new int[2]{77,88};

    // cout << ptr << endl;
    // cout << ptr[0] << endl;
    // cout << *ptr << endl;
    // cout << *ptr++ << endl;
    // cout << *ptr << endl;
    // cout << &ptr << endl;
    // cout << &ptr << endl;
    // // cout << &ptr << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << &ptr[i] << " ";
    // }

    return 0;
}