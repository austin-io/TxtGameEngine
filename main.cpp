//  This file is not a part of the TxtGameEngine.

// TODO
/**  1. Implement parsing data strings functions:
*    	- Regex tag match
*    	- Regex name match
*    	- Compare name to attributes
*    	- Regex dot match or value match depending on the name
*
*    2. (DONE) Create input function that uses the Game::m_Commands list in TxtGameEngine/TxtGameEngine.h (also change the valid template function from TxtGameEngine/Utils.h to get and entire line instead of one word at a time)
*
*    3. Crap ton of Getters and Setters needed in all classes
*
*    4. Make more functions to load data from files for Quest, Item, Spell, and Entity classes in TxtGameEngine/TxtGameEngine.h
*
*    5. Create Status class that passively affects the Character
*
*    6. LoadSaveData function needed
*
*    7. Encounters needed
*
*    8. Character::levelUp() function needed
*/

// Regular Expressions
// Tag match: \\[[^\\]]+:[^\\]]+\\]
// Name match: ([^:\\[\\]]+):
// Dot match: \\.([^.\\]]+)
// Value match: :\\s([^\\]]+)

#include <iostream>

#include "TxtGameEngine/TxtGameEngine.h"

int main() {
    
    txt::Game* game = new txt::Game(true);
    std::string* t = new std::string[10];
    
    game->getRegexMatches("(\\[[^\\]]+:[^\\]]+\\])", "[name: bob][lvl: 14]caagv[e]", t);
    txt::Game::Location local("[Name: HELL]");
    std::cout << "t[0] = " << t[0] << std::endl;

    game->loadCreatures("Source/Creatures.txt");
    game->loadLocations("Source/Locations.txt");

    game->update(); // Mainloop

    delete game;

}
