/**********************************************************************************
** Program:	Menu.cpp
** Author: 	Patrick Glowacki
** Date: 	November 19, 2019
** Description: This is the Menu class implementation file.
************************************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "inputValid.hpp"

using std::cin;
using std::cout;
using std::endl;

/**********************************************************************************
			Menu::Menu	
* This is the default constructor for Menu class 
***********************************************************************************/
Menu::Menu()
{
	// Do nothing
}

/**********************************************************************************
			Menu::~Menu	
* This is the destructor for Menu class 
***********************************************************************************/
Menu::~Menu()
{
	// Do nothing
}


/**********************************************************************************
			Menu::startMenu	
* This is function provides the user the option to
* 	1. Play Game
* 	2. Exit
* If theu choose to play, the function returns true to the main. Otherwise, false.
* The function takes no parameters. 
***********************************************************************************/
bool Menu::startMenu()
{
	// Declare local variables
	int choice;
	bool output;

	// Print out to user	
	cout << endl;
	cout << "Welcome to Fantasy Combat!" << endl;
	cout << "Select from the following options:" << endl;
	cout << "1. Play game." << endl;
	cout << "2. Exit." << endl;
	
	// Get user input	
	choice = inputValid();

	// Check to make sure user input from the menu
	while ((choice != 1) && (choice != 2)){
		cout << "Please select one of the 2 options." << endl;
		choice = inputValid();
	}
	
	switch (choice)
	{
		case 1: output = true;
			break;
		case 2: output = false;
			break;
	}

	return output;
}

