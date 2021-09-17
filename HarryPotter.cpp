/**********************************************************************************
** Program:	HarryPotter.cpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the HarryPotter class implementation file.
************************************************************************************/
#include <iostream>
#include "HarryPotter.hpp"

using std::cin;
using std::cout;
using std::endl;
	
/****************************************************************************************
*				HarryPotter::HarryPotter
* This is the default constructor for the HarryPotter class.
****************************************************************************************/
HarryPotter::HarryPotter()
{
	this->type = HARRYPOTTER;
	attackDie.setSides(6);
	this->numAttackDie = 2;
	defenseDie.setSides(6);
	this->numDefenseDie = 2;
	this->armor = 0;
	this->strength = 10;
	this->strengthTotal = 10;
}

/****************************************************************************************
*				HarryPotter::~HarryPotter
* This is the destructor for the HarryPotter class.
****************************************************************************************/
HarryPotter::~HarryPotter()
{
}

/****************************************************************************************
*				HarryPotter::damage
* This function overrides virtual function of the base class. This version uses the special
* function inside the damage function.  
****************************************************************************************/
int HarryPotter::damage(int attackInt, int defenseInt)
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

	if (lives == 0 && strength <= 0) {
		cout << "Harry Potter has recovered!" << endl;
		strength = 20;
		lives = 1;
	}
	
	if (strength < 0) {
		strength = 0;
	}	

	return damage;
}
 
/****************************************************************************************
*				HarryPotter::special
* This function always returns false because the special ability is handled in the 
* damage function.
****************************************************************************************/
bool HarryPotter::special()
{
	return false;
}

