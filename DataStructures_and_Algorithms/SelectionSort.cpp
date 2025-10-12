#include <iostream>
using namespace std;

void selectionSort(int[], int);

int main(){
    const int SIZE = 10;
    int arr[] = {55, 23, 12, 64, 24 ,84, 43, 34, 77, 91};
    // int arr[] = {12, 55, 23, 64, 24 ,84, 43, 34, 77, 91};



    selectionSort(arr, SIZE);

    for (int i = 0; i < SIZE; i++){
        cout << arr[i] << ", ";
    }

}

void selectionSort(int arr[], int SIZE){
    for (int i = 0; i < SIZE; i++){
        for (int j = i + 1; j < SIZE - 1; j++)
        {
            if (arr[j] < arr[i]){
                int temp = 0;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }
    
}