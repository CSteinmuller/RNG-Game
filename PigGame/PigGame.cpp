// PigGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
/**
TODO:
1) Win Screen
2) vs. AI
3) Break if at 100?
*/

using namespace std;

void multiPlayer();
void singlePlayer();

int main()
{
	int mode;
	bool validInput = false;
	cout << "The rules are as follows.\n During each turn, the player chooses :\n Roll: \nIf the player rolls a one, their turn ends and they earn a score of zero for the turn. \n ";
	cout << " If the player rolls two through six, the number is added to the player's turn total and the player's turn continues.\n	The player can keep rolling as long as it is still their turn.";
	cout << "Bank : \n The turn's total score is added to the player's total score.Then their turn ends. \n The first player to reach 100 wins the game.";
	while (validInput == false)
	{
		std::cout << "Please choose your play mode, enter 1 for multiplayer, or 2 to play against the AI \n";
		std::cin >> mode;
		if (mode == 1)
		{
			multiPlayer();
			validInput = true;
		}
		if (mode == 2)
		{
			singlePlayer();
			validInput = true;
		}
		if ((mode != 2)&&(mode != 1))
		{
			std::cout << "Error, please enter a valid input \n";
		}
	}
	system("PAUSE");
    return 0;
}

void multiPlayer()
{
	int playerScore[2] = { 0, 0 };
	int roll;
	int turns = 0;
	int turnScore = 0;
	int currentPlayer = rand() % 2;
	bool endOfTurn = false;
	string command = "";
	while ((playerScore[0] != 100) && (playerScore[1] != 100))
	{
		while (endOfTurn == false)
		{
			cout << "Player" << currentPlayer + 1 << "> \n";
			getline(cin, command);
			if (command == "roll")
			{
				roll = rand() % 6 + 1;
				if (roll == 1)
				{
					endOfTurn = true;
					turnScore = 0;
					cout << "Player " << currentPlayer + 1 << " rolled a " << roll << "\n" << "Player" << currentPlayer + 1 << "'s turn total = " << turnScore<<"\n";

				}
				else
				{
					turnScore += roll;
					cout << "Player " << currentPlayer + 1 << " rolled a " << roll << "\n" << "Player" << currentPlayer + 1 << "'s turn total = " << turnScore<<"\n";

				}
			}
			if (command == "bank")
			{
				playerScore[currentPlayer] += turnScore;
				endOfTurn = true;
				turnScore = 0;
			}
		}
		endOfTurn = false;
		turns++;
		if ((turns % 2) == 0)
		{
			cout << "Total Score:\n Player 1:" << playerScore[0] << "\n Player 2:" << playerScore[1] << "\n";
		}
		if (currentPlayer == 1)
		{
			currentPlayer--;
		}
		else
		{
			currentPlayer++;
		}

	}
}
void singlePlayer()
{
	int playerScore = 0;
	int computerScore = 0;
}

