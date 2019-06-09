/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The vampire class inherits from the Character class.
*******************************************************************************/


#include "Vampire.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


Vampire::Vampire()
{
	srand(time(NULL));
	this->armor = 1;
	this->strengthPoints = 18;

}


Vampire::Vampire(std::string n)
{
	this->name = n; 
}

/*******************************************************************************
** Description:  This is a virtual funciton inherited from the Character class.
** It is used when making an attack on the opponent.
** The total value of the random die are set.
*******************************************************************************/

void Vampire::makeAttack()
{
	int roll1 = std::rand() % 12 + 1;
	std::cout << "************************Vampire Attack**********************\n " << std::endl;
	std::cout << "Roll 1: " << roll1 << std::endl;
	setTotalAttack(roll1);

	std::cout << std::endl;
}


int Vampire::getTotalAttack()
{
	return totalAttack;
}


/*******************************************************************************
** Description:  This is used for the defense of an opponents attack
*******************************************************************************/
void Vampire::makeDefense(int attack)
{

	int num = specialAbility();

	//Medusa uses her special ability and vampire doesn't use charm
	if (attack == 100 && num != 1)
	{
		std::cout << "\n\n=========Medusa just turned you to stone!!===========\n\n";
		strengthPoints = 0;

	}
	else
	{

		int roll1 = std::rand() % 6 + 1;
		std::cout << "************************Vampire Defense**********************\n " << std::endl;
		std::cout << "Roll 1: " << roll1 << std::endl;

		int oDamage = roll1;

		//Calculates the total 
		int damageTotal1 = attack - oDamage - armor;



		if (damageTotal1 <= 0)
		{
			std::cout << "\nCharacter received no damage\n\n";
		}
		else
		{
			if (num == 1)
			{
				std::cout << "\nVampire used charm to receive no damage\n";
			}
			else
			{
				int total = getStregthPoints() - damageTotal1;
				

				setStregthPoints(total);

			}
		}
	}

}

int Vampire::specialAbility()
{
	int num = std::rand() % 2 + 1;

	//no damage
	if (num == 1)
	{

		return 1;
	}
	//receives damage
	else if (num == 2)
	{
		return 2;
	}

	return 0;
}

Vampire::~Vampire()
{
}
