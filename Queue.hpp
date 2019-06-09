/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/20/2019
** Description:  The header file for the Queue class
*******************************************************************************/


#ifndef QUEUE_HPP
#define QUEUE_HPP


#include "Node.hpp"

#include <iostream>

class Queue : public Node
{
private: 
	Node *head = NULL; 
	Node *tail = NULL; 
	Node *ptr = NULL; 


public:
	Queue(); 
	
	Node *addNodeTail(Character*);
	
	void printQueue();
	
	void setNodeTail(Node*);
	
	void setNodeHead(Node*);
	bool isEmpty(); 
	void deleteHead(); 

	Character *getFirst(); 


	Node *getNodeHead();



};

#endif
