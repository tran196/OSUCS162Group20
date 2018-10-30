/**********************************************************************************************
Author: Cedric Eicher
Date: 11/4/2018
Class: CS 162
Project: Group Project 1
Piece: CritterClassForTestingBoard.cpp
Description: This class was specifically created to test the board in the Critter class.


NOTES:
- My board is a 2D dynamic array, very similar to the one used in Project 1. I have made it
  within this dummy Critter class as I plan to have it be in the Critter class, not separate
  in a Board class. It is sized upon creation via inputs.

- setBoard must be called before setLocations (so that there are board limits)

- As breed/die occur, the antLocations and dbLocations arrays will need to be resized to
  accomodate. I recommend a resize() internal function for this that can easily be called
  during each breed/die instance.



BOARD MEMBER VARIABLES:

  int numAnts: # of ants currently in play
  int numDBs: # of doodlebugs currently in play
  int boardRow: Board # of rows
  int boardCol: Board # of columns
  char** board: Board iteslf (dynamic 2D char pointer array)
  int** antLocations: Dynamic 2D int pointer array that holds ant locations (row, col)
  int** dbLocations: Dynamic 2D int pointer array that holds db locations (row, col)



BOARD MEMBER FUNCTIONS:

  setBoard: function that creates the board initially. Takes two int inputs (row, col) to know
		    what size to make the board. By default, all spaces are set to whitespace ' '.

  setLocations: function that creates the ant and db locations arrays. Randomly assigns (row, col)
			    locations to them within board boundaries (boardRow, boardCol).

  showBoard: function that outputs the board to the screen at any given time. No variable inputs
			 or outputs. Before displaying the board, the ants and doodlebugs are "placed" on the
			 board by pulling the ant and doodlebug location coordinates from the antLocations and
			 dbLocations dynamic int arrays. After displaying the board, the ants and doodlebugs 
			 are "removed" from the board.

  ~CritterClassForTestingBoard: deconstructor which nullifies and destroys board array, antLocations
							    array, and dbLocations array.

***********************************************************************************************/

// Pull-ins
#include "CritterClassForTestingBoard.hpp"
#include <iostream> // cout, endl
#include <stdlib.h> // srand, rand
#include <time.h> // time

// Library functions
using std::cout;
using std::endl;


/*******************************************************************
CritterClassForTestingBoard::setLocations
Description: Sets up antLocations and dbLocations arrays for their
board locations (row, col).
Inputs: None
Outputs: None
*******************************************************************/
void CritterClassForTestingBoard::setLocations(int ants, int dbs){

	// Assign variables
	numAnts = ants;
	numDBs = dbs;

	// Ant locations array setup (dynamic 2D array)
	antLocations = new int*[numAnts];
	for (int i = 0; i < numAnts; ++i) {
		antLocations[i] = new int[2];
	}

	// DB locations array setup (dynamic 2D array)
	dbLocations = new int*[numDBs];
	for (int i = 0; i < numDBs; ++i) {
		dbLocations[i] = new int[2];
	}

	// Populate ant locations with randomized locations on board
	int randRow;
	int randCol;
	// Time seed
	srand(time(NULL));
	// Rows
	for (int i = 0; i < numAnts; i++) {
		// Random row within board row limits
		randRow = rand() % boardRow + 1;
		antLocations[i][0] = randRow;
	}
	// Columns
	for (int i = 0; i < numAnts; i++) {
		// Random row within board row limits
		randCol = rand() % boardCol + 1;
		antLocations[i][1] = randCol;
	}

	// Populate DB locations with randomized locations on board
	// Rows
	for (int i = 0; i < numDBs; i++) {
		// Random row within board row limits
		randRow = rand() % boardRow + 1;
		dbLocations[i][0] = randRow;
	}
	// Columns
	for (int i = 0; i < numDBs; i++) {
		// Random row within board row limits
		randCol = rand() % boardCol + 1;
		dbLocations[i][1] = randCol;
	}

	// DEBUGGING PURPOSES ONLY: Output to screen antLocations and dbLocations arrays
	//cout << "antLocations array (O): " << endl;
	//for (int i = (numAnts - 1); i >= 0; i--) {
	//	for (int j = 0; j < 2; j++) {
	//		cout << antLocations[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "dbLocations array (X): " << endl;
	//for (int i = (numDBs - 1); i >= 0; i--) {
	//	for (int j = 0; j < 2; j++) {
	//		cout << dbLocations[i][j] << " ";
	//	}
	//	cout << endl;
	//}

}


/*******************************************************************
CritterClassForTestingBoard::setBoard
Description: This function sets up the board.
Inputs: int row: user-chosen number of rows on the board. Will need to be captured in main with a menu prompt
	    int col: user-chosen number of columns on the board. Will need to be captured in main with a menu prompt
Outputs: None
*******************************************************************/
void CritterClassForTestingBoard::setBoard(int row, int col) {

	// Take in board values
	boardRow = row;
	boardCol = col;

	// Board setup (dynamic 2D array)
	board = new char*[boardRow];
	for (int i = 0; i < boardRow; ++i) {
		board[i] = new char[boardCol];
	}

	// Populate with spaces (white)
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; j++) {
			board[i][j] = ' ';
		}
	}

}


/*******************************************************************
CritterClassForTestingBoard::showBoard
Description: This function shows the board.
Inputs: None
Outputs: None
*******************************************************************/
void CritterClassForTestingBoard::showBoard() {

	// Pre-showBoard, put ants (O) and doodlebugs (X) on board
	// Place Ants (O)
	for (int i = 0; i < numAnts; i++) {
		for (int j = 0; j < 1; j++) {
			board[antLocations[i][j] - 1][antLocations[i][j+1] - 1] = 'O';
		}
	}
	// Place DBs (X)
	for (int i = 0; i < numDBs; i++) {
		for (int j = 0; j < 1; j++) {
			board[dbLocations[i][j] - 1][dbLocations[i][j + 1] - 1] = 'X';
		}
	}

	// Jump-line to allow board to stand out
	cout << endl;

	// Output top border
	for (int q = 0; q < (boardCol + 2); q++) {
		cout << "= ";
	}
	cout << endl;

	// Output board
	for (int i = (boardRow - 1); i >= 0; i--) {
		cout << "| ";
		for (int j = 0; j < boardCol; j++) {
			cout << board[i][j] << " ";
		}
		cout << "| " << endl;
	}

	// Output bottom border
	for (int q = 0; q < (boardCol + 2); q++) {
		cout << "= ";
	}

	// Jump line to allow board to stand out
	cout << endl;

	// Post-showBoard, remove ants (O) and doodlebugs (X) on board
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; j++) {
			board[i][j] = ' ';
		}
	}

}


/*******************************************************************
CritterClassForTestingBoard::~CritterClassForTestingBoard
Description: Default deconstructor for the class which destroys all
dynamic arrays created.
Inputs: None
Outputs: None
*******************************************************************/
CritterClassForTestingBoard::~CritterClassForTestingBoard() {

	// Delete board dynamic array
	for (int q = 0; q < boardRow; ++q) {
		delete[] board[q];
	}
	delete[] board;
	board = NULL;

	// Delete antLocations dynamic array
	for (int r = 0; r < numAnts; ++r) {
		delete[] antLocations[r];
	}
	delete[] antLocations;
	antLocations = NULL;

	// Delete dbLocations dynamic array
	for (int r = 0; r < numDBs; ++r) {
		delete[] dbLocations[r];
	}
	delete[] dbLocations;
	dbLocations = NULL;

}