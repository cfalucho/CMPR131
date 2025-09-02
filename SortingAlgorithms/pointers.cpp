#include <iostream>

using namespace std;

void reverseArray(int[], int);

int main(){

    int x = 10;
   // Create array 
   int* array = new int[x];
   

   for (int i = 0; i < x; i++)
   {
        array[i] = i + 2; 
   }
   
//    reverseArray(array, x);
    
   int start = 0;
   int end = x - 1;
   int mid = end / 2;

   for (;start <= end; end--)
   {
        cout << array[end] << " ";
        // if (end == mid)
        // {
        //     break;
        // }
        
        
   }
   
   

   
  
    

    return 0; 
}

void reverseArray(int arr[], int NOE){

   
    int temp;
    for (int i = 1; i < NOE; i++)
    {
        temp = arr[i - 1];
        arr[i - 1] = arr[NOE - i];
        arr[NOE - i] = temp;
     
        
     
    }   
}