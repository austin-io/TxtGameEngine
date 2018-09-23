# TxtGameEngine

#### By Austin Poberezhnik

The TxtGameEngine is a simple and easy to use Game Engine designed to quickly create Old-School text-based RPG Adventure games. It can do this by loading data fom strictly formatted .txt files to generate all in-game objects.

The project does not need to be linked to any additional libraries and is multi-platform.

## Using the TxtGameEngine

To use the TxtGameEngine within your program, simply download the TxtGameEngine folder and #include "TxtGameEngine.h" in your main.cpp file. Create a Game object and call the appropriate loading functions to generate all the in-game Locations, NPC's, Creatures, and more. Be sure to follow the guide on how to correctly format your .txt files.

## Formatting .txt files

In-game objects can be generated through correctly formatted .txt files. Each object should have a list of attributes, called tags, which are contained within \[ square brackets \]. 

For example: your NPC file could have a character name John, such that \[Name: John\]. (Undefined variables are given default values). 

Some data will contain a list of other objects. These must be separated with a "." at the beginning and end of an objects name. Going back to John, he might have a few items that he's willing to sell, such that \[Items: .Health Potion.Cloak.Shortsword.\].

After all the data for a single object has been set, close it off with an \[end\] tag.

Contained within the Source/ folder of this repository is a list of example .txt files.

## License

This project with be licensed under the GNU General Public License.
