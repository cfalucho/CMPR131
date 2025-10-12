#include <iostream>
using namespace std;

int main(){

    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int unsortedArr[] = {55, 23, 12, 64, 24 ,84, 23, 34, 77, 91};
    int indexToDelete = 4;

    /*
    
    55, 4, 1, 99, 23, 40, 3, 5, 10, 64

    */

    // Display array 
    cout << "Before deletion: \n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }

    // Delete an item from the array
    for (int i = indexToDelete; i < SIZE; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    // // Display array after item deleted
    cout << "\n\n";
    cout << "After deletion: \n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    cout << sizeof(arr) / sizeof(arr[0]);
    /*
    
    0  1  2  3  4 5 6  7  8

    55 1 99 23 40 3 5 10 64 

    */
    int insertItem = 5;
    int indexNumber = 4;

    // Insert item in the middle of the array
    // Insert item in index [5]
    for (int i = 8; i >= indexNumber; i--)
    {
        arr[i + 1] = arr[i];
        if (i == indexNumber)
        {
            arr[indexNumber] = insertItem;
        }
    }
    


    cout << "\n\n";
    
    //Display array
    cout << "After inserting " << insertItem << " into index: " << indexNumber << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << "\n\n";
    
    

    

    
    

    return 0;

}