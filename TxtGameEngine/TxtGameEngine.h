#ifndef TXTGAMEENGINE_H
#define TXTGAMEENGINE_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <regex>

#include "Entity.h"
#include "Creature.h"
#include "Location.h"
#include "Utils.h"

namespace txt{

class Game{
protected:
    // Member Variables
    std::vector<Location> m_Locations;
    std::vector<Creature> m_Creatures;

    std::map<std::string, void(Game::*)(std::string)> m_Commands;

    bool m_IsRunning;

    // Private Methods
    template <typename T>
    void loadFile(std::string, std::vector<T>&);

    void m_Input();

    // Methods that are pointed to by m_Commands
    void m_Help(std::string);
    void m_Quit(std::string);

public:
    Game(bool);
    virtual ~Game();

    // Get input each loop
    void update();

    // Loading from files
    void loadSaveData(std::string);
    void loadLocations(std::string);
    void loadCreatures(std::string);

    //*
    // Regex Getters
    std::string* getTags(std::string, std::string*);
    std::string* getNames(std::string, std::string*);
    std::string* getElements(std::string, std::string*);
    std::string* getValue(std::string, std::string*);
    //*/

    // Getters
    bool getIsRunning();

    // Setters
    void setIsRunning(bool);

};

}

#endif

