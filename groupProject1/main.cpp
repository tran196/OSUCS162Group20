/**********************************************************************************************
Author: Tuan Tran
Date: 11/4/2018
Class: CS 162
Project: Group Project 1
Piece: main.cpp
Description: This is the main code that governs Group Project 1 (for testing purposes).
***********************************************************************************************/

// Pull-ins
#include "CritterClassForTestingBoard.hpp"
#include <iostream> // cout, endl
#include <string> // string

// Library functions
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::pair;

void menu();
void checkForChar(char &input);
void checkForInt(int &input);
void checkWithinBoundary(int &input, int boundary);

// Testing board
int main() {

//Cedrick's Original Main Function
/********

	// Create CritterClassForTestingBoard
	CritterClassForTestingBoard testingBoard;

	// Create board
	int sizeRows = 20;
	int sizeCols = 20;
	testingBoard.setBoard(sizeRows, sizeCols);

	// Show board (without ants/dbs on yet)
	testingBoard.showBoard();

	// Create ant/db location arrays
	int ants = 100;
	int dbs = 5;
	testingBoard.setLocations(ants, dbs);

	// Show board (with ants/dbs now on)
	testingBoard.showBoard();

*********/

	//Menu Function
	menu();

	// main() return function and termination
	return 0;
}

void menu()
{
	int boardRows, boardColumns, numberOfAnts, numberOfDoodleBugs;
	

	bool gameStatus = false;
	char startGame = 'n';

	do 
	{
	 	cout << "Group 20 Predator Prey Game\n";
	 	cout << "Extra Credit\n";

		cout << "To Start Game Please Enter \'y\' for Yes or \'n\' to Quit\n";
		checkForChar(startGame);

		if (startGame == 'n')
		{
			break;
		}

		cout << "How many rows will the board have?\n";	
		checkForInt(boardRows);								//helper function to check input

		cout << "How many columns will the board have?\n";	
		checkForInt(boardColumns);							//helper function to check input

		cout << "How many Ants?\n";
		checkForInt(numberOfAnts);							//helper function to check input

		cout << "How many Doodlebugs?\n";
		checkForInt(numberOfDoodleBugs);	
		
		// Create CritterClassForTestingBoard
		CritterClassForTestingBoard testingBoard;

		// Create board
		testingBoard.setBoard(boardRows, boardColumns);

		// Show board (without ants/dbs on yet)		
		testingBoard.showBoard();	

		// Create ant/db location arrays
		testingBoard.setLocations(numberOfAnts, numberOfDoodleBugs);

		// Show board (with ants/dbs now on)	
		testingBoard.showBoard();

		cout << "To Play Again Please Enter \'y\' for Yes or \'n\' to Quit\n";
		checkForChar(startGame);
		if (startGame == 'y')
		{
			gameStatus = true;
		}
		else if (startGame == 'n')
		{
			gameStatus = false;
		}



	} while (gameStatus);	
}

//Helper Functions

//Input Validation for Char
void checkForChar(char &input)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		cin >> input;
		if (input == 'y')
		{
			break;
		}
		else if (input == 'n')
		{
			break;
		}
		else
		{
			invalidInput = true;
			cout << "Please enter either \'y\' or \'n\' \n";
			cin.clear();
			cin.ignore();
		}
	} while(invalidInput);
}

//Input Validation for Integer
void checkForInt(int &input)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		std::cin >> input;
		if (std::cin.fail())
		{
			invalidInput = true;
			cout << "Please enter a valid integer\n";
			cin.clear();
			cin.ignore();
		}
		else if (input < 0)
		{
			invalidInput = true;
			cout << "Please enter a Positive integer\n";
			cin.clear();
			cin.ignore();
		}

	}while(invalidInput);
}

void checkWithinBoundary(int &input, int boundary)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		cin >> input;
		if (input <= 0 || input > (boundary - 1))
		{
			invalidInput = true;
			cout << "No within Board Boundary. Please enter a valid integer\n";
			cin.clear();
			cin.ignore();
		}
	}while (invalidInput);
}
