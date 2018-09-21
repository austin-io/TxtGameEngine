#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <regex>

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