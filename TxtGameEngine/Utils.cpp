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

template<>
void storeData<std::string>(std::map<std::string, std::string> &mapData, std::string tagName, std::string dataStr){

    std::string tempStr; 
    std::stringstream ss(dataStr, std::ios_base::app | std::ios_base::in | std::ios_base::out);

    if(mapData.find(tagName) != mapData.end()){
        while(std::getline(ss, tempStr)){
            mapData[tagName] += tempStr;
        }
        
        std::cout << tagName << ": " << mapData[tagName] << std::endl;
            
    }
}

template<>
void storeData<std::vector<std::string> > (std::map<std::string, std::vector<std::string> > &mapData, std::string tagName, std::string dataStr){

    // Stores all data in a stream
    std::stringstream ss(dataStr, std::ios_base::app | std::ios_base::in | std::ios_base::out);
    std::string tempStr;

    if(mapData.find(tagName) != mapData.end()){
        
        while(std::getline(ss, tempStr, ',')){
            (mapData[tagName]).push_back(tempStr);
        }

        for(auto i : mapData[tagName]){
            std::cout << tagName << ": "<< i << std::endl;
        }
    }
}