/**********************************************************************************
** Program:	Vampire.cpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Vampire class implementation file.
************************************************************************************/
#include <iostream>
#include "Vampire.hpp"

using std::cin;
using std::cout;
using std::endl;
	
/****************************************************************************************
*				Vampire::Vampire
* This is the default constructor for the Vampire class.
****************************************************************************************/
Vampire::Vampire()
{
	this->type = VAMPIRE;
	attackDie.setSides(12);
	this->numAttackDie = 1;
	defenseDie.setSides(6);
	this->numDefenseDie = 1;
	this->armor = 1;
	this->strength = 18;
	this->strengthTotal = 18;
}

/****************************************************************************************
*				Vampire::~Vampire
* This is the destructor for the Vampire class.
****************************************************************************************/
Vampire::~Vampire()
{
}

/****************************************************************************************
*				Vampire::damage
* This function overrides virtual function of the base class. This version uses the special
* function inside the damage function.  
****************************************************************************************/
int Vampire::damage(int attackInt, int defenseInt)
{
	int damage = 0;

	if (special()) {  // if special is active (true) 
		cout << "Vampire used his charm! The opponent's attack failed." << endl;
	}
	else { // otherwise, calc damage as normal
		// Check if attack is less than defense
		if ((defenseInt + armor)  >= attackInt) {
			damage = 0;
		} 
		else {
			damage = attackInt - defenseInt - armor;
			strength -= damage;
		}
	} 
	
	if (strength < 0) {
		strength = 0;
	}	
	
	return damage;
}
 
/****************************************************************************************
*				Vampire::special
* This function uses a random number generator to return a bool value.
****************************************************************************************/
bool Vampire::special()
{
	bool output;
	int random = rand() % 2 + 1;

	if (random == 1) {
		output = true;
	}
	else {
		output = false;
	}

	return output;
}

