#ifndef BOARD_H
#define BOARD_H
#include <iostream>		// overloading ostream
#include <vector>		// rightSide and leftSide member variables
#include "tile.h"		// engine member variable and vector data types

using namespace std;

class Board{
public:
	// default cstor dstor
	Board();
	~Board();

	// copy cstor, will be used for serializtion
	Board(const Tile &eng, const vector<Tile> &left, const vector<Tile> &right);

	// access to the sides of the board
	void pushLeft(const Tile &t);
	void pushRight(const Tile &t);

	// assignment overload for copy cstor (serialization)
	void operator=(const Board &b);

	// displaying of the board to the user in the terminal
	friend ostream &operator<<(ostream& out, const Board &b);
private:
	Tile engine;
	vector<Tile> leftSide;
	vector<Tile> rightSide;
};

#endif