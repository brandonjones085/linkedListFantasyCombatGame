
/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/20/2019
** Description:  The teamOneMenu function returns an int which is used to determine the users input
*******************************************************************************/

#include "teamOneMenu.hpp"
#include "validateMenu.hpp"

#include <iostream>


int teamOneMenu()
{
	
	int num1;

	std::cout << "Press 1 for Vampire\n";
	std::cout << "Press 2 for Barbarian\n";
	std::cout << "Press 3 for Blue Men\n";
	std::cout << "Press 4 for Medusa\n";
	std::cout << "Press 5 for Harry Potter\n";

	std::cin >> num1;
	

	
	return num1;


}
