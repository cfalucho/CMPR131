#pragma once
#include <iostream>
#include "Participant.h"
using namespace std;

class Manager{
    public:
        Manager();
        Manager(int);
        
        void add_new_participant(string);
        // void set_distance_walk(Participant*);
        void set_distance_walk();

        void display_all_participants();
    private:
        int capacity;
        int num_of_elements;
        Participant* participants;
        Neighborhood** neighborhoods; 
};