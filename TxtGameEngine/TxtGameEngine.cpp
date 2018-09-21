#include "TxtGameEngine.h"

txt::Game::Game(bool isRunning){
    this->m_IsRunning = isRunning;
    //this->m_Commands.push_back(std::make_pair("help", &Game::m_Help));
    //this->m_Commands.push_back(std::make_pair("exit", &quitGame));
}

txt::Game::~Game(){}

void txt::Game::update(){
    std::string choice;

    while(this->getIsRunning()){
        choice = valid<std::string>();
        
        if(choice == "exit"){
            this->setIsRunning(false);
        } else if(choice == "help"){
            std::cout << "Here's a list of commands you can do:\n"
            "-help    Displays this help page\n"
            "-exit    Quits the game without saving\n";
        }

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

/*
std::string* txt::Game::getTags(std::string dataString, std::string* matchedStrings){
    std::regex tags("\[[^\\]]+:[^\\]]+\\]");
    std::smatch matches;

    return matchedStrings;
}
*/