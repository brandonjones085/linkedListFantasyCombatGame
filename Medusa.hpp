
/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The header file for the Barbarian class.
*******************************************************************************/

#include "Character.hpp"

#include <string>


#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
public:
	Medusa();
	Medusa(std::string); 
	virtual void makeAttack();
	virtual void makeDefense(int);

	virtual int getTotalAttack();
	
	~Medusa();
};


#endif
