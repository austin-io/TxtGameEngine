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

#include "Utils.h"
#include "Location.h"

Location::Location(){}

Location::Location(std::string dataString){
    
    // Total number of variables in the Location class
    const int NUMBER_OF_VARS = 5;
    
    // Arrays to hold all string key value pairs "tag: value"
    std::array<std::string, NUMBER_OF_VARS> tagMatches;
    std::array<std::string, NUMBER_OF_VARS> valueMatches;
    
    // Find all appropriate tags and values
    getRegexMatch("([^:\\[\\]]+):", dataString, tagMatches);
    getRegexMatch(":\\s([^\\]]+)", dataString, valueMatches);

    // Use std::map to connect tags to their corresponding variables
    std::map<std::string, std::string> stringLinks;
    stringLinks.insert(std::make_pair("Name", this->m_Name));
    stringLinks.insert(std::make_pair("Description", this->m_Description));
    
    std::map<std::string, bool> boolLinks;
    boolLinks.insert(std::make_pair("Hostile", this->m_HostileArea));

    std::map<std::string, std::vector<std::string> > vectorLinks;
    vectorLinks.insert(std::make_pair("Conected", this->m_ConnectedAreas));
    vectorLinks.insert(std::make_pair("Npc", this->m_Npcs));

    // Store all the values in the appropriate variables
    for(int i = 0; i < NUMBER_OF_VARS; i++){
        storeData<std::string>(stringLinks, tagMatches[i], valueMatches[i]);
        storeData(boolLinks, tagMatches[i], valueMatches[i]);
        storeData<std::vector<std::string> >(vectorLinks, tagMatches[i], valueMatches[i]);
    }

    std::cout << "Location Created Successfully\n--------------------------------------------------------\n"; 

}

Location::Location(bool hostile, std::string name, std::string description, std::vector<std::string> npcs, std::vector<std::string> connected){

}

Location::~Location(){}
