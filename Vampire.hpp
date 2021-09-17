/**********************************************************************************
** Program: 	Vampire.hpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Vampire class specification file.
*********************************************************************************/

#pragma once

#include "Die.hpp"
#include "Character.hpp"

// Character class declaration 
class Vampire : public Character
{
public:
	// Member functions
	Vampire();
	virtual ~Vampire();
	virtual int damage(int, int);
	virtual bool special();
};

