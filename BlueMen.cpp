/**********************************************************************************
** Program:	BlueMen.cpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the BlueMen class implementation file.
************************************************************************************/
#include <iostream>
#include "BlueMen.hpp"

using std::cin;
using std::cout;
using std::endl;
	
/****************************************************************************************
*				BlueMen::BlueMen
* This is the default constructor for the BlueMen class.
****************************************************************************************/
BlueMen::BlueMen()
{
	this->type = BLUEMEN;
	attackDie.setSides(10);
	this->numAttackDie = 2;
	defenseDie.setSides(6);
	this->numDefenseDie = 3;
	this->armor = 3;
	this->strength = 12;
	this->strengthTotal = 12;
}

/****************************************************************************************
*				BlueMen::~BlueMen
* This is the destructor for the BlueMen class.
****************************************************************************************/
BlueMen::~BlueMen()
{
}

/****************************************************************************************
*				BlueMen::damage
* This function overrides virtual function of the base class. This version uses the special
* function inside the damage function.  
****************************************************************************************/
int BlueMen::damage(int attackInt, int defenseInt)
{
	int damage = 0;
	// Check if attack is less than defense
	if ((defenseInt + armor)  >= attackInt) {
		damage = 0;
	} 
	else {
		damage = attackInt - defenseInt - armor;
		strength -= damage;
	}

	// Determine numDefenseDie based on strength
	if (strength >= 9) {
		numDefenseDie = 3;
	} 
	else if (strength >= 5) {
		numDefenseDie = 2;
	}
	else {
		numDefenseDie = 1;
	}

	cout << "Blue Men Mob - You have " << numDefenseDie << " defense die." << endl;
	
	if (strength < 0) {
		strength = 0;
	}	
	
	return damage;
}

/****************************************************************************************
*				BlueMen::special
* This function always returns false because the BlueMen special ability to handled in the
* damage function. 
****************************************************************************************/
bool BlueMen::special()
{
	return false;
}

