/**********************************************************************************
** Program: 	Medusa.hpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Medusa class specification file.
*********************************************************************************/

#pragma once

#include "Die.hpp"
#include "Character.hpp"

// Character class declaration 
class Medusa : public Character
{
public:
	// Member functions
	Medusa();
	virtual ~Medusa();
	virtual int attack();
	virtual bool special();
};

