/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The header file for the Character class.
*******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{

protected:
	int attack;
	int defense;
	int armor;
	int strengthPoints;
	int totalAttack;
	int totalDefense;
	int damageTotal;
	std::string name; 


public:
	Character();
	Character(int, int);
	int getArmor();
	void setName(std::string);
	std::string getName(); 
	void recovery(); 


	virtual int getDefensePoints();
	virtual int getStregthPoints();
	virtual void setStregthPoints(int);
	virtual void makeAttack();
	virtual void makeDefense(int);
	virtual  void setTotalAttack(int);
	virtual int getTotalAttack();
	virtual void setTotalDefense(int);
	virtual int getTotalDefense();
	virtual void setDamageTotal(int);
	virtual int getDamageTotal();



	~Character();
};

#endif
