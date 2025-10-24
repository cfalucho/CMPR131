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

void Manager::add_new_participant(string name){
    id++;
    participants[num_of_elements++] = Participant(name, id);
}


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
    participants[uid].neighborhoods[neighborhood_id]->set_distance_walk_this_neighborhood(distance_walk);
}


// void Manager::get_distance_walk_from_user_id(int id) const{
//     string participant_name = "";
//     for (int i = 0; i < participants->get_size(); i++){
//         if (participants[i].get_id() == id){
//             participant_name = participants[i].get_name();
//             cout << participant_name;
//         }
//     }
    
// }
void Manager::display_a_participant(int id) const{
    cout << "Name: " << participants[id].get_name() 
         << "\tUID: " << participants[id].get_id() << "\n";
}

void Manager::display_a_participant_total_by_id(int uid) const{
    cout << "Participant's Name: " << participants[uid].get_name() << "\n";
    cout << "Total Distance Walk: " << participants[uid].get_total_distance() << " mi.";
}

void Manager::display_all_participants() const{
    for (int index = 0; index < num_of_elements; index++){
        cout << "\n---------------------------------------\n";
        cout << "Participant: " << participants[index].get_name() << "\t\t" << participants[0].get_id();
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
            cout << setw(20) << participants[uid].neighborhoods[neighborhood_id]->get_distance_walk();
                 
        }
        cout << setw(25) << participants[uid].get_total_distance();
        cout << "\n\n";

        // cout << "Most Active Participant of the Day: ";
                  
    }
    
   
}

// void Manager::most_active_participant_by_total(){
//     for (int i = 0; i < participants.get_size(); i++){
//         for (int j = i + 1; j < participants.get_size() - 1; i++)
//         {
//             if (participants[i] < participants[j])
//             {
//                 participants = new Participant[1];
//                 participants = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
            
//         }
        
//     }
// }

// void selectionSort(int arr[], int SIZE){
//     for (int i = 0; i < SIZE; i++){
//         for (int j = i + 1; j < SIZE - 1; j++){
//             if (arr[j] < arr[i]){
//                 int temp = 0;
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }