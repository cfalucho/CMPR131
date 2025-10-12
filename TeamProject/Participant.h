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

        // Setter
        void add_neighborhood_distance(double);
        

        // Getter
        string get_name() const;
        double get_total_distance() const;
        void display_participants_neighborhoods();

        Neighborhood** neighborhoods; 


    private:
        int capacity;
        int num_of_elements;

        double totalDistance;

        string name;
        // Neighborhood** neighborhoods; 

        
};