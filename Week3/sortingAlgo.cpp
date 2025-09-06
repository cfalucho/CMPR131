#include <iostream>
using namespace std;

void bubbleSort(int[], int);
void selectionSort(int[], int);

int main() {

    const int SIZE = 13;
    int arr[SIZE] = {3, 2, 54, 14, 23, 3, 1, 6, 77, 33, 242, 43, 34};


    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    
    bubbleSort(arr, SIZE);
    cout << "\n\n";
    

    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// Sort numbers from smallest to greatest, 
// left to right
void bubbleSort(int arr[], int size){
    for (int iterations = 1; iterations < size; iterations++)
    {
        for (int index = 0; index < size - iterations; index++)
        {
            if (arr[index] > arr[index + 1])
            {
                int tempSmValue = 0;
                tempSmValue = arr[index + 1];
                arr[index + 1] = arr[index];
                arr[index] = tempSmValue;
                tempSmValue = 0;
            }     
        }    
    }
}

/*


*/
void selectionSort(int arr[], int size){
    for (int smallestValue = 0; smallestValue < size; smallestValue++)
    {
        for (int index = smallestValue + 1; index < size; index++)
        {
            if (arr[smallestValue] > arr[index])
            {
                int temp = 0;
                temp = arr[index];
                arr[index] = arr[smallestValue];
                arr[smallestValue] = temp;
            }
        }
    }
}
