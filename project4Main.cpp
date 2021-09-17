/**********************************************************************************
** Program:	project4Main.cpp
** Author: 	Patrick Glowacki
** Date: 	November 23, 2019
** Description: This program runs controls the Gameplay class. 
************************************************************************************/

#include <iostream>

#include "Gameplay.hpp"
#include "Menu.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	// Create Menu object
	Menu menu1;
	
	// Run game1 
	bool running = menu1.startMenu();
	while (running) {
		//Create Gameplay object
		Gameplay game1;
		
		// Run game1
		game1.sizeMenu();
		game1.lineupMenu();
 	 	game1.tournament();		
		running = game1.finishMenu();
	}
	
	return 0;
}

