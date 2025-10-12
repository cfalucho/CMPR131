#include <iostream>
using namespace std;


// Function prototype
int binarySearch(int[], int, int);

int main () {
    
    int SIZE = 17;
    int arr[]= {4, 5, 6, 7, 8, 9, 20, 25, 30, 45, 53, 65, 75, 84, 90, 95, 99};

    int searchItem = 65;


    int index_of_item = binarySearch(arr, SIZE, searchItem);

    cout << "The item " << searchItem << " is in index " << index_of_item; 



    return 0;
}

// Function that uses Binary Search to search for an item in a Sorted Array
// Divides the size in half if the item is not found

/*
Example:

Objective:
    Array = {4, 5, 6, 7, 8, 9, 20, 25, 30, 45, 53, 65, 75, 84, 90, 95, 99};
    Search Item = 20;


**PsuedoCode**

first = 0;
last = SIZE - 1; 
found = false;
location = 0;

while 0 <= SIZE - 1 && item is not found
    mid = (first + last) / 2
    if arr[mid] == searchItem
        found = true
        location = mid
    else if arr[mid] > searchItem
        last = mid - 1
    else
        first = mid + 1
return location



*/
int binarySearch(int arr[], int SIZE, int searchItem){
    int first = 0;
    int last = SIZE - 1;
    int mid;

    bool found = false;
    int location = 0;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (arr[mid] == searchItem){
            found = true;
            location = mid; 
        }
        else if (arr[mid] > searchItem){
            last = mid - 1; 
        }
        else{
            first = mid + 1;
        }
    }
    
    if(found){
        return location;
    }
    else{
        return -1;
    }
    
}
