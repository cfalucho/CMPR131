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
        string getName();
        Neighborhood getNeighborhoods();
        

    private:
        int capacity;
        int num_of_elements;
        string name;
        Neighborhood* neighborhoods[6];

};