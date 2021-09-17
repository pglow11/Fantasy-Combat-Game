/******************************************************************
** Program:	inputValid.cpp
** Auhtor:	Patrick Glowacki
** Date:	September 29, 2019
** Description: This program is input validation for the project1Main 
**		program.
******************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/****************************************************************************************
			inputValid
* This function valididates user input with full error checking 
* for an integer. The basis for this code comes from  the following site:
learncpp.com/cpp-tutorial/5-10-stdcin-extraction-and-dealing-with-invalid-text-input/
****************************************************************************************/

int inputValid()
{
	while (true) // Loop should continue until user enters valid input
	{
		int userInt;
		cin >> userInt;

		// Check for failed extraction
		if (cin.fail())
		{
			cin.clear(); // Returns back to normal operation mode
			cin.ignore(32767, '\n'); // Removes bad input
			cout << "Please enter a valid input." << endl;
		}
		else if (cin.peek() != '\n') // Check to make sure the value is an integer
		{
			cin.clear(); // Returns back to normal operation mode
			cin.ignore(32767, '\n'); // Removes bad input
			cout << "You did not enter an integer or entered more than one." << endl;
		}
		else
		{
			cin.ignore(32767, '\n'); // Removes bad input

			return userInt;
		}
	}
		
}

