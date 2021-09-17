/**********************************************************************************
** Program: 	Gameplay.hpp
** Author: 	Patrick Glowacki
** Date: 	November, 10, 2019
** Description: This is the Gameplay class specification file.
*********************************************************************************/

#pragma once

#include "Character.hpp"
#include "Queue.hpp"

// Gameplay class declaration 
class Gameplay
{
private:
	// Data members
	int rounds;
	int maxTeamSize;
	int teamSize;
	int row;
	Queue player1;
	Queue player2;
	int p1Score;
	int p2Score;
	Character ***p1Matrix;
	Character ***p2Matrix;
public:
	// Member functions
	Gameplay();
	~Gameplay();
	void sizeMenu();
	void lineupMenu();
	void play();	
	void tournament();
	bool finishMenu();
};

