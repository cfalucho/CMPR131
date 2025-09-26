#include <iostream>
#include <cctype>
using namespace std;

void printVectorCapSize(vector<string>&);
void listItems(vector<string>&);
int getNumOfItems(vector<string>&);
void addItem(vector<string>&, string);
void removeItem(vector<string>&, string);
string toLowerCase(string&);
void clearCart(vector<string>&);


int main(){

    vector<string> numbers;
    numbers = vector<string>(5);
    listItems(numbers);
    printVectorCapSize(numbers);

    numbers.resize(10);
    addItem(numbers, "Watermelon");
    addItem(numbers, "Cherry");
    addItem(numbers, "Apple");
    addItem(numbers, "Green");
    addItem(numbers, "Grapes");
    addItem(numbers, "Mangos");
    addItem(numbers, "Bananas");
    addItem(numbers, "Raspberry");
    addItem(numbers, "Blueberry");
    addItem(numbers, "Green Grapes");
    addItem(numbers, "Green Apples");
    addItem(numbers, "Oranges");
    addItem(numbers, "Durian");
    
    listItems(numbers);
    printVectorCapSize(numbers); 
   

    removeItem(numbers, "Mangos");
    removeItem(numbers, "green grapes");
    removeItem(numbers, "pineapple");
    listItems(numbers);
    printVectorCapSize(numbers);
    removeItem(numbers, "Mangos");


    clearCart(numbers);
    listItems(numbers);
    printVectorCapSize(numbers);
    clearCart(numbers);
    removeItem(numbers, "Mangos");




    // string word = "Green";

    // cout << toLowerCase(word);

    // const int SIZE = 30;
    // char textArray[SIZE];
    // string text = "Green";
    // strcpy(textArray, text.c_str());

    // for (int i = 0; i < strlen(textArray); i++)
    // {
    //     textArray[i] = tolower(textArray[i]);
    // }
    // string newS = textArray;
    // cout << newS;
    
    return 0;
}


void printVectorCapSize(vector<string>& vector){
    cout << "\n";
    cout << "capacity: " << vector.capacity() << "\t\t" << "size: " << vector.size() << "\n\n";
}

void listItems(vector<string>& vector){
    for (int i = 0; i < vector.size(); i++)
    {
        cout << "[" << i << "]: " << vector[i] << "\n";
    }   
}

int getNumOfItems(vector<string>& vector){
    return vector.size();
}

void addItem(vector<string>& vector, string item){
    string itemLowerCase = toLowerCase(item);
    static int index = 0;
    if (vector[index] == "" && vector.size() != vector.capacity())
    {
        vector[index] = itemLowerCase;
        index++;
    }
    else{
        vector.push_back(itemLowerCase);
    }
}

void removeItem(vector<string>& vector, string item){
    string itemLowerCase = toLowerCase(item);
    string lastElement = vector.back();
    string temp = "";
    bool isFound = false;
    if (vector.empty()){
        cout << "Cart is already empty.";
        EXIT_SUCCESS;
    }
    
    for (int index = 0; index < vector.size(); index++)
    {
        if (vector[index] == itemLowerCase) {
            isFound = true;
            temp = vector[index];
            vector[index] = lastElement;
            lastElement = temp;
            cout << "Removing item " << itemLowerCase << "\n";
            vector.pop_back();
        }
    }
    if (!isFound && !vector.empty()){
        cout << itemLowerCase << " is not found.\n";
        EXIT_SUCCESS;  
    }
}

string toLowerCase(string& text){
    const int SIZE = 30;
    char textArray[SIZE];
    strcpy(textArray, text.c_str());

    for (int i = 0; i < strlen(textArray); i++)
    {
        textArray[i] = tolower(textArray[i]);
    }
    return textArray;
}

void clearCart(vector<string>& vector){
    if (vector.empty())
    {
        cout << "Cart is already empty.\n";
    }
    else{
        cout << "Going to clear the cart.\n";
        vector.clear();
    }
}