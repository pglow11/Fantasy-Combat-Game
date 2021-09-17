/**********************************************************************************
** Program: 	HarryPotter.hpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the HarryPotter class specification file.
*********************************************************************************/

#pragma once

#include "Die.hpp"
#include "Character.hpp"

// Character class declaration 
class HarryPotter : public Character
{
public:
	// Member functions
	HarryPotter();
	virtual ~HarryPotter();
	virtual int damage(int, int);
	virtual bool special();
};

