#include "Participant.h"
#include <iomanip>

//-----GLOBAL VARIABLES-----
const int NEIGHBORHOOD_SIZE = 6;
string neighborhood_names[NEIGHBORHOOD_SIZE] = {
        "Old Towne",
        "El Monte",
        "Orange Hills",
        "Santiago Creek",
        "Villa Park Area",
        "N. El Camino Real"
};
//---------------------------

Participant::Participant(){
    name = "";
}
Participant::Participant(string new_participant){
    name = new_participant;

    neighborhoods = new Neighborhood*[capacity];
    for (int index = 0; index < NEIGHBORHOOD_SIZE; index++){
        neighborhoods[index] = new Neighborhood(index + 1, 
                                                neighborhood_names[index]);
    }
}

void Participant::add_neighborhood_distance(double distance_walk){
    for (int i = 0; i < NEIGHBORHOOD_SIZE; i++){
        neighborhoods[i]->set_distance_walk(distance_walk);
        // totalDistance += distance_walk;
    }
}




Participant::~Participant(){};

string Participant::get_name() const{
    return name;
}

double Participant::get_total_distance() const {
    return totalDistance;
}

// Neighborhood Participant::get_neighborhoods() const{
//     return **neighborhoods;
// }

// void Participant::display_participants_neighborhoods(){
//     cout << "\n---------------------------------------\n";
//     cout << "Participant: " << name << "\n";
//     cout << "---------------------------------------\n";
//     for (int i = 0; i < capacity; i++){
//         cout << showpoint << fixed << setprecision(1);
//         cout << neighborhoods[i]->get_neighborhood_unique_id() << ") "
//              << neighborhoods[i]->get_neighborhood_name() << ": \t\t" << setw(8)
//              << neighborhoods[i]->get_distance_walk();
//         cout << "\n";
//     }
// }