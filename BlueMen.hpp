/**********************************************************************************
** Program: 	BlueMen.hpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the BlueMen class specification file.
*********************************************************************************/

#pragma once

#include "Die.hpp"
#include "Character.hpp"

// Character class declaration 
class BlueMen : public Character
{
public:
	// Member functions
	BlueMen();
	virtual ~BlueMen();
	virtual int damage(int, int);
	virtual bool special();
};

