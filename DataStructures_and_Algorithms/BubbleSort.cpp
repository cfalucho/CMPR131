#include <iostream>
using namespace std;

void bubbleSort(int[], int);

int main(){
    const int SIZE = 10;
    int arr[] = {55, 23, 12, 64, 24 ,84, 43, 34, 77, 91};

    bubbleSort(arr, SIZE);

    for (int i = 0; i < SIZE; i++){
        cout << arr[i] << ", ";
    }

}

void bubbleSort(int arr[], int SIZE){
    int temp = 0;
    for (int iterations = 1; iterations < SIZE; iterations++){
        for (int index = 0; index < SIZE - iterations; index++){
            if (arr[index] > arr[index + 1]){
                int tempSmallValue = 0;
                tempSmallValue = arr[index + 1];
                arr[index + 1] = arr[index];
                arr[index] = tempSmallValue;
                tempSmallValue = 0;
            }
        }
    }
}