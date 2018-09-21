#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string m_Name,
                m_Description;

public:
    Item();
    virtual ~Item();
};

#endif