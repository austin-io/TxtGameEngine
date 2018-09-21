/**
*
*   Austin Poberezhnik ~ alias@gmail.com
*   
*   TxtGameEngine
*
*/

// TODO
/**  Plan for parsing data strings:
*    - Regex tag match
*    - Regex name match
*    - Compare name to attributes
*    - Regex dot match or value match depending on the name
*/

// Regular Expressions
// Tag match: \[[^\]]+:[^\]]+\]
// Name match: ([^:\[\]]+):
// Dot match: \.([^.\]]+)
// Value match: :\s([^]]+)

#include <iostream>

#include "TxtGameEngine/TxtGameEngine.h"

int main() {
    
    txt::Game* game = new txt::Game(true);

    game->loadCreatures("Source/Creatures.txt");
    game->loadLocations("Source/Locations.txt");

    game->update(); // Mainloop

    delete game;

}