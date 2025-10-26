#pragma once
#include <iostream>
using namespace std;

class Neighborhood{
    public:
        // Default Constructor
        Neighborhood();
        // Overloaded Constructor
        Neighborhood(int, string);
        Neighborhood(int, string, double);
    

        // Destructor
        ~Neighborhood();

        // Setters
        void set_distance_walk_this_neighborhood(double);

        // Getters
        string get_neighborhood_name() const;
        double get_distance_walk() const;
        int get_neighborhood_unique_id()const;
        int get_size() const;

    private:
        int capacity;
        int num_of_elements;

        int unique_id;
        string neighborhood_name;
        double neighborhood_dist_walk;
};