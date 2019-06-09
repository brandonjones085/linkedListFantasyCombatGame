
/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The Barbarian class inherits from the Character class.
*******************************************************************************/

#include "Barbarian.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>


//CONSTRUCTOR
Barbarian::Barbarian()
{
	srand(time(NULL));
	this->armor = 0;
	this->strengthPoints = 12;
}

Barbarian::Barbarian(std::string n)
{
	this->name = n;
}


Barbarian::Barbarian(int a, int s)
{
	srand(time(NULL));
	this->armor = a;
	this->strengthPoints = s;
}


/*******************************************************************************
** Description:  This is a virtual funciton inherited from the Character class.
** It is used when making an attack on the opponent.
** The total value of the random die are set.
*******************************************************************************/

void Barbarian::makeAttack()
{
	int roll1 = std::rand() % 6 + 1;
	int roll2 = std::rand() % 6 + 1;
	std::cout << "************************Barbarian attack**********************" << std::endl;
	std::cout << "Roll 1: " << roll1 << std::endl;
	std::cout << "Roll 2: " << roll2 << std::endl;

	int total = roll1 + roll2;

	//sets the total
	setTotalAttack(total);
	std::cout << std::endl;

}

int Barbarian::getTotalAttack()
{
	return totalAttack;
}


/*******************************************************************************
** Description:  This takes in an int and uses that value to calculate the total damage during each cycle.
*******************************************************************************/
void Barbarian::makeDefense(int attack)
{
	//Medusa uses her special ability
	if (attack == 100)
	{
		std::cout << "\n\n=========Medusa just turned you to stone!!===========\n\n";
		strengthPoints = 0;

	}
	else {

	}


	//used for defense. 
	int roll1 = std::rand() % 6 + 1;
	int roll2 = std::rand() % 6 + 1;
	std::cout << "************************Barbarian Defense**********************" << std::endl;
	std::cout << "Roll 1: " << roll1 << std::endl;
	std::cout << "Roll 2: " << roll2 << std::endl;

	int oDamage = roll1 + roll2;

	//Calculates the total 
	int damageTotal1 = attack - oDamage - armor;



	//This runs if the total is a negative value. 
	if (damageTotal1 <= 0)
	{
		std::cout << "\nCharacter received no damage\n\n";
	}
	else
	{
		int total = getStregthPoints() - damageTotal1;
		

		setStregthPoints(total);
	}
}


Barbarian::~Barbarian()
{
}
