#pragma once
#include <iostream>
#include "Participant.h"
using namespace std;

class Manager{
    public:
        Manager();
        Manager(int);
        
        void add_new_participant(string);
        // setters
        void set_distance_walk();
        void set_distance_walk_by_neighborhood_id(int, int, double);

        // getters
        void display_a_participant(int) const;
        void display_a_participant_total_by_id(int) const;
        void display_a_participant_and_a_neighborhood(int, int) const;
        void display_all_participants()const;
        void display_all_participants_and_their_neighborhoods() const;
        void display_all_participants_and_their_distance_walks_per_neighborhood() const;

        // void most_active_participant_by_total() const;
    
        private:
        int capacity;
        int num_of_elements;
        int id;
        Participant* participants;
        string* neighborhood_names;
};