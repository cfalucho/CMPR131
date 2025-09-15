#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void bubbleSort(int[], int);
void selectionSort(int[], int);
int partition(int[], int, int);
void swap(int[], int, int);

bool isDuplicate(vector<int>&);

int main() {

    const int SIZE = 5;
    int arr[SIZE] = {1,2,3,3,4};

    vector<int> nums = {1, 2, 3, 4, 5};
    // int start = 0;
    // int end = 12;
    
    cout << nums.size();
    cout << "\n";
    // Generate 100 randome numbers
    // for (int i = 0; i < SIZE; i++)
    // {
    //     arr[i] = rand() % 10000;
    // }
    cout << isDuplicate(nums);

    // partition(arr, start, end);
    // for (int i = 0; i < SIZE; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    //  BubbleSort
    // Start Time
    // auto bubbleSort_start = high_resolution_clock::now();
    // bubbleSort(arr, SIZE);
    // // // Stop time
    // auto bubbleSort_stop = high_resolution_clock::now();
    // auto bubbleSort_duration = duration_cast<microseconds>(bubbleSort_stop - bubbleSort_start);

    // SelectionSort
    // auto selectionSort_start = high_resolution_clock::now();
    // selectionSort(arr, SIZE);
    // auto selectionSort_stop = high_resolution_clock::now();
    // auto selectionSort_duration = duration_cast<microseconds>(selectionSort_stop - selectionSort_start);

    // for (int i = 0; i < SIZE; i++)
    // {
    //     cout << count++ << ". " << arr[i] << "\n";
    // }
    
    cout << "\n\n";
    // cout << "BubbleSort runtime Algorithm: " << bubbleSort_duration.count() << " microseconds.\n\n";
    // cout << "SelectionSort runtime Algorithm: " << selectionSort_duration.count() << " microseconds.\n\n";


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


/*
Original Array
{3, 2, 54, 14, 23, 3, 34, 6, 77, 33, 242, 43, 55};


// After swap
{34, 2, 54, 14, 23, 3, 3, 6, 77, 33, 242, 43, 55};
 

Now partitioning
        {34, 2, 14, 23, 3, 3, 6, 33, 77, 54, 242, 43, 55};
        pV     
                                  s
                                                      i

pivotValue > index
34 > 2
34 > 54

Output:




*/

int partition(int arr[], int start, int end){
    int mid = (start + end) / 2;        // (0 + 13) / 2 = 6
    swap(arr, start, mid);

    int pivotValue = arr[start];
    int smallIndex = start;

    for (int index = smallIndex + 1; index <= end; index++)
    {
        if (pivotValue > arr[index])
        {
            smallIndex++;
            swap(arr, index, smallIndex);
            
        }
    }
    swap(arr, start, smallIndex);
    return smallIndex;
}


void swap(int arr[], int first, int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}


/*
{1, 2, 3, 4, 5};
       i
              j
*/

bool isDuplicate(vector<int>& nums){
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
            
        }
        
    }
    if (count > 0)
    {
        return true;
    }

    return false;
}