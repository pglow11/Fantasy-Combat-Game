/**********************************************************************************
** Program: 	Barbarian.hpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Barbarian class specification file.
*********************************************************************************/

#pragma once

#include "Die.hpp"
#include "Character.hpp"

// Character class declaration 
class Barbarian : public Character
{
public:
	// Member functions
	Barbarian();
	virtual ~Barbarian();
	virtual bool special();
};

