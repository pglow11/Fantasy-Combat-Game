/**********************************************************************************
** Program: 	Die.hpp
** Author: 	Patrick Glowacki
** Date: 	October 20, 2019
** Description: This is the Die class specification file.
*********************************************************************************/

#pragma once

// Die class declaration
class Die
{
protected:
	// Data members
	int N;
public:
	// Member function
	Die();
	Die(int);
	~Die();
	int roll();	
	int getSides();
	void setSides(int);
};
