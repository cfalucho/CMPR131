#include <iostream>
#include "BST.h"

using namespace std;



int main(){
    BST aircraft;
    BST aircraft3;

    cout << "----------------------\n";
    cout << "|\t LOGS        |\n";
    cout << "----------------------\n";
    aircraft.insert(1005);
    aircraft.insert(1005);
    aircraft.insert(1005);
    aircraft.insert(1010);
    aircraft.insert(1035);
    aircraft.insert(2200);
    aircraft.insert(2200);
    aircraft3.insert(1135);
    aircraft3.insert(1245);
    aircraft3.insert(1505);
    aircraft3.insert(900);
    aircraft3.insert(930);
    cout << "----------------------\n";
    cout << "|\t LOGS        |\n";
    cout << "----------------------\n";
    
    

    cout << "\nPrinting Landing times...\n";
    aircraft.print_schedule();

    aircraft.remove(1005);
    aircraft.remove(1035);
    aircraft.remove(1505);
    aircraft.print_schedule();
    cout << "\n";

    aircraft.remove(1001);
    cout << "\n";
    aircraft.print_schedule();


    BST aircraft2(aircraft);
    
    aircraft2.print_schedule();
    cout << "Aircraft 3 landing time tree.\n";
    aircraft3.print_schedule();

    cout << "Performing overloading assignment operator.\n";
    aircraft.operator=(aircraft3);

    cout << "Aircraft 2 landing time tree.\n";
    aircraft.print_schedule();
}