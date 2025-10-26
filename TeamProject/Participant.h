#pragma once
#include <iostream>
#include "Neighborhood.h"
using namespace std;

class Participant{
    public:
        // Default Constructor
        Participant();
        // Overload Constructor
        Participant(int, string);
        Participant(int, string, double[]);

        // Participant(Neighborhood);
        // Destructor
        ~Participant();

        // Setter
        void add_neighborhood_distance(double);
        void add_to_total_distance(double);
        
        // Getter
        string get_name() const;
        int get_id() const;
        int get_size() const;
        double get_total_distance() const;
        string get_neighborhood_name_by_id(int)const;
        double get_distance_walk_by_neighborhood_id(int) const;
        void display_participants_neighborhoods();


        Neighborhood** neighborhoods; 

    private:
        int capacity;
        int num_of_elements;

        int id;
        string name;
        double total_distance;

        // Neighborhood** neighborhoods; 

        
};