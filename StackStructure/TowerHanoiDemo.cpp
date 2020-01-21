//TowerHanoiDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of stacks. 

#include <iostream>
#include <cstdlib>
#include "TowerHanoi.h"

using namespace std;

int main()
{
	int numberOfDiscs = 0;
	int numberOfMoves = 0;
	int rodFrom, rodTo;
	bool gameEnded = false;

	do
	{
		cout << "Please input the number of discs (max 6):" << endl;
		cin >> numberOfDiscs;
	}
	while ((numberOfDiscs < 1) || (numberOfDiscs > 6));
	
	TowerHanoi game(numberOfDiscs); // initialize the game


	// start of the game
	cout << game; // print the current state of the game on the screen
	while(!gameEnded)
	{
		cout << "Please input the rod to remove from (1, 2 or 3):" << endl;	
		cin >> rodFrom;
		cout << "Please input the rod to place onto (1, 2 or 3):" << endl;	
		cin >> rodTo;
		game.move(rodFrom, rodTo); // move should perform all the checks and only move a disc if the movement is allowed. If the movement is not allowed, display a warning message.
		numberOfMoves++;
		cout << game; // print the current state of the game on the screen
		gameEnded = game.checkWin(); // checks if the 3rd rod contains all the discs.
	}
	cout << "The game has ended." << endl; 
	cout << "You required " << numberOfMoves << " to win." << endl; 

	return 0;
}
