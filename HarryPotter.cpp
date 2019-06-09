
/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The HarryPotter class inherits from the Character class.
*******************************************************************************/

#include "HarryPotter.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


HarryPotter::HarryPotter()
{
	srand(time(NULL));
	this->armor = 0;
	this->strengthPoints = 10;
}


HarryPotter::HarryPotter(std::string n)
{
	this->name = n; 
}

/*******************************************************************************
** Description:  This is a virtual funciton inherited from the Character class.
** It is used when making an attack on the opponent.
** The total value of the random die are set.
*******************************************************************************/
void HarryPotter::makeAttack()
{
	int roll1 = std::rand() % 6 + 1;
	int roll2 = std::rand() % 6 + 1;
	std::cout << "************************Harry Potter Attack**********************\n " << std::endl;
	std::cout << "Roll 1: " << roll1 << std::endl;
	std::cout << "Roll 2: " << roll2 << std::endl;
	int total = roll1 + roll2;
	setTotalAttack(total);

	std::cout << std::endl;
}

void HarryPotter::setCount(int i)
{
	count = i;
}

int HarryPotter::returnCount()
{
	return count;
}


int HarryPotter::getTotalAttack()
{
	return totalAttack;
}

/*******************************************************************************
** Description:  This is used during the characters defense.
** It takes in an int and uses that value to determine the total damage each round.
*******************************************************************************/
void HarryPotter::makeDefense(int attack)
{
	int c = returnCount();

	if (c < 2)
	{
		//Medusa turns to stone.
		if (attack == 100)
		{
			std::cout << "\n\n=========Medusa just turned you to stone!!===========\n\n";
			std::cout << "\n///////////Harry Potter Used His Hogwarts Ability\\\\\\\\n";
			setStregthPoints(20);
			c += c;
			setCount(c);

		}
		else
		{


			int roll1 = std::rand() % 6 + 1;
			int roll2 = std::rand() % 6 + 1;
			std::cout << "************************Harry Potter Defend**********************\n " << std::endl;
			std::cout << "Roll 1: " << roll1 << std::endl;
			std::cout << "Roll 2: " << roll2 << std::endl;
			int oDamage = roll1 + roll2;


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


				if (strengthPoints <= 0 && count < 1)
				{
					setStregthPoints(20);
					c += c;
					setCount(c);

					std::cout << "\n\n\nHarry Potter used Hoggwarts\n\n";
					total = getStregthPoints() - damageTotal1;
					
				}

				else
				{

					setStregthPoints(total);
				}

			}

		}


	}
}

HarryPotter::~HarryPotter()
{
}
