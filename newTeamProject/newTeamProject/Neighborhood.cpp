#include "Neighborhood.h"

Neighborhood::Neighborhood() {
    unique_id = 0;
    neighborhood_name = "";
    neighborhood_dist_walk = 0.0;
}

Neighborhood::Neighborhood(int id, string name) {
    unique_id = id;
    neighborhood_name = name;
    neighborhood_dist_walk = 0.0;
}

Neighborhood::Neighborhood(int id, string name, double distance_walk) {
    unique_id = id;
    neighborhood_name = name;
    neighborhood_dist_walk = distance_walk;
}
Neighborhood::Neighborhood(const Neighborhood& otherNeigh)
{

	// copies name
	neighborhood_name = otherNeigh.neighborhood_name;

	// copies distance walked
	neighborhood_dist_walk =
		otherNeigh.neighborhood_dist_walk;

	unique_id = otherNeigh.unique_id;

}
// overloaded copy assignment operator (bypass default memberwise assignment)
Neighborhood& Neighborhood::operator=(const Neighborhood& RHS)
{
	// verify if there is self-assignment
	if (this == &RHS)
	{
		return *this;
	}

	neighborhood_name = RHS.neighborhood_name;

	neighborhood_dist_walk = RHS.neighborhood_dist_walk;

	unique_id = RHS.unique_id;

	// return self referencing pointer
	return *this;
}

// move constructor 
Neighborhood::Neighborhood(Neighborhood&& otherNeigh) noexcept
{

	neighborhood_name = otherNeigh.neighborhood_name;

	neighborhood_dist_walk =
		otherNeigh.neighborhood_dist_walk;

	unique_id = otherNeigh.unique_id;

	otherNeigh.neighborhood_name = "";
	otherNeigh.neighborhood_dist_walk = 0;
	otherNeigh.unique_id = 0;

}

// move assignment operator
Neighborhood& Neighborhood::operator= (Neighborhood&& right) noexcept
{
	if (this != &right)
	{
		neighborhood_name = right.neighborhood_name;
		neighborhood_dist_walk = right.neighborhood_dist_walk;


		right.neighborhood_dist_walk = 0;
		right.neighborhood_name = "";

	}

	return *this;
}


Neighborhood::~Neighborhood() {}

void Neighborhood::set_distance_walk_this_neighborhood(double distance) {
    neighborhood_dist_walk = distance;
}

string Neighborhood::get_neighborhood_name() const {
    return neighborhood_name;
}
double Neighborhood::get_distance_walk() const {
    return neighborhood_dist_walk;
}

int Neighborhood::get_neighborhood_unique_id() const {
    return unique_id;
}