#include "Manager.h"


Manager::Manager(){
    capacity = 10;
    num_of_elements = 0;
    participants = new Participant[capacity];

    int NEIGHBORHOOD_SIZE = 6;
    neighborhood_names = new string[NEIGHBORHOOD_SIZE];
    neighborhood_names[0] = "Old Towne";
    neighborhood_names[1] = "El Monte";
    neighborhood_names[2] = "Orange Hills";
    neighborhood_names[3] = "Santiago Creek";
    neighborhood_names[4] = "Villa Park Area";
    neighborhood_names[5] = "N. El Camino Real";

   
}


Manager::Manager(int participant_size){
    capacity = participant_size;
    num_of_elements = 0;
    participants = new Participant[capacity];


    int NEIGHBORHOOD_SIZE = 6;
    neighborhood_names = new string[NEIGHBORHOOD_SIZE];
    neighborhood_names[0] = "Old Towne";
    neighborhood_names[1] = "El Monte";
    neighborhood_names[2] = "Orange Hills";
    neighborhood_names[3] = "Santiago Creek";
    neighborhood_names[4] = "Villa Park Area";
    neighborhood_names[5] = "N. El Camino Real";
}

void Manager::add_new_participant(string name){
    capacity = NEIGHBORHOOD_SIZE;
    participants[num_of_elements++] = Participant(name);

    // neighborhoods = new Neighborhood*[capacity];
    // for (int index = 0; index < capacity; index++){
    //     neighborhoods[index] = new Neighborhood(index + 1, 
    //                                             neighborhood_names[index]);
    // }
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
            cout << neighborhood_names[j] << ": ";
            cin >> user_input;
            participants[index].add_neighborhood_distance(user_input);
            participants[index].totalDistance += user_input;
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
            cout << neighborhood_names[j] << ": \t\t" << setw(8)
                 << participants[index].neighborhoods[j]->get_distance_walk();
            cout << "\n";
        }
        cout << "\n---------------------------------------\n";
        cout << "Total Distance: " << participants[index].get_total_distance()  << "\n";
        cout << "---------------------------------------\n";
    }
}


// void Manager::display_all_participants(){
//     for (int i = 0; i < capacity; i++){
//         participants[i].display_participants_neighborhoods();
//     }
// }