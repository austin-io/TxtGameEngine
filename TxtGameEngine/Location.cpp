#include "Location.h"

Location::Location(){}

Location::Location(std::string dataString){
    std::cout << "> Location created.\n" << dataString 
              << "\n--------------------------------------------------------\n";

}

Location::Location(bool hostile, std::string name, std::string description,std::vector<Entity> npcs, std::vector<Location> connected){

}

Location::~Location(){}