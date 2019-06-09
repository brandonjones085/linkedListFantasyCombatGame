#include "validateChar.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


void validateChar(char &i)
{
	i = tolower(i); 

	while (i != 'y' && i != 'n')
	{
		std::cout << "\nInvalid input! Try again: "; 
		std::cin >> i; 
		i = tolower(i); 
	}

}
