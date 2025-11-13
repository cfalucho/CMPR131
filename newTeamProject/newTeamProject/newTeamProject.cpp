#include <iostream>
#include "Manager.h"    
#include <fstream>
#include <sstream>


using namespace std;

/*
    Old Towne
    El Modena
    Orange Hills
    Santiago Creek
    Villa Park Area
    North El Camino Real
*/

void RunMainProject()
{
    Manager manage(1);

    manage.load_data_from_file("data.txt");
    manage.display_all_participants_and_their_distance_walks_per_neighborhood();
    cout << endl;

    manage.get_most_participant_by_total();
}

int main() {

    cout << "Running Main Project..\n";
    RunMainProject();
    return 0;
}