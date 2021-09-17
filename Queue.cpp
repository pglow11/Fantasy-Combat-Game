/**********************************************************************************
** Program:	Queue.cpp
** Author: 	Patrick Glowacki
** Date: 	November 17, 2019
** Description: This is the Queue class implementation file.
************************************************************************************/

#include <iostream>
#include <string>

#include "Queue.hpp"
#include "inputValid.hpp" 

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**********************************************************************************
			Queue::Queue	
* This is the default constructor for Queue class. 
***********************************************************************************/
Queue::Queue()
{
	this->aliveHead = nullptr;
	this->deadHead = nullptr;
}

/**********************************************************************************
			Queue::~Queue	
* This is the default constructor for Queue class. 
***********************************************************************************/
Queue::~Queue()
{
	// Go through alive linked-list
	if (isAliveEmpty()) {
		
	}
	// Check if only 1 QueueNode
	else if (aliveHead->next == nullptr) {
		QueueNode *garbage = aliveHead;
		delete garbage;
	}
	else { // if more than one QueueNode
		// First break the circle
		QueueNode *tail = aliveHead->prev;
		tail->next = nullptr;
		QueueNode *nodePtr = aliveHead;  // Start at head of list
		while (nodePtr != nullptr)
		{
			// garbage keeps track of node to be deleted
			QueueNode *garbage = nodePtr;
			// Move on to next node, if any
			nodePtr = nodePtr->next;
			// Delete garbage
			delete garbage; 	 	
		}
	}
	
	// Go through dead linked-list
	if (isDeadEmpty()) {
		
	}
	// Check if only 1 QueueNode
	else if (deadHead->next == nullptr) {
		QueueNode *garbage = deadHead;
		delete garbage;
	}
	else { // if more than one QueueNode
		// First break the circle
		QueueNode *tail = deadHead->prev;
		tail->next = nullptr;
		QueueNode *nodePtr = deadHead;  // Start at head of list
		while (nodePtr != nullptr)
		{
			// garbage keeps track of node to be deleted
			QueueNode *garbage = nodePtr;
			// Move on to next node, if any
			nodePtr = nodePtr->next;
			// Delete garbage
			delete garbage; 	 	
		}
	}
}

/**********************************************************************************
			Queue::isAliveEmpty	
* This function checks if the queue for the alive linked-list is empty. If so, it 
* returns true; otherwise, return false. 
***********************************************************************************/
bool Queue::isAliveEmpty()
{
	bool output;

	if (aliveHead == nullptr) {
		output = true; 
	}
	else {
		output = false;
	}

	return output;
}

/**********************************************************************************
			Queue::isDeadEmpty	
* This function checks if the queue for the dead linked-list is empty. If so, it 
* returns true; otherwise, return false. 
***********************************************************************************/
bool Queue::isDeadEmpty()
{
	bool output;

	if (deadHead == nullptr) {
		output = true; 
	}
	else {
		output = false;
	}

	return output;
}

/**********************************************************************************
			Queue::addBack	
* This function takes a character pointer, creates a QueueNode with the input and
* appends the Character to the back of the alive queue.
***********************************************************************************/
void Queue::addBack(Character *ptr)
{
	if (isAliveEmpty()) {	
		aliveHead = new QueueNode(ptr, nullptr, nullptr);	
	}
	else if (aliveHead->next == nullptr) {
		aliveHead->next = new QueueNode(ptr, aliveHead, aliveHead);
		aliveHead->prev = aliveHead->next;
	} 
	else {
		QueueNode *temp = aliveHead->prev;
		aliveHead->prev = new QueueNode(ptr, temp, aliveHead);
		temp->next = aliveHead->prev;
	}
}

/**********************************************************************************
			Queue::addFront	
* This function takes a Character pointer, creates a QueueNode with the input and
* appends the Character to the front the dead queue list.
***********************************************************************************/
void Queue::addFront(Character *ptr)
{
	if (isDeadEmpty()) {	
		deadHead = new QueueNode(ptr, nullptr, nullptr);	
	}
	else if (deadHead->next == nullptr) {
		QueueNode *temp = deadHead;
		deadHead = new QueueNode(ptr, temp, temp);
		temp->next = deadHead; 
		temp->prev = deadHead;
	} 
	else {
		QueueNode *tempHead = deadHead;
		QueueNode *tempTail = tempHead->prev; 
		deadHead = new QueueNode(ptr, tempTail, tempHead);
		tempHead->prev = deadHead;
		tempTail->next = deadHead;
	}
}

