#include <iomanip>
#include <fstream>
#include <sstream>
#include "Manager.h"

Manager::Manager(int) {
    capacity = 10;
    num_of_elements = 0;
    id = -1;
    participants = new Participant[capacity];

    create_neighborhoods();
}

Manager::Manager(const Manager& manager)
{
    capacity = manager.capacity;
    num_of_elements = manager.num_of_elements;
    id = manager.id;

    participants = new Participant[capacity];
    for (int i = 0; i < manager.num_of_elements; i++)
    {
        participants[i] = *new Participant(manager.participants[i]);
    }
    create_neighborhoods();
}

// overloaded copy assignment operator (bypass default memberwise assignment)
Manager& Manager::operator=(const Manager& RHS) noexcept
{
     
    // verify if there is self-assignment
    if (this == &RHS)
    {
        return *this;
    }

    capacity = RHS.capacity;
    num_of_elements = RHS.num_of_elements;
    id = RHS.id;

    
    participants = new Participant[capacity];
    for (int i = 0; i < RHS.num_of_elements; i++)
    {
        
        participants[i] = *new Participant(RHS.participants[i]);
    }
    create_neighborhoods();

    // return self referencing pointer
    return *this;
}

// move constructor 
Manager::Manager(Manager&& otherManager) noexcept
{
    capacity = otherManager.capacity;
    otherManager.capacity = 0;
    num_of_elements = otherManager.num_of_elements;
    otherManager.num_of_elements = 0;
    id = otherManager.id;
    otherManager.id = 0;

    participants = otherManager.participants;
    otherManager.participants = nullptr;

    neighborhood_names = otherManager.neighborhood_names;
    otherManager.neighborhood_names = nullptr;

}

// move assignment operator
Manager& Manager::operator= (Manager&& right) noexcept
{
    if (this != &right)
    {
        capacity = right.capacity;
        right.capacity = 0;
        num_of_elements = right.num_of_elements;
        right.num_of_elements = 0;
        id = right.id;
        right.id = 0;

        participants = right.participants;
        right.participants = nullptr;

        neighborhood_names = right.neighborhood_names;
        right.neighborhood_names = nullptr;
    }

    return *this;
}

void Manager::double_array_capacity() {

    capacity = capacity * 2;
    Participant* new_participant_array = new Participant[capacity];
    for (int i = 0; i < num_of_elements; i++)
    {
        new_participant_array[i] = move(participants[i]);
    }
    delete[] participants;
    participants = new_participant_array;
}
void Manager::verify_array_capacity() {

    if (num_of_elements >= capacity)
    {
        double_array_capacity();
    }
}

void Manager::add_new_participant(int id, string name) {

    verify_array_capacity();
    participants[num_of_elements++] = Participant(id, name);
};


void Manager::add_new_participant(int id, string name, double distance_walk_arr[]) {

    verify_array_capacity();
    participants[num_of_elements++] = Participant(id, name, distance_walk_arr);
};


void Manager::set_distance_walk() {
    double user_input = 0;
    for (int index = 0; index < num_of_elements; index++) {
        cout << "\n---------------------------------------\n";
        cout << "Participant: " << participants[index].get_name() << "\n";
        cout << "---------------------------------------\n";
        for (int j = 0; j < 6; j++) {
            cout << neighborhood_names[j] << ": ";
            cin >> user_input;
            participants[index].add_neighborhood_distance(user_input);
            participants[index].add_to_total_distance(user_input);
        }
        cout << "---------------------------------------\n";
    }
}

void Manager::set_distance_walk_by_neighborhood_id(int uid, int neighborhood_id, double distance_walk) {
    participants[uid].add_to_total_distance(distance_walk);
    participants[uid].get_neighborhoods()[neighborhood_id]->set_distance_walk_this_neighborhood(distance_walk);
}

Participant* Manager::get_participants() const{
    return participants;
}

void Manager::display_a_participant(int id) const {
    cout << "ID: " << participants[id].get_id()
        << "\tName: " << participants[id].get_name() << "\n";
}

