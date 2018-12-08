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
    std::cout << "> Location created.\n" << dataString 
              << "\n--------------------------------------------------------\n";

    std::string* tagMatches = new std::string[5];
    
    getRegexMatch("(\\[[^\\]]+:[^\\]]+\\])", dataString, tagMatches);

    std::map<std::string, std::string> stringLinks;
    stringLinks.insert(std::make_pair("Name", this->m_Name));
    stringLinks.insert(std::make_pair("Description", this->m_Description));
    

    delete[] tagMatches;
}

Location::Location(bool hostile, std::string name, std::string description,std::vector<Entity> npcs, std::vector<std::string> connected){

}

Location::~Location(){}
