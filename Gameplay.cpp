/**********************************************************************************
** Program:	Gameplay.cpp
** Author: 	Patrick Glowacki
** Date: 	November 10, 2019
** Description: This is the Gameplay class implementation file.
************************************************************************************/

#include <iostream>
#include <string>

#include "Gameplay.hpp"
#include "Character.hpp" 
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp" 
#include "inputValid.hpp"
#include "Queue.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**********************************************************************************
			Gameplay::Gameplay	
* This is the default constructor for the Gameplay class. 
***********************************************************************************/
Gameplay::Gameplay()
{
	// Set data members
	this->rounds = 0;
	this->maxTeamSize = 20;
	this->teamSize = 0;
	this->p1Score = 0;
	this->p2Score = 0;
	this->row = 5;

	// Dynamically allocate memory for 2D array - p1Matrix
	p1Matrix = new Character**[row];
	p2Matrix = new Character**[row]; 
	for (int count = 0; count < row; count ++) {
		p1Matrix[count] = new Character*[maxTeamSize];
		p2Matrix[count] = new Character*[maxTeamSize];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < maxTeamSize; j++) {
			if (i == 0) {
				p1Matrix[i][j] = new Barbarian;
				p2Matrix[i][j] = new Barbarian;
			}
			else if (i == 1) {
				p1Matrix[i][j] = new Vampire;
				p2Matrix[i][j] = new Vampire;
			}
			else if (i == 2) {
				p1Matrix[i][j] = new BlueMen;
				p2Matrix[i][j] = new BlueMen;
			}
			else if (i == 3) {
				p1Matrix[i][j] = new Medusa;
				p2Matrix[i][j] = new Medusa;
			}
			else {
				p1Matrix[i][j] = new HarryPotter;
				p2Matrix[i][j] = new HarryPotter;
			}
		}
	}
}

/**********************************************************************************
			Gameplay::~Gameplay	
* This is the destructor for the Gameplay class. 
***********************************************************************************/
Gameplay::~Gameplay()
{
	for(int i = 0; i < row; i++) {
		for (int j = 0; j < maxTeamSize; j++) {
			delete p1Matrix[i][j];
			delete p2Matrix[i][j];
		}	

		delete [] p1Matrix[i];
		delete [] p2Matrix[i];
	} 
	delete [] p1Matrix;
	delete [] p2Matrix;
	p1Matrix = nullptr;
	p2Matrix = nullptr;
}

/**********************************************************************************
			Gameplay::sizeMenu	
* This is function provides the user the option to set the teamSize data member.
* The function returns nothing and takes no parameters. 
***********************************************************************************/
void Gameplay::sizeMenu()
{
	// Declare local variables
	int choice;

	// Print out to user	
	cout << endl;
	cout << "Please enter an integer for the size of your team.  Maximum size of " << maxTeamSize << endl;
	
	// Get user input	
	choice = inputValid();
	while (choice < 1 || choice > maxTeamSize) {
		cout << "Please choose a team size within the bounds of 1 and 20." << endl;
		choice = inputValid();
	}
	
	// Set teamSize data member
	teamSize = choice;
}

