#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

class Character : public Entity {
protected:
    int m_XP,
        m_NextLevel;

public:
    Character();
    virtual ~Character();
    
    void levelUp();
};

#endif