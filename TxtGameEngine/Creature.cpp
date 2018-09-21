#include "Creature.h"

Creature::Creature(){}

Creature::Creature(std::string dataString){
    std::cout << "> Creature created.\n" << dataString 
              << "\n--------------------------------------------------------\n";
    //std::regex mainSets("\[\w\]");
}

Creature::~Creature(){}