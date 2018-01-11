/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include <iostream>		// overloading ostream
#include <vector>		// rightSide and leftSide member variables
#include <sstream>
#include <string>
#include "tile.h"		// engine member variable and vector data types

using namespace std;

class Board{
public:
	// default cstor
	Board() {}
	// copy cstor
	Board(const Board &b);
	/**************************************************************************
	Function Name: push_left
	Purpose: 
		To push a tile to the left side of the board
	Paramaters: 
		t, the tile to be pushed
	Return Value: None
	Assistance Received: None.
	**************************************************************************/
	void push_left(const Tile &t);
	/**************************************************************************
	Function Name: push_right
	Purpose: 
		To push a tile to the right side of the board
	Paramaters: 
		t, the tile to be pushed
	Return Value: None
	Assistance Received: None.
	**************************************************************************/
	void push_right(const Tile &t);
	/**************************************************************************
	Function Name: set_engine
	Purpose: 
		To set the engine of the board
	Paramaters: 
		t, the tile to set the engine to
	Return Value: None
	Assistance Received: None.
	**************************************************************************/
	void set_engine(const Tile &t) { this->engine = t; }
	/**************************************************************************
	Function Name: clear_board
	Purpose: 
		To set the engine to empty (-1,-1) and empty the left and right sides
		of the board
	Paramaters: None
	Return Value: None
	Assistance Received: None.
	**************************************************************************/
	void clear_board();
	/**************************************************************************
	Function Name: get_leftSide
	Purpose: 
		To return the left side of the board
	Paramaters: None
	Return Value: a vector of type tile
	Assistance Received: None.
	**************************************************************************/
	vector<Tile> get_leftSide() { return this->leftSide; }
	/**************************************************************************
	Function Name: get_rightSide
	Purpose: 
		To return the right side of the board
	Paramaters: None
	Return Value: a vector of type tile
	Assistance Received: None.
	**************************************************************************/
	vector<Tile> get_rightSide() { return this->rightSide; }
	/**************************************************************************
	Function Name: get_engine
	Purpose: 
		To return the engine of the board
	Paramaters: None
	Return Value: a tile object
	Assistance Received: None.
	**************************************************************************/
	Tile get_engine() { return this->engine; }
	/**************************************************************************
	Function Name: operator=
	Purpose: 
		To overload the assignment operator and set the board to equal the 
		passed board
	Paramaters: 
		b, a board object being assigned to the board
	Return Value: None
	Assistance Received: None.
	**************************************************************************/
	void operator=(const Board &b);
private:
	Tile engine;
	vector<Tile> leftSide;
	vector<Tile> rightSide;
};

#endif