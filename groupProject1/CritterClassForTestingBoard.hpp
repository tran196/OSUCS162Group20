/**********************************************************************************************
Author: Cedric Eicher
Date: 11/4/2018
Class: CS 162
Project: Group Project 1
Piece: CritterClassForTestingBoard.hpp
Description: This class was specifically created to test the board in the Critter class.
***********************************************************************************************/

// Duplicate guards
#ifndef CRITTERCLASSFORTESTINGBOARD_HPP
#define CRITTERCLASSFORTESTINGBOARD_HPP

// CritterClassForTestingBoard class declaration
class CritterClassForTestingBoard {

	// Private member variables
	private:
		int numAnts;
		int numDBs;
		int boardRow;
		int boardCol;
		char** board;
		int** antLocations;
		int** dbLocations;

	// Public function headers
	public:
		void setLocations(int numAnts, int numDBs);
		void setBoard(int row, int col);
		void showBoard();
		~CritterClassForTestingBoard();
};

#endif
