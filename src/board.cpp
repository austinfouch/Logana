#include "board.h"

using namespace std;

/*
	Board::Board(const Board &b)
		Copy cstor.
*/
Board::Board(const Board &b)
{
	this->engine = b.engine;
	this->leftSide = b.leftSide;
	this->rightSide = b.rightSide;
}

/*
	void Board::push_left(const Tile &t)
		This function gives access to pushing back objects to the member stack leftSide.
*/
void Board::push_left(const Tile &t)
{
	this->leftSide.push_back(t);
}

/*
	void Board::push_right(const Tile &t)
		This function gives access to pushing back objects to the member stack
		righSide.
*/
void Board::push_right(const Tile &t)
{
	this->rightSide.push_back(t);
}

/*
	void Board::operator=(const Board &b)
		Overloaded assignment operator.
*/
void Board::operator=(const Board &b)
{
	this->engine = b.engine;
	this->leftSide = b.leftSide;
	this->rightSide = b.rightSide;
}

void Board::clear_board()
{
	while(!this->leftSide.empty())
		this->leftSide.pop_back();

	while(!this->rightSide.empty())
		this->rightSide.pop_back();

	this->engine = Tile(-1, -1);
}