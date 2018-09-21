#include "Entity.h"

Entity::Entity(int hpMax, int ac, int lvl, int gold, int str, int dex, int con, int intel, int wis, int cha, 
    std::string name, std::string description)
// Member initialization
: m_HealthPointMax(hpMax), m_ArmorClass(ac), m_Level(lvl), m_Gold(gold), m_Strength(str), m_Dexterity(dex), m_Constitution(con), m_Intelligence(intel), m_Wisdom(wis), m_Charisma(cha), m_Name(name), m_Description(description){}

Entity::~Entity(){}

