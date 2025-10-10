#pragma once
#include <iostream>
#include "Neighborhood.h"
using namespace std;

class Participant{
    public:
        // Default Constructor
        Participant();
        // Overloaed Constructor
        Participant(string);

        Participant(Neighborhood);
        // Destructor
        ~Participant();

        // Getter
        string get_name() const;


        void display_participants_neighborhoods();
    private:
        int capacity;
        int num_of_elements;
        string name;
        // Neighborhood** neighborhoods; 
};