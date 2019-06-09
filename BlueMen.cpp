
/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The blueMen class inherits from the Character class.
*******************************************************************************/

#include "BlueMen.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


//Constructor
blueMen::blueMen()
{
	srand(time(NULL));
	this->armor = 3;
	this->strengthPoints = 12;
}


blueMen::blueMen(std::string n)
{
	this->name = n; 
}

/*******************************************************************************
** Description:  This is a virtual funciton inherited from the Character class.
** It is used when making an attack on the opponent.
** The total value of the random die are set.
*******************************************************************************/
void blueMen::makeAttack()
{
	int roll1 = std::rand() % 10 + 1;
	int roll2 = std::rand() % 10 + 1;
	std::cout << "Blue Men attack\n " << std::endl;
	std::cout << "Roll 1: " << roll1 << std::endl;
	std::cout << "Roll 2: " << roll2 << std::endl;
	int total = roll1 + roll2;
	setTotalAttack(total);
	std::cout << std::endl;
}


int blueMen::getTotalAttack()
{
	return totalAttack;
}




/*******************************************************************************
** Description:  makeDefenseRoll is used after an attack.
** First is runs the specialAbility function and determins how many die are rolled.
** The total is then set
*******************************************************************************/

void blueMen::makeDefenseRoll()
{


	int special = specialAbility();

	if (special == 3)
	{
		int roll1 = std::rand() % 6 + 1;
		int roll2 = std::rand() % 6 + 1;
		int roll3 = std::rand() % 6 + 1;
		std::cout << "************************Blue Men Attack**********************\n " << std::endl;
		std::cout << "Roll 1: " << roll1 << std::endl;
		std::cout << "Roll 2: " << roll2 << std::endl;
		std::cout << "Roll 3: " << roll3 << std::endl;
		int total = roll1 + roll2 + roll3;
		setTotalDefense(total);
		std::cout << std::endl;
	}
	else if (special == 2)
	{
		int roll1 = std::rand() % 6 + 1;
		int roll2 = std::rand() % 6 + 1;

		std::cout << "Blue Men attack\n " << std::endl;
		std::cout << "Roll 1: " << roll1 << std::endl;
		std::cout << "Roll 2: " << roll2 << std::endl;

		int total = roll1 + roll2;
		setTotalDefense(total);
		std::cout << std::endl;
	}
	else if (special == 1)
	{
		int roll1 = std::rand() % 6 + 1;


		std::cout << "Blue Men attack\n " << std::endl;
		std::cout << "Roll 1: " << roll1 << std::endl;


		int total = roll1;
		setTotalDefense(total);
		std::cout << std::endl;
	}

}

/*******************************************************************************
** Description:  This is used during the characters defense.
** It takes in an int and uses that to caluclate the total damage.
*******************************************************************************/

void blueMen::makeDefense(int attack)
{

	//Medusa uses her special ability
	if (attack == 100)
	{
		std::cout << "\n\n=========Medusa just turned you to stone!!===========\n\n";
		strengthPoints = 0;

	}
	else
	{


		makeDefenseRoll();

		int oDamage = getTotalDefense();

		//Calculates the total 
		int damageTotal1 = attack - oDamage - armor;




		setDamageTotal(damageTotal1);


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

/*******************************************************************************
** Description:  This is used to determin how many die are rolled during the defense roll.
** It is based off the amount of strenthPoints the character has.
** For every 4 points lost, the character losses a die.
*******************************************************************************/

int blueMen::specialAbility()
{
	if (strengthPoints >= 12)
	{
		return 3;
	}
	else if (strengthPoints >= 8)
	{
		return 2;
	}
	else if (strengthPoints >= 4)
	{
		return 1;
	}

	return 0;
}


blueMen::~blueMen()
{
}
