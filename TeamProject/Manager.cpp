#include <iomanip>
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
    id = -1;
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

void Manager::add_new_participant(int id, string name){

    participants[num_of_elements++] = Participant(id, name);
};


void Manager::add_new_participant(int id, string name, double distance_walk_arr[]){

    participants[num_of_elements++] = Participant(id, name, distance_walk_arr);
};


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
            participants[index].add_to_total_distance(user_input);
        }
        cout << "---------------------------------------\n";
    }
}

void Manager::set_distance_walk_by_neighborhood_id(int uid, int neighborhood_id, double distance_walk){
    participants[uid].add_to_total_distance(distance_walk);
    participants[uid].get_neighborhoods()[neighborhood_id]->set_distance_walk_this_neighborhood(distance_walk);
}

void Manager::display_a_participant(int id) const{
    cout << "ID: " << participants[id].get_id()
         << "\tName: " << participants[id].get_name() << "\n";
}

void Manager::display_a_participant_total_by_id(int uid) const{
    cout << "Participant's Name: " << participants[uid].get_name() << "\n";
    cout << "Total Distance Walk: " << participants[uid].get_total_distance() << " mi.";
}

void Manager::display_all_participants() const{
    for (int index = 0; index < num_of_elements; index++){
        cout << "\n---------------------------------------\n";
        cout << "Participant: " << participants[index].get_name() << "\t\t" << participants[index].get_id();
        cout << "\n---------------------------------------\n";  
    }
}

void Manager::display_a_participant_and_a_neighborhood(int id, int neighborhood_id) const{
    cout << "UID: " << participants[id].get_id() 
         << "\tName: " << participants[id].get_name()
         << "\t\tNeighborhood: " << participants[id].get_neighborhood_name_by_id(neighborhood_id)
         << "\t\tDistance: " << participants[id].get_distance_walk_by_neighborhood_id(neighborhood_id);
    }

void Manager::display_all_participants_and_their_neighborhoods() const {
    for (int i = 0; i < num_of_elements; i++){
        participants[i].display_participants_neighborhoods();
    }
}

void Manager::display_all_participants_and_their_distance_walks_per_neighborhood() const{
    cout << "UID"; 
    cout << setw(10) << "Name" 
         << setw(25) << "Old Towne"
         << setw(20) << "El Monte" 
         << setw(23) << "Orange Hills"
         << setw(20) << "Santiago Creek"
         << setw(22) << "Villa Park Area"
         << setw(23) << "N. El Camino Real"
         << setw(20) << "Total Distance";
    cout << "\n------------------------------------------------------------------"
         << "--------------------------------------------------------------------"
         << "--------------------------------\n";

    for (int uid = 0; uid < num_of_elements; uid++)
    {
        cout << participants[uid].get_id();
        cout << setw(15) << participants[uid].get_name();

        for (int neighborhood_id = 0; neighborhood_id < 6; neighborhood_id++)
        {
            cout << setw(20) << participants[uid].get_neighborhoods()[neighborhood_id]->get_distance_walk() << " mi.";                 
        }
        cout << setw(25) << participants[uid].get_total_distance();
        cout << "\n\n";
    }
}

void Manager::get_most_participant_by_total() const{
    cout << "Most Active Participant of the Day: " << most_active_participant_by_total()->get_name();
}

Participant* Manager::most_active_participant_by_total() const{
    if (num_of_elements > 0) //if we have participants
    {
        int activeParticipantID = 0;
        double highestTotal = participants[0].get_total_distance();
        for (int i = 1; i < num_of_elements - 1; i++)
        {
            if (participants[i].get_total_distance() > highestTotal)
            {
                highestTotal = participants[i].get_total_distance();
                activeParticipantID = i;
            }
        }
        return &participants[activeParticipantID];
    }
    return nullptr;
}
