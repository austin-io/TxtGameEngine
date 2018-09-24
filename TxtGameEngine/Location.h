/** 
*   This file is a part of the TxtGameEngine.
*
*   The TxtGameEngine is a program used to create simple text-based RPG Adventure games.
*   Copyright (C) 2018  Austin Yuriy Poberezhnik.
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/

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