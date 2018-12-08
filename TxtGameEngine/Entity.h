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

#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"
#include "Spell.h"
#include "Item.h"

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
    std::vector<std::vector<Item> >  m_Inventory;
    std::vector<std::vector<Spell> > m_Spells;

public:
    Entity(int hpMax = 15, int ac = 12, int lvl = 1, int gold = 100, int str = 10, int dex = 10, int con = 10, int intel = 10, int wis = 10, int cha = 10, std::string name = "Entity", std::string description = "N/A");
    
    virtual ~Entity();

    void attack(Entity);

    // Getters

    // Setters
};

#endif