/**********************************************************************************
			Queue::removeFrontLoser	
* This function removes the front QueueNode from the alive queue and adds it to the 
* front of the dead queue using the addFront function.
* The function has no parameters and does not return anything.
***********************************************************************************/
void Queue::removeFrontLoser()
{
	if (isAliveEmpty()) { // This check is not really necessary because this function would not be called without a node 
		cout << "Your lineup is empty." << endl;
	}
	else if (aliveHead->next == nullptr) {  // only 1 QueueNode
		QueueNode *garbage = aliveHead;
		addFront(aliveHead->charPtr);	
		delete garbage;
		aliveHead = nullptr;
	}
	else if (aliveHead->next == aliveHead->prev) {
		QueueNode *garbage = aliveHead;
		addFront(aliveHead->charPtr);
		aliveHead = aliveHead->prev;
		aliveHead->next = aliveHead->prev = nullptr;
		delete garbage;	
	}
	else {
		cout << "This is the problem." << endl;
		QueueNode *garbage = aliveHead;
		addFront(aliveHead->charPtr);
		QueueNode *temp = aliveHead->prev;
		aliveHead = aliveHead->next;
		delete garbage;	
		aliveHead->prev = temp;
		temp->next = aliveHead;
		temp = nullptr;
	}
}

/**********************************************************************************
			Queue::removeFrontWinner	
* This function removes the front QueueNode from the alive queue and adds it to the 
* back of the alive queue using the addFront function.
* The function has no parameters and does not return anything.
***********************************************************************************/
void Queue::removeFrontWinner()
{
	if (isAliveEmpty()) { // This check is not really necessary because this function would not be called without a node 
		cout << "Your lineup is empty." << endl;
	}
	else if (aliveHead->next == nullptr) {  // only 1 QueueNode
		// Do nothing
	}
	else {
		aliveHead = aliveHead->next;
	} 
}


/**********************************************************************************
			Queue::printAliveQueue	
* This function prints the alive queue. The function takes no paramters and does not return anything.
***********************************************************************************/
void Queue::printAliveQueue()
{
	if (isAliveEmpty()) {
		cout << "Your lineup is empty." << endl;
	}
	else if (aliveHead->next == nullptr) {
		cout << "Your lineup is: " << "Type: " << (aliveHead->charPtr)->getPlayerType() << " / " << 
						"Name: " << (aliveHead->charPtr)->getName() << endl;
	}
	else {
		QueueNode *temp = aliveHead;
		cout << endl;
		cout << "Your lineup is: " << endl;
		cout << "Type: " << (temp->charPtr)->getPlayerType() << " / " << 
			"Name: " << (temp->charPtr)->getName() << endl; 
		temp = temp->next;
		while (temp != aliveHead) {
			cout << "Type: " << (temp->charPtr)->getPlayerType() << " / " << 
				"Name: " << (temp->charPtr)->getName() << endl; 
			temp = temp->next;
		}
		cout << endl;
	}
}

/**********************************************************************************
			Queue::printDeadQueue	
* This function prints the dead queue. The function takes no paramters and does not return anything.
***********************************************************************************/
void Queue::printDeadQueue()
{
	if (isDeadEmpty()) {
		cout << "Your loser pile is empty." << endl;
	}
	else if (deadHead->next == nullptr) {
		cout << "Your loser pile is: " << "Type: " << (deadHead->charPtr)->getPlayerType() << " / " << 
						  "Name: " << (deadHead->charPtr)->getName() << endl;
	}
	else {
		QueueNode *temp = deadHead;
		cout << endl;
		cout << "Your loser pile is: " << endl;
		cout << "Type: " << (deadHead->charPtr)->getPlayerType() << " / " << 
			"Name: " << (deadHead->charPtr)->getName() << endl;
		temp = temp->next;
		while (temp != deadHead) {
			cout << "Type: " << (temp->charPtr)->getPlayerType() << " / " << 
				"Name: " << (temp->charPtr)->getName() << endl;
			temp = temp->next;
		}
		cout << endl;
	}
}

/**********************************************************************************
			Queue::getCharPtr
* This function returns the charPtr data member.
***********************************************************************************/
Character *Queue::getCharPtr() 
{
	return aliveHead->charPtr;
}
