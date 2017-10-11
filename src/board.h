#ifndef BOARD_H
#define BOARD_H
#include <iostream>		// overloading ostream
#include <vector>		// rightSide and leftSide member variables
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

	// assignment overload for copy cstor (serialization)
	void operator=(const Board &b);

	friend ostream &operator<<(ostream& out, Board &b);
private:
	Tile engine;
	vector<Tile> leftSide;
	vector<Tile> rightSide;
};

#endif