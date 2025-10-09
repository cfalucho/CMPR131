#pragma once
#include <iostream>
using namespace std;

class Neighborhood{
    public:
        // Default Constructor
        Neighborhood();
        // Overloaded Constructor
        Neighborhood(int, string);
        // Destructor
        ~Neighborhood();

        // Setters
        void set_distance_walk(double);

        // Getters
        string get_neighborhood_name() const;
        double get_distance_walk() const;
        int get_neighborhood_unique_id() const;
        


    private:
        int capacity;
        int num_of_elements;

        int unique_id;
        string neighborhood_name;
        double distance_walk;
};