/**********************************************************************************
** Program: 	Character.hpp
** Author: 	Patrick Glowacki
** Date: 	November 8, 2019
** Description: This is the Character class specification file.
*********************************************************************************/

#pragma once

#include <string>
#include "Die.hpp"

using std::string;

// enum eclaration
enum PlayerType {BLANK, BARBARIAN, VAMPIRE, BLUEMEN, MEDUSA, HARRYPOTTER}; 

// Character class declaration 
class Character
{
protected:
	// Data members
	Die attackDie;
	Die defenseDie;
	int numAttackDie;
	int numDefenseDie;
	int armor;
	int strength;
	int strengthTotal;
	int lives;
	PlayerType type;
	string name;   	
public:
	// Member functions
	Character();
	virtual ~Character();
	virtual int attack();
	virtual int defense();
	virtual int damage(int, int);
	virtual bool special() = 0;
	int getArmor();
	int getStrength();
	void setStrength(int);
	int getLives();
	void setLives(int);
	int randomNum();
	string getPlayerType();	
	string getName();
	void setName(string);
	void recovery();
};

