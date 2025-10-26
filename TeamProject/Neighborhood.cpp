#include "Neighborhood.h"

Neighborhood::Neighborhood(){
    unique_id = 0;
    neighborhood_name = "";
    neighborhood_dist_walk = 0.0;
}

Neighborhood::Neighborhood(int id, string name){
    unique_id = id;
    neighborhood_name = name;
    neighborhood_dist_walk = 0.0;
}

Neighborhood::Neighborhood(int id, string name, double distance_walk){
    unique_id = id;
    neighborhood_name = name;
    neighborhood_dist_walk = distance_walk;
}


Neighborhood::~Neighborhood(){}

void Neighborhood::set_distance_walk_this_neighborhood(double distance){
    neighborhood_dist_walk = distance;
}

string Neighborhood::get_neighborhood_name() const{
    return neighborhood_name;
}
double Neighborhood::get_distance_walk() const{
    return neighborhood_dist_walk;
}

int Neighborhood::get_neighborhood_unique_id() const{
    return unique_id;
}

int Neighborhood::get_size() const{
    return num_of_elements;
}