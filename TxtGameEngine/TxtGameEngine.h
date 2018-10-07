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

#ifndef TXTGAMEENGINE_H
#define TXTGAMEENGINE_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <regex>
#include <sstream>

#include "Utils.h"

namespace txt{

class Game{
public:
    // Sub-Classes
    class Entity;
    class Creature;
    class Character;
    class Location;
    class Spell;
    class Quest;
    class Item;

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
    void getRegexMatches(std::string, std::string, std::string*&);
    //*/

    // Getters
    bool getIsRunning();

    // Setters
    void setIsRunning(bool);

    // Sub-Classes
    class Entity{
    protected:
        int m_HealthPoints, 
            m_HealthPointMax, 
            m_ArmorClass, 
            m_Level, 
            m_Gold;
        
        // Stats
        int m_Strength,
            m_Dexterity,
            m_Constitution,
            m_Intelligence,
            m_Wisdom,
            m_Charisma;

        // Descriptors
        std::string m_Name;
        std::string m_Description;

        // Status m_Status;

        // Inventory Capacity
        std::vector<std::vector<Game::Item> >  m_Inventory;
        std::vector<std::vector<Game::Spell> > m_Spells;

    public:
        Entity(int hpMax = 15, int ac = 12, int lvl = 1, int gold = 100, int str = 10, int dex = 10, int con = 10, int intel = 10, int wis = 10, int cha = 10, std::string name = "Entity", std::string description = "N/A");
        
        virtual ~Entity();

        void attack(Entity);

        // Getters

        // Setters
    };

    class Character : public Entity {
    protected:
        int m_XP,
            m_NextLevel;

    public:
        Character();
        virtual ~Character();
        
        void levelUp();
    };

    class Creature : public Entity {
    protected:
        bool m_IsHostile;

    public:
        Creature();
        Creature(std::string);
        virtual ~Creature();
    };


    class Location {
    protected:
        bool m_HostileArea;

        std::string m_Name; 
        std::string m_Description;

        std::vector<Game::Entity> m_Npcs;
        std::vector<Game::Location> m_ConnectedAreas;

    public:
        // Default constructor
        Location();
        virtual ~Location();
        // Parsing constructor
        Location(std::string); 
        
        // Full constructor
        Location(bool hostile, std::string name, std::string description,std::vector<Game::Entity> npcs, std::vector<Game::Location> connected);
               
    };

    class Item {
    protected:
        std::string m_Name,
                    m_Description;

    public:
        Item();
        virtual ~Item();
    };

    class Spell {
        protected:
            std::string m_Name,
                        m_Description;
        public:
            Spell();
            virtual ~Spell();
    };

    class Quest{
        protected:
            std::string m_Name,
                        m_Description;

        public:
            Quest();
            virtual ~Quest();
    };

};

}

#endif

