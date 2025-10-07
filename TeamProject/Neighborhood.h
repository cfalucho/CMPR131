#pragma once
#include <iostream>
using namespace std;

class Neighborhood{
    public:
        Neighborhood();
        // Neighborhood(int);
        Neighborhood(int, string);
        Neighborhood(double);
        Neighborhood(string, double);
        ~Neighborhood();
        void setNeighborhood(int, string);
        void add_distance_walk(double);
        string get_neighborhood_name();
        double get_distance_walk();
        int get_neighborhood_unique_id();
        


    private:
        int capacity;
        int num_of_elements;

        int unique_id;
        string neighborhood_name;
        double distance_walk;
};