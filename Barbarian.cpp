/**********************************************************************************
** Program:	Barbarian.cpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Barbarian class implementation file.
************************************************************************************/
#include <iostream>
#include "Barbarian.hpp"

using std::cin;
using std::cout;
using std::endl;
	
/****************************************************************************************
*				Barbarian::Barbarian
* This is the default constructor for the Barbarian class.
****************************************************************************************/
Barbarian::Barbarian()
{
	this->type = BARBARIAN;
	attackDie.setSides(6);
	this->numAttackDie = 2;
	defenseDie.setSides(6);
	this->numDefenseDie = 2;
	this->armor = 0;
	this->strength = 12;
	this->strengthTotal = 12;
}

/****************************************************************************************
*				Barbarian::~Barbarian
* This is the destructor for the Barbarian class.
****************************************************************************************/
Barbarian::~Barbarian()
{
}

/****************************************************************************************
*				Barbarian::special
* This is function overrides the virtual special function of the base case. It always 
* returns false because the Barbarian class has no special ability.
****************************************************************************************/
bool Barbarian::special()
{
	return false;
}
