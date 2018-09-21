#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <vector>

#include "Entity.h"

class Location {
protected:
    bool m_HostileArea;

    std::string m_Name; 
    std::string m_Description;

    std::vector<Entity> m_Npcs;
    std::vector<Location> m_ConnectedAreas;

public:
    // Default constructor
    Location();

    // Parsing constructor
    Location(std::string); 
    
    // Full constructor
    Location(bool hostile, std::string name, std::string description,std::vector<Entity> npcs, std::vector<Location> connected);
    
    virtual ~Location();
    
};

#endif