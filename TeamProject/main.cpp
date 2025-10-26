#include <iostream>
#include "Participant.cpp"  // remove for VS code
#include "Neighborhood.cpp" // remove for VS code
#include "Manager.cpp"      // remove for VS code
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

int main(){ 

    
    Manager manage(50);

    // Read a file
    ifstream readFile;
    readFile.open("data.txt");
    if (!readFile.is_open()){
        cout << "Error opening file.";
        return 1;
    }

    string line;

    // array to store distance
    double distanceWalk[6] = {0};
    for (int i = 0; i < 6; i++){
        distanceWalk[i] = 0;
    }
    
    while (getline(readFile, line)){
        int id;
        string firstName, lastName;
        double num;

        // Parse strings from a line of text
        stringstream ss(line);

        ss >> id >> firstName >> lastName;
        
        cout << id << " " << firstName << " " << lastName << " ";
        string name; 
        name = firstName + " " + lastName;

        int i = 0;
        // parse the doubles and store into an array
        while (ss >> num){
            cout << num << " ";
            distanceWalk[i] = num;
            i++;
        }
        cout << endl;
        
        for (int i = 0; i < 6; i++){
            cout << distanceWalk[i] << " ";
        }    
        cout << endl;

        manage.add_new_participant(id, name, distanceWalk);
    }
    manage.display_all_participants_and_their_distance_walks_per_neighborhood();
    cout << endl;

    manage.get_most_participant_by_total();
    




    
    
    

    // manage.add_new_participant("Sally");
    // manage.add_new_participant("Logan");

    // manage.set_distance_walk();
    
    // manage.display_all_participants();
    // string name = "";
    // manage.display_a_participant(0);
    // manage.display_a_participant(1);
    // manage.display_a_participant(2);
    // manage.display_a_participant(3);
    // manage.display_a_participant(4);


    // // manage.display_all_participants_and_their_neighborhoods();
    // manage.set_distance_walk_by_neighborhood_id(0,0,2.2);
    // manage.set_distance_walk_by_neighborhood_id(0,1,8.2);
    // manage.set_distance_walk_by_neighborhood_id(0,2,4.2);
    // manage.set_distance_walk_by_neighborhood_id(0,3,13.2);
    // manage.set_distance_walk_by_neighborhood_id(0,4,8.2);
    // manage.set_distance_walk_by_neighborhood_id(0,5,9.2);
    
    // manage.set_distance_walk_by_neighborhood_id(1,0,5.7);
    // manage.set_distance_walk_by_neighborhood_id(1,1,6.2);
    // manage.set_distance_walk_by_neighborhood_id(1,2,7.8);
    // manage.set_distance_walk_by_neighborhood_id(1,3,9.2);
    // manage.set_distance_walk_by_neighborhood_id(1,4,7.2);
    // manage.set_distance_walk_by_neighborhood_id(1,5,4.2);


    // manage.set_distance_walk_by_neighborhood_id(2,1,2.8);
    // manage.set_distance_walk_by_neighborhood_id(2,2,5.8);

    // manage.set_distance_walk_by_neighborhood_id(3,0,5.8);
    // manage.set_distance_walk_by_neighborhood_id(3,1,7.8);
    // manage.set_distance_walk_by_neighborhood_id(3,2,12.3);
    // manage.set_distance_walk_by_neighborhood_id(3,4,9.1);
    // manage.set_distance_walk_by_neighborhood_id(3,5,1.2);
    
    // manage.display_a_participant_and_a_neighborhood(1,1);
    // cout << "\n";
    // manage.display_a_participant_and_a_neighborhood(1,2);
    // cout << "\n";
    // manage.display_a_participant_and_a_neighborhood(1,3);
    // cout << "\n";
    // manage.display_a_participant_total_by_id(1);
    // cout << "\n";
    // manage.display_a_participant_and_a_neighborhood(2,1);
    // cout << "\n";
    // manage.display_a_participant_total_by_id(2);
    // cout << "\n\n";

    // manage.display_all_participants_and_their_distance_walks_per_neighborhood();
    
    
    // manage.most_active_participant_by_total();

    // manage.display_all_participants_and_their_distance_walks_per_neighborhood();

    // const int SIZE = 5
    // Participant* participants = new Participant[SIZE];

    // participants[0] = Participant("Christian");
    // participants[1] = Participant("Sally");
    // participants[2] = Participant("Logan");
    // participants[3] = Participant("John");
    // participants[4] = Participant("Ana");
    
//     participants[0].neighborhoods[2]->set_distance_walk(1.3);
//     participants[0].neighborhoods[3]->set_distance_walk(2.3);
//     participants[0].neighborhoods[4]->set_distance_walk(6.3);
//     participants[0].neighborhoods[5]->set_distance_walk(4.3);

//     cout << "\n";
  

//    for (int i = 0; i < 5; i++){
//         participants[i].display_Participants_Neighborhood();
//    }
   


// Neighborhood Class
    // const int SIZE = 6;
    // Neighborhood* neighborhood[SIZE];

    // for (int i = 0; i < 6; i++){
    //    neighborhood[i] = new Neighborhood();
    // }
    

    // for (int i = 0; i < SIZE; i++){
    //     cout << neighborhood[i] << "\n";
    // }

    // cout << "\n";
    // Neighborhood n1("Old Towne", 12.2);

    
    // cout << n1.getName();
    // cout << "\n";
    // cout << n1.getDistance();
    // neighborhood[0]->add_distance_walk_per_neighborhood("Old Towne", 12.2); 
    // neighborhood[1]->add_distance_walk_per_neighborhood("El Monte", 22.2);
    // neighborhood[2]->add_distance_walk_per_neighborhood("Orange Hills", 3.12);
    // neighborhood[3]->add_distance_walk_per_neighborhood("Santiago Creek", 44.2);
    // neighborhood[4]->add_distance_walk_per_neighborhood("Villa Park Area", 4.2);
    // neighborhood[5]->add_distance_walk_per_neighborhood("El Camino Real", 1.2);


    // cout << "\n";

    // for (int i = 0; i < SIZE; i++){
    //     cout << n1[i]->getName() << "\t | " 
    //          << neighborhood[i]->getDistance() << "\n";
    // }
    
    
    return 0;
}