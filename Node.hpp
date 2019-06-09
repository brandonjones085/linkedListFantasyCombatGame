/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/20/2019
** Description:  The header file for the Node class
*******************************************************************************/


#ifndef NODE_HPP
#define NODE_HPP

#include "Character.hpp"
#include <iostream>

class Node
{
protected: 

	Character *player; 
	Node *next = NULL; 
	Node *prev = NULL; 
		

public: 
	Node(); 
	Node(Character *p);
	
	Node(Character*, Node*, Node*); 

	Node *getNext(); 
	void setNext(Node*); 
	Node *getPrev();
	void setPrev(Node*); 
	void setPlayer(Character*); 

	Character *getPlayer(); 
	
};


#endif // !NODE_HPP
