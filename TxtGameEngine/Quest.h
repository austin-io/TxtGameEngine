#ifndef QUEST_H
#define QUEST_H

#include <iostream>

class Quest{
protected:
    std::string m_Name,
                m_Description;

public:
    Quest();
    virtual ~Quest();
};

#endif