/**********************************************************************************
			Gameplay::lineupMenu	
* This is function provides the user the option to select the characters for their team.
* The function asks the user what character they want for a position in the lineup, 
* uses the addBack function to create a node and then sets the name of that Character using
* input from the user.   
* The function returns nothing and takes no parameters. 
***********************************************************************************/
void Gameplay::lineupMenu()
{
	// Declare local variables
	int choice;
	int p1Vampire = 0, p1Barbarian = 0, p1BlueMen = 0, p1Medusa = 0, p1HarryPotter = 0;
	int p2Vampire = 0, p2Barbarian = 0, p2BlueMen = 0, p2Medusa = 0, p2HarryPotter = 0;

	// Print out to user	
	cout << endl;
	cout << "Time to make your lineup of fighters." << endl;
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= teamSize; j++) {	
			cout << endl;
			cout << "Player " << i << " - Select your character for spot " << j << " in your lineup." << endl;
			cout << " 0. Barbarian" << endl;
			cout << " 1. Vampire" << endl;
			cout << " 2. Blue Men" << endl;
			cout << " 3. Medusa" << endl;
			cout << " 4. Harry Potter" << endl;  
			
			// Get user input	
			choice = inputValid();

			// Check to make sure user input from the menu
			while ((choice != 0) && (choice != 1) && (choice != 2) && (choice != 3) && (choice != 4)){
				cout << "Please select one of the 4 options." << endl;
				choice = inputValid();
			}

			// Get user input for Character name
			string tempName;
			cout << "What would you like to name this Character?" << endl;
			getline(cin, tempName); 	
			
			// Use loop counter to determine which player to addBack to
			if (i == 1) {  // player1
				switch (choice)  // Set name
				{
					case 0:	p1Matrix[0][p1Barbarian]->setName(tempName);
						break;
					case 1:	p1Matrix[1][p1Vampire]->setName(tempName);
						break;
					case 2: p1Matrix[2][p1BlueMen]->setName(tempName);
						break;
					case 3: p1Matrix[3][p1Medusa]->setName(tempName);
						break;
					case 4: p1Matrix[4][p1HarryPotter]->setName(tempName);
						break;
				}
				switch (choice) // Add QueueNode
				{
					case 0:	player1.addBack(p1Matrix[0][p1Barbarian]);
						p1Barbarian++;
						break;
					case 1:	player1.addBack(p1Matrix[1][p1Vampire]);
 						p1Vampire++;
						break;
					case 2: player1.addBack(p1Matrix[2][p1BlueMen]);
 						p1BlueMen++;
						break;
					case 3: player1.addBack(p1Matrix[3][p1Medusa]);
 						p1Medusa++;
						break;
					case 4: player1.addBack(p1Matrix[4][p1HarryPotter]);
 						p1HarryPotter++;
						break;
				}
			}
			else {  // player2
				switch (choice)  // Set name
				{
					case 0:	p2Matrix[0][p2Barbarian]->setName(tempName);
						break;
					case 1:	p2Matrix[1][p2Vampire]->setName(tempName);
						break;
					case 2: p2Matrix[2][p2BlueMen]->setName(tempName);
						break;
					case 3: p2Matrix[3][p2Medusa]->setName(tempName);
						break;
					case 4: p2Matrix[4][p2HarryPotter]->setName(tempName);
						break;
				}
				switch (choice)  // Add QueueNode
				{
					case 0:	player2.addBack(p2Matrix[0][p2Barbarian]);
						p2Barbarian++;
						break;
					case 1:	player2.addBack(p2Matrix[1][p2Vampire]);
 						p2Vampire++;
						break;
					case 2: player2.addBack(p2Matrix[2][p2BlueMen]);
 						p2BlueMen++;
						break;
					case 3: player2.addBack(p2Matrix[3][p2Medusa]);
 						p2Medusa++;
						break;
					case 4: player2.addBack(p2Matrix[4][p2HarryPotter]);
 						p2HarryPotter++;
						break;
				}
			}
		}
		cout << "Player " << i << " - Your lineup is set." << endl;  
	}
	cout << endl;
	cout << "Player 1 ";
	player1.printAliveQueue();
	cout << "Player 2 ";
	player2.printAliveQueue();
}

