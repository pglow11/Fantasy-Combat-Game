/**********************************************************************************
** Program:	Character.cpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Character class implementation file.
************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Character.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/****************************************************************************************
*				Character::Character
* This is the default constructor for Character class.
****************************************************************************************/
Character::Character()
{
	this->type = BLANK;
	this->name = "BLANK";
	this->lives = 0;

	// Use the time function to get a seed value for srand
	unsigned seed;
	seed = time(0);
	srand(seed);
}

/****************************************************************************************
*				Character::~Character
* This is the destructor for Character class.
****************************************************************************************/
Character::~Character()
{
}

/****************************************************************************************
*				Character::attack
* This function returns an integer using the Die class roll function.
****************************************************************************************/
int Character::attack()
{
	int num;
	int sum = 0;
	for (int i = 0; i < numAttackDie; i++) { // roll for each number of die  
		num = attackDie.roll(); // assign roll to variable
		sum += num; // sum up rolls
	}

	return sum;
}

/****************************************************************************************
*				Character::defense
* This function returns an integer using the Die class roll function.
****************************************************************************************/
int Character::defense()
{
	int num;
	int sum = 0;
	for (int i = 0; i < numDefenseDie; i++) { // roll for each number of die  
		num = defenseDie.roll(); // assign roll to variable
		sum += num; // sum up rolls
	}

	return sum;
}


/****************************************************************************************
*				Character::damage
* This function modifies the strength data member using two integers as parameters.
****************************************************************************************/
int Character::damage(int attackInt, int defenseInt)
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

	if (strength < 0) {
		strength = 0;
	}	

	return damage;
}

/****************************************************************************************
*				Character::getArmor
* This function gets the armor data member.
****************************************************************************************/
int Character::getArmor()
{
	return this->armor;
}

/****************************************************************************************
*				Character::getStrength
* This function gets the strength data member.
****************************************************************************************/
int Character::getStrength()
{
	return this->strength;
}

/****************************************************************************************
*				Character::setStrength
* This function sets the strength data member.
****************************************************************************************/
void Character::setStrength(int strength)
{
	this->strength = strength;
}

/****************************************************************************************
*				Character::getLives
* This function gets the lives data member.
****************************************************************************************/
int Character::getLives()
{
	return this->lives;
}

/****************************************************************************************
*				Character::setLives
* This function sets the strength data member.
****************************************************************************************/
void Character::setLives(int lives)
{
	this->lives = lives;
}

/**********************************************************************************
				Character::randomNum
* This helper function returns a random number.
*********************************************************************************/
int Character::randomNum()
{
	return rand();	
}

/**********************************************************************************
				Character::getPlayerType
* This function returns the type data member.
*********************************************************************************/
string Character::getPlayerType()
{
	string output;

	switch (type)
	{

		case BLANK:		output = "Blank";
					break;
		case BARBARIAN: 	output = "Barbarian";
					break;
		case VAMPIRE: 		output = "Vampire";
					break;
		case BLUEMEN:		output = "Blue Men";
					break;
		case MEDUSA:		output = "Medusa";
					break;
		case HARRYPOTTER: 	output = "Harry Potter";
					break;
	}
	
	return output;
}

/**********************************************************************************
				Character::getname
* This function returns the name data member.
*********************************************************************************/
string Character::getName()
{
	return this->name;
}

/**********************************************************************************
				Character::setName
* This function sets the name data member with a string parameter.
*********************************************************************************/
void Character::setName(string userName)
{
	this->name = userName;
}

/**********************************************************************************
				Character::recovery
* This function uses the roll function in the Die class to reset a percentage of the 
* character's strength data member. Using a 6-sided die means the Character can recover
* up to 60% of the strength lost during the combat. 
*********************************************************************************/
void Character::recovery()
{
	if (strength == strengthTotal) {
		cout << "The winner remains at full strength." << endl;
	}
	else {
		// Create local Die object
		Die recovDie(6);

		// Roll 6-sided die
		int roll = recovDie.roll();

		// Reset strength based on remaining strength
		int diff = strengthTotal - strength; 
		int percent = floor((diff * roll) / 10);
		strength += percent; 

		// Print results
		cout << "The winner has recovered to a strength of: " << strength << endl; 	
	}
}
















	
