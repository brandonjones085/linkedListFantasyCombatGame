/*******************************************************************************
** Author:       Brandon Jones
** Date:         05/10/2019
** Description:  The Game class controls the flow of the whole program.
*******************************************************************************/


#include "Game.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "validateInt.hpp"
#include "Queue.hpp"
#include "teamOneMenu.hpp"
#include "validateChar.hpp"


#include <iostream>
#include <cstdlib>
#include <string>

Game::Game()
{
teamOne = NULL; 
teamTwo = NULL; 
losers = NULL; 
}


/*******************************************************************************
** Description:  This controls the whole flow of the game. ]
** It first runs the menus and determes the characters for the attacker and opponents
** Then runs through the attacks and defense and determines if the characters still have positive values.
** If the strengthPoints drop below 0, the game ends.
*******************************************************************************/

void Game::runGame()
{
	int teamOnePoints = 0; 
	int teamOneNumPlayers;
	std::cout << "\nPlease enter the number of players for team one ";
	std::cin >> teamOneNumPlayers;
	validateInt(teamOneNumPlayers); 
	setNumTeamOne(teamOneNumPlayers); 

	int teamTwoPoints = 0; 
	int teamTwoNumPlayers;
	std::cout << "\nPlease enter the number of players for team two ";
	std::cin >> teamTwoNumPlayers;
	validateInt(teamTwoNumPlayers); 
	setNumTeamTwo(teamTwoNumPlayers); 


	game = true; 
	int round = 1;

	//Queue for both players and the loser
	teamOne = new Queue;
	teamTwo = new Queue; 
	losers = new Queue; 
	Node *l = losers->addNodeTail(nullptr);
	
	


	int t1 = 0;

	//Loops through number of players and sets players, then asks for their name
	for(int i = 1; i <= teamOneNumPlayers; i++)
	{
		Node *n1 = teamOne->addNodeTail(nullptr);
		
		
		std::string name = " ";
		std::cout << "\nWho would you like to choose for player number " << i << std::endl; 
		t1 = teamOneMenu();

		if (t1 == 1)
		{
			//vampire
			n1->setPlayer(new Vampire); 
		}
		else if (t1 == 2)
		{
			//barbarian
			n1->setPlayer(new Barbarian);
		}
		else if (t1 == 3)
		{
			//bluemen
			n1->setPlayer(new blueMen);
		}
		else if (t1 == 4)
		{
			//medusa
			n1->setPlayer(new Medusa);
		}
		else if(t1 ==5)
		{
			//harry potter
			n1->setPlayer(new HarryPotter);
		}

		//Sets their name
		std::cout << "\nWhat would you like their name to be? "; 
		std::cin.ignore(); 
		std::getline (std::cin, name); 
		
		n1->getPlayer()->setName(name); 

	}


	std::cout << "\n\nNow for team two..." << std::endl; 

	//Loops through number of players and sets players, then asks for their name
	for (int i = 1; i <= teamTwoNumPlayers; i++)
	{
		//Adds noeds to end of queue
		Node *n2 = teamTwo->addNodeTail(nullptr);
		
		std::string name = " ";
		
		std::cout << "\nWho would you like to choose for player number " << i << std::endl;
		int t2 = teamOneMenu(); 

		if (t2 == 1)
		{
			//Vampire
			n2->setPlayer(new Vampire);
		}
		else if (t2 == 2)
		{
			//Barbarian
			n2->setPlayer(new Vampire); 
		}
		else if (t2 == 3)
		{
			//Bluemen
			n2->setPlayer(new blueMen); 
		}
		else if (t2 == 4)
		{
			//medusa
			n2->setPlayer(new Medusa);
		}
		else if (t2 == 5)
		{
			//harry potter
			n2->setPlayer(new HarryPotter); 
		}

		//Sets their name
		std::cout << "\nWhat would you like their name to be? ";
		std::cin.ignore();
		std::getline(std::cin, name);

		n2->getPlayer()->setName(name);//Sets the name


	}

	std::cout << std::endl; 


	//Displays the names for both the teams
	std::cout << "\nThe team one players are...\n"; 
	teamOne->printQueue(); 
	std::cout << std::endl; 
	std::cout << "\nThe team one players are...\n";
	teamTwo->printQueue(); 
	game = true; 

	std::cout << std::endl;
	std::cout << std::endl; 
	std::cout << "Press enter to continue...\n"; 

	//Begins the game while there are nodes in the queue

	do {


		//Pauses game between rounds
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore();

		//Displays both the players for that tournament
		std::cout << teamOne->getFirst()->getName() << " versus " << teamTwo->getFirst()->getName() << std::endl;

		std::cout << "\nThe tournament has begun\n";


		//Makes the attack
		teamOne->getFirst()->makeAttack();

		int aAttack = teamOne->getFirst()->getTotalAttack();

		teamTwo->getFirst()->makeDefense(aAttack);

		//Shows all the totals
		std::cout << "\nAttacker strength " << teamOne->getFirst()->getStregthPoints() << std::endl;
		std::cout << "Attacker armor " << teamOne->getFirst()->getArmor() << std::endl;
		std::cout << "\nOpponent strength " << teamTwo->getFirst()->getStregthPoints() << std::endl;
		std::cout << "Opponent armor " << teamTwo->getFirst()->getArmor() << std::endl;


		std::cout << "\n\nRound number: " << round << std::endl;

		//increments round by one
		round++;


		int oStrength = teamTwo->getFirst()->getStregthPoints();

		//If the strength drops below 1
		if (oStrength < 1)
		{
			//Player that lost
			std::cout << teamTwo->getFirst()->getName() << " lost\n";
			teamOnePoints += 1; 


			std::cout << "The round is over!\n";
			std::cout << "\nTeam one points: " << teamOnePoints;
			std::cout << "\nTeam two points: " << teamTwoPoints;

			l->setPlayer(teamTwo->getFirst());//Adds to loser queue


			teamOne->getFirst()->recovery(); //recovers the player that won

			teamOne->setNodeTail(teamOne->getNext()); //Sets the winner to the back of the queue

			//Removes the player from the head
			teamOne->deleteHead();
			teamTwo->deleteHead();


			//If the teamOne returns true for being empty
			if (teamOne->isEmpty())
			{
                                game = false; 
				std::cout << "\nTeam one is out of players\n";
				break; 
			}

			//If the teamTwo returns true for being empty
			else if (teamTwo->isEmpty())
			{
				game = false; 
				std::cout << "\nTeam two is out of players\n";
				break;  
			
			}
			else
			{
				std::cout << "\n.........................................................................\n";
				std::cout << ".........................................................................\n";
				std::cout << ".........................................................................\n";
				std::cout << ".........................................................................\n";
				std::cout << ".........................................................................\n";
				std::cout << ".........................................................................\n";
				std::cout << ".........................................................................\n";
				std::cout << "\nThe next tournament is...\n";
				
				round = 1;
			}


		}


		//Starts second stage
		std::cout << "\n\nPlease enter for the opponent to attack now\n" << std::endl;

		std::cout << "-------------------------------------------------------------------" << std::endl;
		std::cout << teamOne->getFirst()->getName() << " versus " << teamTwo->getFirst()->getName() << std::endl;
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore();
		std::cout << "Round number " << round << std::endl;

		//teamTwo attacks
		teamTwo->getFirst()->makeAttack();


		int oAttack = teamTwo->getFirst()->getTotalAttack();

		teamOne->getFirst()->makeDefense(oAttack);



		//Shows new totals
		std::cout << "\nAttacker strength " << teamOne->getFirst()->getStregthPoints() << std::endl;
		std::cout << "Attacker armor " << teamOne->getFirst()->getArmor() << std::endl;
		std::cout << "\nOpponent strength " << teamTwo->getFirst()->getStregthPoints() << std::endl;
		std::cout << "Opponent armor " << teamTwo->getFirst()->getArmor() << std::endl;
		round++;

		int aStrength = teamOne->getFirst()->getStregthPoints();

		//If the strength drops below 1
		if (aStrength < 1)
		{
			//The name of player which lost
			std::cout << teamOne->getFirst()->getName() << " lost\n";

			teamTwoPoints += 1; //adds a point to the winner


			
			std::cout << "The round is over!\n";
			std::cout << "\nTeam one points: " << teamOnePoints;
			std::cout << "\nTeam two points: " << teamTwoPoints;

			l->setPlayer(teamOne->getFirst());//Adds to loser queue


			teamTwo->getFirst()->recovery(); //recovers the player that won

			teamTwo->setNodeTail(teamTwo->getNext()); //Sets the winner to the back of the queue

			//Removes the head
			teamOne->deleteHead();
			teamTwo->deleteHead();

				//
				if (teamOne->isEmpty())
				{
					game = false;
				   	
					std::cout << "\nTeam one is out of players\n";
					break; 
					
				}
				else if (teamTwo->isEmpty())
				{
					game = false; 
					std::cout << "\nTeam two is out of players\n";
					break;  
				}
				else
				{
					std::cout << ".........................................................................\n"; 
					std::cout << ".........................................................................\n";
					std::cout << ".........................................................................\n";
					std::cout << ".........................................................................\n";
					std::cout << ".........................................................................\n";
					std::cout << ".........................................................................\n";
					std::cout << ".........................................................................\n";

					std::cout << "\nThe next tournament is...\n";
				
					round = 1; 
				}


		}


	}while (game);


		
	

		//Asks user if they would like to display the loser queue
	char y = 'y'; 
	std::cout << "\nWould you like to display the contents of the loser container? y\n "; 
	std::cin >> y; 
	validateChar(y); 

	if (putchar(tolower(y)) == 'y')
	{
		char again = 'y'; 
		//Display loser content

		std::cout << "\n\nThe losers are: " << std::endl; 
		
		losers->printQueue();


		std::cout << "\nWould you like to play again? y/n"; 
		std::cin >> again; 
		validateChar(again); 

		if (putchar(tolower(again)) == 'y')
		{
			game = true; 
			runGame(); 
		}
		else
		{
			game = false; 
			std::cout << "\nGoodbye\n"; 
			exit(0); 
		}






	}
	else
	{
		std::cout << "\nGoodbye!"; 
		exit(0); 
	}




}








void Game::setNumTeamOne(int i)
{
	this->numTeamOne = i; 
}

void Game::setNumTeamTwo(int i)
{
	this->numTeamTwo = i; 
}


