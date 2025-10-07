#pragma once
#include <iostream>
#include "Neighborhood.h"
using namespace std;

class Participant{
    public:
        Participant();
        Participant(string);
        ~Participant();

        void display_Participants_Neighborhood();
        void add_walk_dist_per_neighborhood(const Neighborhood&);
        void add_distance_walk(double);
        string getName();
        Neighborhood getNeighborhoods();
        
        Neighborhood** neighborhoods;
    private:
        int capacity;
        int num_of_elements;
        string name;
        // Neighborhood** neighborhoods;
};