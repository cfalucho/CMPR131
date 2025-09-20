#include <iostream>
using namespace std;

void selectionSort(int arr[],int);
void bubbleSort(int arr[], int);
int findSum(int arr[], int);
void findLargestValue(int arr[], int);
void printLargestToSmallest(int arr[], int);

int main(){
    
    const int SIZE = 10;
    int arr[SIZE] = {10,2,4,1,6,11,12,5,3,7};
    
    // Selection Sort
    // selectionSort(arr, SIZE);
    // bubbleSort(arr, SIZE);

    cout << "Sum: " << findSum(arr, SIZE);
    cout << "\n\n";
    cout << "Largest value: ";
    findLargestValue(arr, SIZE);
    cout << "\n\n";
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    printLargestToSmallest(arr, SIZE);


    

    return 0;
}

void selectionSort(int arr[], int size){
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j]= temp;
            }
        }
    }
}

void bubbleSort(int arr[], int size){
   int temp = 0;
   for (int iterations = 1; iterations < size - 1; iterations++)
   {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }   
        }    
   }
}

int findSum(int arr[], int size){
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

/*

{10,2,4,1,6,11,12,5,3,7};

*/
void findLargestValue(int arr[], int size){
    int temp = 0;
    
    
    for (int i = 0; i < size - 1; i++)
    {  
      if (arr[i + 1] > arr[0])
      {
        temp = arr[0];
        arr[0] = arr[i + 1];            
        arr[i + 1] = temp;
      }
    }
    cout << arr[0];
}

void printLargestToSmallest(int arr[], int size){
    bubbleSort(arr, size);
            
    for (int i = 0; i < size; size--)
    {
        cout << arr[size - 1] << " ";
    }
    
}