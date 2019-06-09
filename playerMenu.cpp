#include "playerMenu.hpp"
#include "validateMenu.hpp"
#include "Game.hpp"
#include <iostream>

class Game;


int attackMenu()
{
	Game g;

	int num1;

	std::cout << "\n\nFirst you need to choose the attacker\n\n" << std::endl;
	std::cout << "Press 1 for Vampire\n";
	std::cout << "Press 2 for Barbarian\n";
	std::cout << "Press 3 for Blue Men\n";
	std::cout << "Press 4 for Medusa\n";
	std::cout << "Press 5 for Harry Potter\n";
	std::cin >> num1;
	validateMenu(num1);
	return num1;


}
