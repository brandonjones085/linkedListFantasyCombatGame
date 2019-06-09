
/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The Medusa class inherits from the Character class.
*******************************************************************************/

#include "Medusa.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>



Medusa::Medusa()
{
	srand(time(NULL));
	this->armor = 3;
	this->strengthPoints = 8;
}


Medusa::Medusa(std::string n)
{
	this->name = n; 
}

/*******************************************************************************
** Description: This is a virtual funciton inherited from the Character class.
** It is used when making an attack on the opponent.
** The total value of the random die are set.
*******************************************************************************/
void Medusa::makeAttack()
{
	int roll1 = std::rand() % 6 + 1;
	int roll2 = std::rand() % 6 + 1;
	std::cout << "************************Medusa Attack**********************\n " << std::endl;
	std::cout << "Roll 1: " << roll1 << std::endl;
	std::cout << "Roll 2: " << roll2 << std::endl;
	int total = roll1 + roll2;

	//This is used for the special ability
	if (total == 12)
	{
		total = 100;
	}

	setTotalAttack(total);
	std::cout << std::endl;

}

int Medusa::getTotalAttack()
{
	return totalAttack;
}


/*******************************************************************************
** Description:  This is used during the characters defense.
** It takes in an int and uses that value to determine the total damage each round.
*******************************************************************************/
void Medusa::makeDefense(int attack)
{
	//Medusa uses her special ability
	if (attack == 100)
	{
		std::cout << "\n\n=========Medusa just turned you to stone!!===========\n\n";
		strengthPoints = 0;

	}
	else
	{

		int roll1 = std::rand() % 6 + 1;

		std::cout << "************************Medusa Defense**********************\n " << std::endl;
		std::cout << "Roll 1: " << roll1 << std::endl;

		int total = roll1;

		int oDamage = total;

		//Calculates the total 
		int damageTotal1 = attack - oDamage - armor;



		//If damage is less than 0
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
}

Medusa::~Medusa()
{
}
