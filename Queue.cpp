/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/20/2019
** Description:  The Queue class
*******************************************************************************/



#include "Queue.hpp"


#include <iostream>

Queue::Queue()
{
	head = NULL; 
	tail = NULL; 
}


/*******************************************************************************
** Description:  Takes a Character object and adds it to the linked list
*******************************************************************************/
Node *Queue::addNodeTail(Character *n)
{
	Node *temp = new Node(n); 

	if (head == NULL)
	{
		 
		setNodeHead(temp); 
		
	}
	else
	{
		ptr = getNodeHead(); 

		temp->setNext(ptr); 


		Node *oTail = ptr->getPrev(); 

		temp->setPrev(oTail);

		oTail->setNext(temp);

		ptr->setPrev(temp);

		
	}


	return temp; 
}

//sets the head of the linked list
void Queue::setNodeHead(Node *n)
{
	if (n != nullptr)
	{
		if (isEmpty())
		{
			n->setPrev(n); 
			n->setNext(n); 
			
		}
		else
		{
			n->setNext(head); 
			n->setPrev(head->getPrev()); 
			head->setPrev(n); 
		}
	}

	head = n; 
}

//sets the tail for the linked list
void Queue::setNodeTail(Node *n)
{
	this->tail = n; 
}


Node *Queue::getNodeHead()
{
	return head; 
}

//determines if the queue is empty
bool Queue::isEmpty()
{
	return getNodeHead() == NULL; 
}




/*******************************************************************************
** Description:  Prints the queue
*******************************************************************************/
void Queue::printQueue()
{
	if (head == nullptr)
	{
		std::cout << "\nThe queue is empty\n"; 
	}
	else
	{
		Node *ptr = getNodeHead(); 

		do 
		{
			std::cout << ptr->getPlayer()->getName() << std::endl; 

			ptr = ptr->getNext(); 
		} while (ptr != getNodeHead()); 

	}
}


Character *Queue::getFirst()
{
	return head->getPlayer();
}

/*******************************************************************************
** Description:  Removes the head from the queue and 
*******************************************************************************/
void Queue::deleteHead()
{
	//checks if empty
	if (!isEmpty())
	{
		//gets the current head
		Node *n = getNodeHead();

		//gets the next node
		Node *next = n->getNext(); 

		//Checks if there is only one node
		if (next != n)
		{
			//next gets set as the new head
			next->setPrev(n->getPrev());
			Node *last = n->getPrev(); 
			last->setNext(next);
			head = next; 
		}
		else
		{
			//sets the head to null
			head = NULL; 
		}

		delete n; 

	}
}
