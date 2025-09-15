#include <iostream>
using namespace std;

bool isAnagram(string s, string t);

int main(){

    string s = "racecar";
    string t = "carrace";

    int string1 = s.length();
    int string2 = t.length();
    
    // cout << string1;
    cout << "\n";
    char arr1[string1 + 1];
    char arr2[string2 + 2];

    strcpy(arr1, s.c_str());
    strcpy(arr2, t.c_str());


    for (int i = 0; i < string1; i++)
    {
      for(int j = i + 1; j < string1; j++){
         if (arr1[j] < arr1[i])
         {
            int temp = arr1[j];
            arr1[j] = arr1[i];
            arr1[i] = temp;
         }
      }
    }

    for (int i = 0; i < string2; i++)
    {
      for(int j = i + 1; j < string2; j++){
         if (arr2[j] < arr2[i])
         {
            int temp = arr2[j];
            arr2[j] = arr2[i];
            arr2[i] = temp;
         }
      }
    }

    cout << "\n\n";
    for (size_t i = 0; i < string1; i++)
    {
        cout << arr1[i] << ", ";
    }


    cout << "\n\n";
    for (size_t i = 0; i < string2; i++)
    {
        cout << arr2[i] << ", ";
    }
    cout << "\n\n";
    cout << strcmp(arr1, arr2);
    
    
    
    

    return 0;
}


// bool isAnagram(string s, string t){
//     char string[] = "s";


//     return false;
// }

