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
        // Destructor
        ~Participant();

        // Getter
        string getName() const;

        Neighborhood get_distance_by_neighborhood(int id);

        void display_Participants_Neighborhood();
        

        Neighborhood** neighborhoods;
    private:
        int capacity;
        int num_of_elements;
        string name;
        // Neighborhood** neighborhoods;
};