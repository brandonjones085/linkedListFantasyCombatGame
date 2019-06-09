/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/20/2019
** Description:  The main file where the program is run
*******************************************************************************/

#include "menu.hpp"
#include "Game.hpp"

#include <iostream>

int main()
{
	int num = menu();
	if (num == 1)
	{
		Game g; 
		g.runGame(); 

	}
	else
	{
		std::cout << "\nGoodbye\n\n"; 
	}
}


