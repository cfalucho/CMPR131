#include <iostream>
#include "DArray.cpp"
#include "DArray.h"

using namespace std;

int main(){
    

    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5 - i; j++)
        {
            cout << " ";
        }
        cout << "*";
        
    }
    




    

    return 0;
}