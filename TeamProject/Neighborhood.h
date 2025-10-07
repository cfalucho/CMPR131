#pragma once
#include <iostream>
using namespace std;

class Neighborhood{
    public:
        Neighborhood();
        Neighborhood(int);
        Neighborhood(string, double);
        ~Neighborhood();
        string get_neighborhood_name();
        double get_distance_walk();
        int get_neighborhood_unique_id();


    private:
        int capacity;
        int num_of_elements;

        int id;
        string neighborhood_name;
        double distance_walk;

        
};