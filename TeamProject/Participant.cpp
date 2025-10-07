#include "Participant.h"
#include <iomanip>

Participant::Participant(){
    name = "";
}
Participant::Participant(string name){
    
    capacity = 6;
    num_of_elements = 0;

    this->name = name;
    
    neighborhoods = new Neighborhood*[capacity];
    neighborhoods[0] = new Neighborhood(1, "Old Towne");
    neighborhoods[1] = new Neighborhood(2, "El Monte");
    neighborhoods[2] = new Neighborhood(3, "Orange Hills");
    neighborhoods[3] = new Neighborhood(4, "Santiago Creek");
    neighborhoods[4] = new Neighborhood(5, "Villa Park Area");
    neighborhoods[5] = new Neighborhood(6, "North Camino Real");
    
    // for (int i = 0; i < capacity; i++){
    //     neighborhoods[i] = new Neighborhood(1, "Old Towne");
    // }
    
}
Participant::~Participant(){};

void Participant::add_walk_dist_per_neighborhood(const Neighborhood& nh){
    *neighborhoods[num_of_elements++] = nh;
}



string Participant::getName(){
    return name;
}

Neighborhood Participant::getNeighborhoods(){
    return *neighborhoods[num_of_elements++];
}
void Participant::display_Participants_Neighborhood(){
    cout << "\n---------------------------------------\n";
    cout << "Participant: " << name << "\n";
    cout << "---------------------------------------\n";
    for (int i = 0; i < capacity; i++){
        cout << showpoint << fixed << setprecision(1);
        cout << neighborhoods[i]->get_neighborhood_unique_id() << ") "
             << neighborhoods[i]->get_neighborhood_name() << ": \t\t" << setw(5)
             << neighborhoods[i]->get_distance_walk();
        cout << "\n";
    }
}