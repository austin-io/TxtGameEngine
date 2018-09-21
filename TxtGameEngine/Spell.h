#ifndef SPELL_H
#define SPELL_H

#include <string>

class Spell {
protected:
    std::string m_Name,
                m_Description;
public:
    Spell();
    virtual ~Spell();
};

#endif