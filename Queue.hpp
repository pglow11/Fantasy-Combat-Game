/**********************************************************************************
** Program: 	Queue.hpp
** Author: 	Patrick Glowacki
** Date: 	November 17, 2019
** Description: This is the Queue class specification file.
*********************************************************************************/

#pragma once

#include "Character.hpp"

// Queue class declaration 
class Queue
{
protected:
	// Declare a struct for the QueueNode
	struct QueueNode
	{
		Character *charPtr;
		QueueNode *prev;
		QueueNode *next;
		QueueNode(Character *charPtr, QueueNode *prev, QueueNode *next)
		{
			this->charPtr = charPtr;
			this->prev = prev;
			this->next = next;
		}
	};
	// Data members for Queue class
	QueueNode *aliveHead;
	QueueNode *deadHead;
public:
	// Member functions
	Queue();
	~Queue();
	bool isAliveEmpty();
	bool isDeadEmpty();
	void addBack(Character*);
	void addFront(Character*);
	void removeFrontLoser();
	void removeFrontWinner();
	void printAliveQueue();
	void printDeadQueue();
	Character *getCharPtr();
};

