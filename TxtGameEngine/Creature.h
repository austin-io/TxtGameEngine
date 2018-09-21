#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"

class Creature : public Entity {
protected:
    bool m_IsHostile;

public:
    Creature();
    Creature(std::string);
    virtual ~Creature();
};

#endif