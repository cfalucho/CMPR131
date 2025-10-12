#include <iostream>
using namespace std;

int main (){

    int unsortedArr[] = {55, 23, 12, 64, 24 ,84, 43, 34, 77, 91};
    int SIZE = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

    int temp;
    // Let index 0 be the smallest number

    for (int iteration = 1; iteration < SIZE; iteration++)
    {
        for (int i = 0; i < SIZE - iteration; i++)
        {
            if (unsortedArr[i] > unsortedArr[i + 1])
            {
                temp = unsortedArr[i]; 
                unsortedArr[i] = unsortedArr[i + 1];
                unsortedArr[i + 1] = temp;
            }
        }
    }
    
    cout << "\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << unsortedArr[i] << " ";
    }
    
    return 0;

}
