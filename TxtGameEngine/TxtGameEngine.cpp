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

#include "TxtGameEngine.h"

txt::Game::Game(bool isRunning){
    this->m_IsRunning = isRunning;
    this->m_Commands.insert(std::make_pair("help", &Game::m_Help));
    this->m_Commands.insert(std::make_pair("exit", &Game::m_Quit));
}

txt::Game::~Game(){}

void txt::Game::update(){

    while(this->getIsRunning()){
        Game::m_Input();
    }

}

void txt::Game::loadSaveData(std::string s){

}

bool txt::Game::getIsRunning(){
    return this->m_IsRunning;
}

void txt::Game::setIsRunning(bool isRunning){
    this->m_IsRunning = isRunning;
}

void txt::Game::loadLocations(std::string s){
    this->loadFile<Location>(s, this->m_Locations);
}

void txt::Game::loadCreatures(std::string s){
    this->loadFile<Creature>(s, this->m_Creatures);
}

void txt::Game::m_Input(){
    
    //std::string choice = valid<std::string>(""); // Get input string
    std::stringstream strStream;
    std::string choice;
    std::string choiceString;
    
    std::cout << "> ";
    getline(std::cin, choiceString);

    strStream << choiceString;
    strStream >> choice;
    getline(strStream, choiceString);

    auto command = this->m_Commands.find(choice); // Iterator for hash map
    
    // Checks if the users choice is within the hash map
    if(command == this->m_Commands.end()){
        // If the users choice is not found
	    std::cout << "That command doesn't work!\n"
		      << "Type \"help\" to see a list of options\n";

    } else{
        // If the users input string is found it runs the associated function
        (this->*(command->second))(choiceString);

    }
}

template <typename T>
void txt::Game::loadFile(std::string s, std::vector<T>& data){
    std::ifstream input;

    std::string tempString = "";
    std::string dataString = "";

    input.open(s);
    if(!input.is_open()){
        std::cout << s << ": file not found.\n";
    } else {
        while(getline(input, tempString)){
            if(tempString != "[end]"){
                dataString += tempString;
            } else {
                data.push_back(dataString);
                dataString = "";
            }

        }
    }

    input.close();
}

void txt::Game::m_Help(std::string args){
    std::cout << "Here's a list of Commands you can do:\n"
                 "  help    Displays this help page\n"
                 "  exit    Quits game without saving\n";
}

void txt::Game::m_Quit(std::string args){
    Game::setIsRunning(false);
}
