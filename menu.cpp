#include "menu.hpp"
#include "validateMenu.hpp"

#include <iostream>

int menu()
{
	int num1; 

	std::cout << "\n\nWelcome to the combat fantasy game\n\n" << std::endl; 
	std::cout << "What would you like to do?" << std::endl; 
	std::cout << "1. Play\n";
	std::cout << "2. Exit\n";

	std::cin >> num1; 
	validateMenu(num1); 
	return num1; 



}


