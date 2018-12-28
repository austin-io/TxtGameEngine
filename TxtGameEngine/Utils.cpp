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

template <typename Value = int>
Value valid(std::string phrase) {
	Value input;

	std::cout << phrase << "> ";
	std::cin >> input;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(9999999999, '\n');
		std::cout << "That input doesn't work! Try again \n";
		std::cout << phrase << "> ";
		std::cin >> input;
	}
	std::cin.ignore(9999999999, '\n');

	return input;
}

void getRegexMatch(std::string regexStr, std::string dataString, std::string* &matchedStrings){
    std::regex reg(regexStr);
    std::smatch matches;
    std::sregex_iterator CurrentMatch(dataString.begin(), dataString.end(), reg), LastMatch;
    for(int i = 0; CurrentMatch != LastMatch; i++){
        matches = *CurrentMatch;
        matchedStrings[i] = matches.str(1);
        //std::cout << "Regex: " << matchedStrings[i] << std::endl;
        CurrentMatch++;
    }
    
}

template<typename T>
void storeData(std::map<std::string, T> &mapData, std::string tagName, std::string dataStr){
    
    std::stringstream ss(dataStr, std::ios_base::app | std::ios_base::in | std::ios_base::out);

    if(mapData.find(tagName) != mapData.end()){
        ss >> std::boolalpha >> mapData[tagName];
        std::cout << tagName << ": "
            << mapData[tagName] << std::endl;
    }
}

void storeData(std::map<std::string, std::string> &mapData, std::string tagName, std::string dataStr){

    std::string tempStr; 
    std::stringstream ss(dataStr, std::ios_base::app | std::ios_base::in | std::ios_base::out);

    if(mapData.find(tagName) != mapData.end()){
        while(std::getline(ss, tempStr)){
            mapData[tagName] += tempStr;
        }
        
        std::cout << tagName << ": "
            << mapData[tagName] << std::endl;
            
    }
}