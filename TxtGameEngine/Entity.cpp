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

#include "Entity.h"

Entity::Entity(int hpMax, int ac, int lvl, int gold, int str, int dex, int con, int intel, int wis, int cha, 
    std::string name, std::string description)
// Member initialization
: m_HealthPointMax(hpMax), m_ArmorClass(ac), m_Level(lvl), m_Gold(gold), m_Strength(str), m_Dexterity(dex), m_Constitution(con), m_Intelligence(intel), m_Wisdom(wis), m_Charisma(cha), m_Name(name), m_Description(description){}

Entity::~Entity(){}

