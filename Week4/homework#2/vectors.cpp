#include <iostream> 
#include <vector>
using namespace std;

bool checkMemAlloc(string*& ptr);

int main(){
    int capacity  = 5;
    int newCapacity = capacity * 2;
    int numOfElements = 0;
    // Create new array on the heap
    string* newArr = new string[newCapacity];

    if (checkMemAlloc(newArr)){
      cout << "continue...";
    }
    else{
        cout << "No new array created.\n";
 
    }
    return 0;
}

bool checkMemAlloc(string*& ptr){
    if (ptr)
    {  
        cout << "mem succsessful.\n";
        return true;
    }else{
        cout << "mem failed";
        return false;
    }
    
}