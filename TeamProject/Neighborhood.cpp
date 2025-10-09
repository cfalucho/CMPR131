#include "Neighborhood.h"

Neighborhood::Neighborhood(){
    unique_id = 0;
    neighborhood_name = "";
    distance_walk = 0.0;
}

Neighborhood::Neighborhood(int id, string name){
    unique_id = id;
    neighborhood_name = name;
    distance_walk = 0.0;
}

Neighborhood::~Neighborhood(){}

void Neighborhood::set_distance_walk(double distance){
    this->distance_walk = distance;
};

string Neighborhood::get_neighborhood_name() const{
    return neighborhood_name;
}
double Neighborhood::get_distance_walk() const{
    return distance_walk;
}

int Neighborhood::get_neighborhood_unique_id() const{
    return unique_id;
}