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

	// copy cstor, will be used for serializtion
	Board(const Board &b);

	// access to the sides of the board
	void push_left(const Tile &t);
	void push_right(const Tile &t);
	void set_engine(const Tile &t) { this->engine = t; }

	void clear_board();
	vector<Tile> get_leftSide() { return this->leftSide; }
	vector<Tile> get_rightSide() { return this->rightSide; }
	Tile get_engine() { return this->engine; }

	// assignment overload for copy cstor (serialization)
	void operator=(const Board &b);
private:
	Tile engine;
	vector<Tile> leftSide;
	vector<Tile> rightSide;
};

#endif