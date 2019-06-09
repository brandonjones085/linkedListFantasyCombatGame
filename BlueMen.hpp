/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description: The header file for the blueMen class.
*******************************************************************************/

#include "Character.hpp"

#include <string>

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


class blueMen : public Character
{


public:
	blueMen();
	blueMen(std::string); 
	virtual void makeAttack();
	virtual void makeDefense(int);
	virtual int getTotalAttack();
	int specialAbility();
	void makeDefenseRoll();
	~blueMen();
};


#endif
