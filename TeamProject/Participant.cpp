#include "Participant.h"
#include <iomanip>

Participant::Participant(){
    name = "";
}
Participant::Participant(string name){
    capacity = 6;
    num_of_elements = 0;

    this->name = name;
    for (int i = 0; i < capacity; i++){
        neighborhoods[i] = new Neighborhood(i);
    }
    
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
        cout << neighborhoods[i]->get_neighborhood_unique_id() << ") "
             << neighborhoods[i]->get_neighborhood_name() << ": \t" << setw(4)
             << neighborhoods[i]->get_distance_walk();
        cout << "\n";
    }
}