/**********************************************************************************
			Gameplay::play	
* This function uses a for loop to go through each round of "combat". 
* The function does not return anything and takes no parameters. 
***********************************************************************************/
void Gameplay::play()
{
	// Set player pointers using front QueueNode charPtr  
	Character *player1Ptr = player1.getCharPtr();
	Character *player2Ptr = player2.getCharPtr();
	string p1Name = player1Ptr->getName();
	string p2Name = player2Ptr->getName(); 

	// Combat
	rounds = 0;
	
	cout << "Player 1 " << player1Ptr->getPlayerType() << " " << p1Name << " vs. " << 
		"Player 2 " << player2Ptr->getPlayerType() << " " << p2Name << endl;

	while ((player1Ptr->getStrength() > 0) && (player2Ptr->getStrength() > 0)) {
		
		rounds++; // increment round data member 
		cout << "Round " << rounds << ":" << endl;  
	
		// Player 1 Attack
		int player1PtrAttack = player1Ptr->attack();
		int player2PtrDefense =  player2Ptr->defense();
		player2Ptr->damage(player1PtrAttack, player2PtrDefense);
		cout << p1Name << " total attack = " << player1PtrAttack << " / " <<
			p2Name << " total defense = " << player2PtrDefense << " / " <<
			p2Name << " strength = " << player2Ptr->getStrength() << endl;
	
		// Player 2 Attack	
		int player2PtrAttack = player2Ptr->attack();
		int player1PtrDefense =  player1Ptr->defense();
		player1Ptr->damage(player2PtrAttack, player1PtrDefense);
		cout << p2Name << " total attack = " << player2PtrAttack << " / " <<
			p1Name << " total defense = " << player1PtrDefense << " / " <<
			p1Name << " strength = " << player1Ptr->getStrength() << endl;
	}
	
	// Print round
	cout << endl;
	cout << "After " << rounds << " rounds:" << endl;	
	
	// Check strength
	if (player1Ptr->getStrength() <= 0) {
		cout << p1Name << " has been defeated. " << p2Name << " wins!"  << endl;
		player1.removeFrontLoser();
		player2Ptr->recovery();
		player2.removeFrontWinner();
		p2Score += 1;
	}
	else if (player2Ptr->getStrength() <= 0) {
		cout << p2Name << " has been defeated. " << p1Name << " wins!"  << endl;
		player2.removeFrontLoser();
		player1Ptr->recovery();
		player1.removeFrontWinner();
		p1Score += 1;
	}
	else if (player1Ptr->getStrength() <= 0 && player2Ptr->getStrength() <= 0) {
		cout << "Both players are down. It's a draw. Fight again." << endl;
	}
	else {
		// Do nothing
	} 		
	
}

/**********************************************************************************
			Gameplay::tournament	
* This is function controls the gameflow of the Fantasy Combat tournament. 
* It goes through each player of the lineup and uses the play function to perform "comabt".
* Winner of the combat round recover some of their lost health and are placed to the back of the winner's queue.
* Losers are moved to a seperate container and put in the front.
* The function does not return anything and takes no parameters. 
***********************************************************************************/
void Gameplay::tournament()
{
	bool p1Empty = player1.isAliveEmpty();
	bool p2Empty = player2.isAliveEmpty();
	int matchup = 0;

	while (!p1Empty && !p2Empty) {
		matchup++;  //increment matchup
		
		cout << endl;
		cout << "Matchup " << matchup << ": "; 
		
		// Combat for the front nodes in each player's queue 
		play();

		// Print Score
		cout << "Player 1 Score: " << p1Score << ", Player 2 Score: " << p2Score << endl; 		
	
		// Reset bool values
		p1Empty = player1.isAliveEmpty();
		p2Empty = player2.isAliveEmpty();
	}
	
	// Scoring
	cout << endl;
	int loser; 	
	if (p1Score > p2Score) {
		cout << "Player 1 has won the game with a score of " << p1Score << " to " << p2Score << endl;	
		loser = 2;
	}
	else if (p2Score > p1Score) {
		cout << "Player 2 has won the game with a score of " << p2Score << " to " << p1Score << endl;	
		loser = 1;
	}
	else {
		cout << "It's a draw." << endl;
		loser = 3;
	}

	// Print loser pile
	int choice;
	cout << endl;
	cout << "Would you like to print the loser pile?" << endl;
	cout << "1. Yes." << endl;
	cout << "2. No." << endl;
		
	// Get user input	
	choice = inputValid();

	// Check to make sure user input from the menu
	while ((choice != 1) && (choice != 2)){
		cout << "Please select one of the 2 options." << endl;
		choice = inputValid();
	}
	
	if (choice == 1) {
		switch (loser)
		{
			case 1: player1.printDeadQueue();
				break;
			case 2: player2.printDeadQueue();
				break;
			case 3: cout << "There's no loser pile because it was a draw." << endl;
				break;
		}
	}
	else {
		cout << "OK." << endl;
	}
	
}

/**********************************************************************************
			Gameplay::finishMenu
* This is function controls the end menu of the gameplay where the user can select to
* play again or exit. The function returns a bool and takes no parameters. 
***********************************************************************************/
bool Gameplay::finishMenu()
{
	// Declare local variables
	int choice;
	bool output;	

	// Print out to user	
	cout << endl;
	cout << "Would you like to play again or exit?" << endl;
	cout << "1. Play again." << endl;
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