void Manager::display_a_participant_total_by_id(int uid) const {
    cout << "Participant's Name: " << participants[uid].get_name() << "\n";
    cout << "Total Distance Walk: " << participants[uid].get_total_distance() << " mi.";
}

void Manager::display_all_participants() const {
    for (int index = 0; index < num_of_elements; index++) {
        cout << "\n---------------------------------------\n";
        cout << "Participant: " << participants[index].get_name() << "\t\t" << participants[index].get_id();
        cout << "\n---------------------------------------\n";
    }
}

void Manager::display_a_participant_and_a_neighborhood(int id, int neighborhood_id) const {
    cout << "UID: " << participants[id].get_id()
        << "\tName: " << participants[id].get_name()
        << "\t\tNeighborhood: " << participants[id].get_neighborhood_name_by_id(neighborhood_id)
        << "\t\tDistance: " << participants[id].get_distance_walk_by_neighborhood_id(neighborhood_id);
}

void Manager::display_all_participants_and_their_neighborhoods() const {
    for (int i = 0; i < num_of_elements; i++) {
        participants[i].display_participants_neighborhoods();
    }
}

void Manager::display_all_participants_and_their_distance_walks_per_neighborhood() const {
    const int WIDTH = 18;
    cout << "UID";
    cout << setw(20) << "Name"
        << setw(WIDTH) << "Old Towne"
        << setw(WIDTH) << "El Monte"
        << setw(WIDTH) << "Orange Hills"
        << setw(WIDTH) << "Santiago Creek"
        << setw(WIDTH) << "Villa Park Area"
        << setw(WIDTH) << "N. El Camino Real"
        << setw(25) << "Total Distance";
    cout << "\n------------------------------------------------------------------"
        << "--------------------------------------------------------------------"
        << "----------------------\n-----------------------"

        << setw(135) << "DISTANCE WALKED IN MILES"

        "\n------------------------------------------------------------------"
        << "--------------------------------------------------------------------"
        << "----------------------\n";



    if (num_of_elements != 0)
    {
        for (int uid = 0; uid < num_of_elements; uid++)
        {
            cout << participants[uid].get_id();
            cout << setw(20) << participants[uid].get_name();

            for (int neighborhood_id = 0; neighborhood_id < 6; neighborhood_id++)
            {
                cout << setw(WIDTH) << participants[uid].get_neighborhoods()[neighborhood_id]->get_distance_walk();
            }
            cout << setw(25) << participants[uid].get_total_distance();
            cout << "\n\n";

        }
    }
}

void Manager::get_most_participant_by_total() const {
    cout << "Most Active Participant of the Day: " << most_active_participant_by_total()->get_name() << "\n";
}

void Manager::load_data_from_file(string path)
{
    // Read a file
    ifstream readFile;
    readFile.open(path);
    if (!readFile.is_open()) {
        cout << "Error opening file.";
        throw;
    }

    string line;

    // array to store distance
    double distanceWalk[6] = { 0 };
    for (int i = 0; i < 6; i++) {
        distanceWalk[i] = 0;
    }

    while (getline(readFile, line)) {
        int id;
        string firstName, lastName;
        double num;

        // Parse strings from a line of text
        stringstream ss(line);

        ss >> id >> firstName >> lastName;

        string name;
        name = firstName + " " + lastName;

        int i = 0;
        // parse the doubles and store into an array
        while (ss >> num) {
            distanceWalk[i] = num;
            i++;
        }

        add_new_participant(id, name, distanceWalk);
    }
}

void Manager::create_neighborhoods(){
    int NEIGHBORHOOD_SIZE = 6;
    neighborhood_names = new string[NEIGHBORHOOD_SIZE] 
    { 
        "Old Towne" , 
        "El Monte" ,
        "Orange Hills" ,
        "Santiago Creek" ,
        "Villa Park Area" ,
        "N. El Camino Real"
    };
}

Participant* Manager::most_active_participant_by_total() const {
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