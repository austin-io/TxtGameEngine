/** 
*   This file is a part of the TxtGameEngine.
*
*   The TxtGameEngine is a program used to create simple text-based RPG Adventure games.
*   Copyright (C) 2018  Austin Yuriy Poberezhnik.
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/

#ifndef UTILS_H
#define UTILS_H

#include "pch.h"

template <typename Value = int>
Value valid(std::string phrase = "");

void getRegexMatch(std::string regexStr, std::string dataString, std::string* &matchedStrings);

template<typename T>
void storeData(std::map<std::string, T> &mapData, std::string tagName, std::string dataStr);

void storeData(std::map<std::string, std::string> &mapData, std::string tagName, std::string dataStr);

#endif