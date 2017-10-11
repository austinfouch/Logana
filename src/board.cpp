#include "board.h"

using namespace std;

/*
**	Board::Board(const Board &b)
**		Copy cstor.
*/
Board::Board(const Board &b)
{
	this->engine = b.engine;
	this->leftSide = b.leftSide;
	this->rightSide = b.rightSide;
}

/*
**	void Board::push_left(const Tile &t)
**		This function gives access to pushing back objects to the member stack leftSide.
*/
void Board::push_left(const Tile &t)
{
	this->leftSide.push_back(t);
}

/*
**	void Board::push_right(const Tile &t)
**		This function gives access to pushing back objects to the member stack righSide.
*/
void Board::push_right(const Tile &t)
{
	this->rightSide.push_back(t);
}

/*
**	void Board::operator=(const Board &b)
**		Overloaded assignment operator.
*/
void Board::operator=(const Board &b)
{
	this->engine = b.engine;
	this->leftSide = b.leftSide;
	this->rightSide = b.rightSide;
}

/*
**	ostream &operator<<(ostream& out, const Board &b)
**		Overloaded ostream operator. Will be moved to the BoardView class.
*/
ostream &operator<<(ostream& out, const Board &b)
{
	out << "L ";
	for(int i = 0; i < b.leftSide.size(); i++)
		out << b.leftSide[i] << " ";

	out << b.engine;

	for(int i = 0; i < b.rightSide.size(); i++)
		out << " " << b.rightSide[i];
	out << " R" << endl << endl;
}
