#include "Manager.h"

const int NEIGHBORHOOD_SIZE = 6;
string neighborhood_names[NEIGHBORHOOD_SIZE] = {
        "Old Towne",
        "El Monte",
        "Orange Hills",
        "Santiago Creek",
        "Villa Park Area",
        "N. El Camino Real"
};
Manager::Manager(){
    capacity = 10;
    num_of_elements = 0;
    participants = new Participant[capacity];
}


Manager::Manager(int participant_size){
    capacity = participant_size;
    num_of_elements = 0;
    participants = new Participant[capacity];

}

void Manager::add_new_participant(string name){
    capacity = NEIGHBORHOOD_SIZE;
    participants[num_of_elements++] = Participant(name);

    neighborhoods = new Neighborhood*[capacity];
    for (int index = 0; index < capacity; index++){
        neighborhoods[index] = new Neighborhood(index + 1, 
                                                neighborhood_names[index]);
    }
}

// void Manager::set_distance_walk(Participant* participants){
//     double user_input = 2;
//     participants[1].neighborhoods[2]->set_distance_walk(user_input);
    
// }

void Manager::set_distance_walk(){
    double user_input = 0;
    for (int index = 0; index < num_of_elements; index++){
        cout << "\n---------------------------------------\n";
        cout << "Participant: " << participants[index].get_name() << "\n";
        cout << "---------------------------------------\n";
        for (int j = 0; j < 6; j++){
            cout << neighborhoods[j]->get_neighborhood_name() << ": ";
            cin >> user_input;
            neighborhoods[j]->set_distance_walk(user_input);
        }
        cout << "---------------------------------------\n";
    }
    
}

void Manager::display_all_participants(){
    for (int index = 0; index < num_of_elements; index++){
        cout << "\n---------------------------------------\n";
        cout << "Participant: " << participants[index].get_name() << "\n";
        cout << "---------------------------------------\n";
        for (int j = 0; j < 6; j++){
            cout << showpoint << fixed << setprecision(1);
            cout << neighborhoods[j]->get_neighborhood_unique_id() << ") "
                 << neighborhoods[j]->get_neighborhood_name() << ": \t\t" << setw(8)
                 << neighborhoods[j]->get_distance_walk();
            cout << "\n";
        }
    }
}


// void Manager::display_all_participants(){
//     for (int i = 0; i < capacity; i++){
//         participants[i].display_participants_neighborhoods();
//     }
// }