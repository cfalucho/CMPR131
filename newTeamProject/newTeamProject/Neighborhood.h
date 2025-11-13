#pragma once
#include <iostream>
using namespace std;

class Neighborhood {
public:
    // Default Constructor
    Neighborhood();
    // Overloaded Constructor
    Neighborhood(int, string);
    Neighborhood(int, string, double);

    // Copy Constructor
    Neighborhood(const Neighborhood& otherNeigh);

	// overloaded copy assignment operator (bypass default memberwise assignment)
	Neighborhood& operator=(const Neighborhood& RHS);

	// move constructor 
    Neighborhood(Neighborhood&& otherNeigh) noexcept;

	// move assignment constructor
    Neighborhood& operator= (Neighborhood&& right) noexcept;
    // Destructor
    ~Neighborhood();

    // Setters
    void set_distance_walk_this_neighborhood(double);

    // Getters
    string get_neighborhood_name() const;
    double get_distance_walk() const;
    int get_neighborhood_unique_id()const;

private:

    int unique_id;
    string neighborhood_name;
    double neighborhood_dist_walk;
};