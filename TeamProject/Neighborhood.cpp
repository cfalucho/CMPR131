#include "Neighborhood.h"

Neighborhood::Neighborhood(){
    id = 0;
    neighborhood_name = "";
    distance_walk = 0.0;
}
Neighborhood::Neighborhood(int id){
    id++;
    neighborhood_name = "";
    distance_walk = 0.0;
}
Neighborhood::Neighborhood(string name, double distance_walk){
    this->neighborhood_name = name;
    this->distance_walk = distance_walk;
}
Neighborhood::~Neighborhood(){}

string Neighborhood::get_neighborhood_name(){
    return neighborhood_name;
}
double Neighborhood::get_distance_walk(){
    return distance_walk;
}

int Neighborhood::get_neighborhood_unique_id(){
    return id;
}