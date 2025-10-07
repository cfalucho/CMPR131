#include "Neighborhood.h"

Neighborhood::Neighborhood(){
    unique_id = 0;
    neighborhood_name = "";
    distance_walk = 0.0;
}
// Neighborhood::Neighborhood(int id){
//     unique_id = id;
//     neighborhood_name = "";
//     distance_walk = 0.0;
// }
Neighborhood::Neighborhood(double distance){
    this->distance_walk = distance;
}
Neighborhood::Neighborhood(int id, string name){
    unique_id = id;
    neighborhood_name = name;
    distance_walk = 0.0;
}
Neighborhood::Neighborhood(string name, double distance_walk){
    this->neighborhood_name = name;
    this->distance_walk = distance_walk;
}

// void Neighborhood::setNeighborhood(int id, string neighborhood_name){
//     this->unique_id = id;
//     this->neighborhood_name;
// }

void Neighborhood::add_distance_walk(double distance){
    this->distance_walk = distance;
};

Neighborhood::~Neighborhood(){}

string Neighborhood::get_neighborhood_name(){
    return neighborhood_name;
}
double Neighborhood::get_distance_walk(){
    return distance_walk;
}

int Neighborhood::get_neighborhood_unique_id(){
    return unique_id;
}