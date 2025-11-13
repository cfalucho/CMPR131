#include "Participant.h"
#include <iomanip>

//-----GLOBAL VARIABLES-----
const int NEIGHBORHOOD_SIZE = 6;
string neighborhood_names[NEIGHBORHOOD_SIZE] = {
        "Old Towne",
        "El Modena",
        "Orange Hills",
        "Santiago Creek",
        "Villa Park Area",
        "N. El Camino Real"
};
//---------------------------

Participant::Participant() {
    name = "";

}

Participant::Participant(int uid, string new_participant) {
    capacity = NEIGHBORHOOD_SIZE;
    id = uid;
    name = new_participant;
    total_distance = 0.0;

    neighborhoods = new Neighborhood * [capacity];
    for (int index = 0; index < NEIGHBORHOOD_SIZE; index++) {
        neighborhoods[index] = new Neighborhood(index + 1,
            neighborhood_names[index]);
    }
}

Participant::Participant(int uid, string new_participant, double distance_walk_arr[]) {
    capacity = NEIGHBORHOOD_SIZE;
    id = uid;
    name = new_participant;
    total_distance = 0.0;

    for (int i = 0; i < capacity; i++) {
        total_distance += distance_walk_arr[i];
    }


    neighborhoods = new Neighborhood * [capacity];
    for (int index = 0; index < NEIGHBORHOOD_SIZE; index++) {
        neighborhoods[index] = new Neighborhood(index + 1,
            neighborhood_names[index], distance_walk_arr[index]);
    }
}

Participant::Participant(const Participant& participant)
{
    capacity = participant.capacity;
    id = participant.id;
    name = participant.name;
    total_distance = participant.total_distance;

    neighborhoods = new Neighborhood * [capacity];
    for (int i = 0; i < capacity; i++)
    {
        neighborhoods[i] = new Neighborhood(*participant.neighborhoods[i]);
    }
}

// overloaded copy assignment operator (bypass default memberwise assignment)
Participant& Participant::operator=(const Participant& RHS)
{
    // verify if there is self-assignment
    if (this == &RHS)
    {
        return *this;
    }

    capacity = RHS.capacity;
    id = RHS.id;
    name = RHS.name;
    total_distance = RHS.total_distance;

    neighborhoods = new Neighborhood * [capacity];
    for (int i = 0; i < capacity; i++)
    {
        neighborhoods[i] = new Neighborhood(*RHS.neighborhoods[i]);
    }


    // return self referencing pointer
    return *this;
}

// move constructor 
Participant::Participant(Participant&& otherParticipant) noexcept
{
    capacity = otherParticipant.capacity;
    id = otherParticipant.id;
    name = otherParticipant.name;
    total_distance = otherParticipant.total_distance;
    neighborhoods = otherParticipant.neighborhoods;


    otherParticipant.capacity = 0;
    otherParticipant.id = 0;
    otherParticipant.name = "";
    otherParticipant.total_distance = 0;
    otherParticipant.neighborhoods = nullptr;

}

// move assignment operator
Participant& Participant::operator= (Participant&& right) noexcept
{
    if (this != &right)
    {
        capacity = right.capacity;
        id = right.id;
        name = right.name;
        total_distance = right.total_distance;
        neighborhoods = right.neighborhoods;


        right.capacity = 0;
        right.id = 0;
        right.name = "";
        right.total_distance = 0;
        right.neighborhoods = nullptr;
    }

    return *this;
}

Participant::~Participant() {

    delete[] neighborhoods;
};

void Participant::add_neighborhood_distance(double distance_walk) {
    for (int i = 0; i < NEIGHBORHOOD_SIZE; i++) {
        neighborhoods[i]->set_distance_walk_this_neighborhood(distance_walk);
    }
}

void Participant::add_to_total_distance(double distance_walk) {
    total_distance += distance_walk;
}



string Participant::get_name() const {
    return name;
}

int Participant::get_id() const {
    return id;
}

int Participant::get_capacity() const
{
    return capacity;
}
/*
int Participant::get_number_of_elements() const {
    return num_of_elements;
}*/

double Participant::get_total_distance() const {
    return total_distance;
}

string Participant::get_neighborhood_name_by_id(int id)const {
    return neighborhoods[id]->get_neighborhood_name();
}

double Participant::get_distance_walk_by_neighborhood_id(int id) const {
    return neighborhoods[id]->get_distance_walk();

}

void Participant::display_participants_neighborhoods() {
    cout << "\n---------------------------------------\n";
    cout << "Participant: " << name << "\n";
    cout << "---------------------------------------\n";
    for (int i = 0; i < capacity; i++) {
        cout << showpoint << fixed << setprecision(1);
        cout << neighborhoods[i]->get_neighborhood_unique_id() << ") "
            << neighborhoods[i]->get_neighborhood_name() << ": \t\t" << setw(8);        cout << "\n";
    }
}

Neighborhood** Participant::get_neighborhoods() {
    return neighborhoods;
}