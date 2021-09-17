/**********************************************************************************
** Program:	Medusa.cpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Medusa class implementation file.
************************************************************************************/
#include <iostream>
#include "Medusa.hpp"

using std::cin;
using std::cout;
using std::endl;
	
/****************************************************************************************
*				Medusa::Medusa
* This is the default constructor for the Medusa class.
****************************************************************************************/
Medusa::Medusa()
{
	this->type = MEDUSA;
	attackDie.setSides(6);
	this->numAttackDie = 2;
	defenseDie.setSides(6);
	this->numDefenseDie = 1;
	this->armor = 3;
	this->strength = 8;
	this->strengthTotal = 8;
}

/****************************************************************************************
*				Medusa::~Medusa
* This is the destructor for the Medusa class.
****************************************************************************************/
Medusa::~Medusa()
{
}

/****************************************************************************************
*				Medusa::attack
* This function overrides virtual attack function of the base class. This version determines 
* if Medusa rolled a 12 and if so, the attack integer returned is 100 to ensure it kills.
* However, the Vampire's charm trumps MEdusa's glare, which is handled in the Vampire class.
****************************************************************************************/
int Medusa::attack()
{
	int num;
	int sum = 0;
	for (int i = 0; i < numAttackDie; i++) { // roll for each number of die  
		num = attackDie.roll(); // assign roll to variable
		sum += num; // sum up rolls
	}

	// Check if glare special ability it active
	if (sum == 12) {
		cout << "Medusa used her glare! The opponent has turned to stone." << endl;
		sum = 100; // set to number that will always beat the opponent's defense value 
	}
	
	return sum;
}

/****************************************************************************************
*				Medusa::special
* This function always returns false because the Medusa special ability to handled in the
* attack function. 
****************************************************************************************/
bool Medusa::special()
{
	return false;
}

