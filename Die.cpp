/**********************************************************************************
** Program: 	Die.cpp
** Author: 	Patrick Glowacki
** Date: 	October 20, 2019
** Description: This is the Die class implementation file.
*********************************************************************************/

#include "Die.hpp"
#include <cstdlib>
#include <ctime>

/**********************************************************************************
				Die::Die
* Default constructor that initialuize N data member to 0.
*********************************************************************************/
Die::Die()
{
	this->N = 0;
	
	// Use the time function to get a seed value for srand
	unsigned seed;
	seed = time(0);
	srand(seed);

}

/**********************************************************************************
				Die::Die
* Constructor that initializes N data member using int parameter. 
*********************************************************************************/
Die::Die(int sides)
{
	this->N = sides;
}

/**********************************************************************************
				Die::~Die
* Destructor
*********************************************************************************/
Die::~Die()
{
	// intentionally left blank
}

/**********************************************************************************
				Die::roll
* This function uses random number generator to return an integer between 1 and N. 
*********************************************************************************/
int Die::roll()
{
	// Declare local variables
	int number;
	// Generate random number between 1 and N
	number = rand() % N + 1;

	return number;
}

/**********************************************************************************
				Die::getSides
* This function returns the N data member.
*********************************************************************************/
int Die::getSides()
{
	return this->N;
}

/**********************************************************************************
				Die::setSides
* This function sets the N data member.
*********************************************************************************/
void Die::setSides(int sides)
{
	this->N = sides;
}

