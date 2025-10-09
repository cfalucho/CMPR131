#include <iostream>
#include "Participant.cpp"
#include "Neighborhood.cpp"
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
    const int SIZE = 5;
    Participant* participants = new Participant[SIZE];


    participants[0] = Participant("Christian");
    participants[1] = Participant("Sally");
    participants[2] = Participant("Logan");
    participants[3] = Participant("John");
    participants[4] = Participant("Ana");
    
  
    participants[0].neighborhoods[0]->set_distance_walk(12.3);
    participants[0].neighborhoods[1]->set_distance_walk(33.3);
    participants[0].neighborhoods[2]->set_distance_walk(1.3);
    participants[0].neighborhoods[3]->set_distance_walk(2.3);
    participants[0].neighborhoods[4]->set_distance_walk(6.3);
    participants[0].neighborhoods[5]->set_distance_walk(4.3);


    
    

    cout << "\n";
  


     


   for (int i = 0; i < SIZE; i++){
        participants[i].display_Participants_Neighborhood();
   }
   




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