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
Participant::Participant(string name){
    capacity = 6;
    num_of_elements = 0;

    this->name = name;
    
    neighborhoods = new Neighborhood*[capacity];
    for (int index = 0; index < capacity; index++){
        neighborhoods[index] = new Neighborhood(index + 1, 
                                                neighborhood_names[index]);
    }
}
Participant::~Participant(){};


string Participant::getName() const{
    return name;
}

Neighborhood Participant::get_distance_by_neighborhood(int id){
    return *neighborhoods[id];
}

void Participant::display_Participants_Neighborhood(){
    cout << "\n---------------------------------------\n";
    cout << "Participant: " << name << "\n";
    cout << "---------------------------------------\n";
    for (int i = 0; i < capacity; i++){
        cout << showpoint << fixed << setprecision(1);
        cout << neighborhoods[i]->get_neighborhood_unique_id() << ") "
             << neighborhoods[i]->get_neighborhood_name() << ": \t\t" << setw(8)
             << neighborhoods[i]->get_distance_walk();
        cout << "\n";
    }
}