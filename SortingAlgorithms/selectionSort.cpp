#include <iostream>
using namespace std;

template <class elemType>
int minLocation(elemType[], int, int);

template <class elemType>
void swap(elemType arr[], int, int);

template <class elemType>
void selectionSort(elemType[], int);

int main() {
    
    int arr[] = {55, 23, 12, 64, 24 ,84, 43, 34, 77, 91,
                222, 212, 241, 7, 8, 22, 96, 76, 63, 51, 65,
                42, 3, 13, 55, 33, 4, 216, 288, 266, 249,
                29, 26, 6, 14, 64, 79, 45, 41, 50, 99,
                121, 134, 145, 167, 177, 189, 122, 111, 112, 145,
                1, 5, 2, 234, 251, 264,  67, 11, 31, 81,
                312, 325, 366, 377, 333, 321, 355, 371, 383, 399
            };
    
    int firstIndex = 0;
    const int SIZE = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
       cout << arr[i] << " ";

       if ((i % 10) == 0 && i != 0)
       {
            cout << "\n";
       }
        
    }
    return 0;
}

// Find the smallest element in the array
template <class elemType>
int minLocation(elemType arr[], int firstIndex, int SIZE){
    int minIndex = firstIndex;

    for (int position = firstIndex + 1; position < SIZE - 1 ; position++)
    {
        if (arr[minIndex] > arr[position])
        {
            minIndex = position;
        }
    }
    return minIndex;
}

// Swap the elements of the smallest Index and the next index
template <class elemType>
void swap(elemType arr[], int first, int second){
    int temp;

    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

template <class elemType>
void selectionSort(elemType arr[], int SIZE){

    int minIndex;
    for (int position = 0; position < SIZE; position++)
    {
        minIndex = minLocation(arr, position, SIZE);
        swap(arr, position, minIndex);
    }
}