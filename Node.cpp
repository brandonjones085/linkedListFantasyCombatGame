/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/20/2019
** Description:  The Node the class is the main container for the characters. 
*******************************************************************************/



#include "Node.hpp"


Node::Node()
{
	this->player = nullptr; 
	this->next = nullptr; 
	this->prev = nullptr; 
}



Node::Node(Character *p)
{
	setPlayer(p);
}


void Node::setPlayer(Character *p)
{
	this->player = p; 
}

Node::Node(Character *p, Node *n, Node *pre)
{
	this->player = p; 
	this->next = n; 
	this->prev = pre; 
}



Character *Node::getPlayer()
{
	return player; 
}

Node *Node::getNext()
{
	return this->next; 
}

void Node::setNext(Node *n)
{
	this->next = n; 
}

Node *Node::getPrev()
{
	return this->prev; 
}

void Node::setPrev(Node *p)
{
	this->prev = p; 
}
