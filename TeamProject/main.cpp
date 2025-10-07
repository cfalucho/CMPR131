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
    
    // for (int i = 0; i < SIZE; i++)
    // {
    //     cout << p1[i].getName() << "\n";
    // }
    
   participants[0].add_walk_dist_per_neighborhood(Neighborhood("Old Towne", 12.2));
   participants[0].add_walk_dist_per_neighborhood(Neighborhood("El Monte", 5.1));
   participants[0].add_walk_dist_per_neighborhood(Neighborhood("Orange Hills", 3.1));
   participants[0].add_walk_dist_per_neighborhood(Neighborhood("Santiago Creek", 55.1));
   participants[0].add_walk_dist_per_neighborhood(Neighborhood("Villa Park Area", 20.1));
   participants[0].add_walk_dist_per_neighborhood(Neighborhood("El Camino Real", 33.1));
     
   participants[1].add_walk_dist_per_neighborhood(Neighborhood("Old Towne", 12.2));
   participants[1].add_walk_dist_per_neighborhood(Neighborhood("El Monte", 51.1));
   participants[1].add_walk_dist_per_neighborhood(Neighborhood("Orange Hills", 33.1));
   participants[1].add_walk_dist_per_neighborhood(Neighborhood("Santiago Creek", 6.1));
   participants[1].add_walk_dist_per_neighborhood(Neighborhood("Villa Park Area", 60.1));
   participants[1].add_walk_dist_per_neighborhood(Neighborhood("El Camino Real", 23.1));

   participants[2].add_walk_dist_per_neighborhood(Neighborhood("Old Towne", 2.2));
   participants[2].add_walk_dist_per_neighborhood(Neighborhood("El Monte", 13.1));
   participants[2].add_walk_dist_per_neighborhood(Neighborhood("Orange Hills", 13.1));
   participants[2].add_walk_dist_per_neighborhood(Neighborhood("Santiago Creek", 5.1));
   participants[2].add_walk_dist_per_neighborhood(Neighborhood("Villa Park Area", 2.1));
   participants[2].add_walk_dist_per_neighborhood(Neighborhood("El Camino Real", 3.1));



   
   participants[0].display_Participants_Neighborhood();




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