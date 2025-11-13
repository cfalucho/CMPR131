#pragma once
#include <iostream>
#include "Participant.h"
using namespace std;

class Manager {
public:
    Manager();
    Manager(int);

    Manager(const Manager& manager);

    // overloaded copy assignment operator (bypass default memberwise assignment)
    Manager& operator=(const Manager& RHS) noexcept;

    // move constructor 
    Manager(Manager&& otherManager) noexcept;

    // move assignment constructor
    Manager& operator= (Manager&& right) noexcept;

    // array manipulation
    void double_array_capacity();
    void verify_array_capacity();

    // setters
    void add_new_participant(int, string);
    void add_new_participant(int, string, double[]);
    void set_distance_walk();
    void set_distance_walk_by_neighborhood_id(int, int, double);

    // getters
    Participant* get_participants() const;
    Participant* most_active_participant_by_total() const;
    
    // display functions
    void display_a_participant(int) const;
    void display_a_participant_total_by_id(int) const;
    void display_a_participant_and_a_neighborhood(int, int) const;
    void display_all_participants()const;
    void display_all_participants_and_their_neighborhoods() const;
    void display_all_participants_and_their_distance_walks_per_neighborhood() const;
    void get_most_participant_by_total() const;

    void load_data_from_file(string path);
    void create_neighborhoods();

private:
    int capacity;
    int num_of_elements;
    int id;
    Participant* participants;
    string* neighborhood_names;
};