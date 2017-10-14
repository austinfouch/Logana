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

void Board::display_board()
{
	ostringstream firstLine, secondLine;

	firstLine << "  ";
	secondLine << "L ";
	for(Tile &tile : this->leftSide)
	{
		if(tile.is_double())
		{
			firstLine << tile.get_leftPips() << " ";
			secondLine << "| ";
		}
		else
		{
			secondLine << tile << " ";
			firstLine << "    ";
		}
	}

	Tile tmp(-1, -1);
	if(this->engine == tmp)
	{
		secondLine << "(empty) ";
	}
	else
	{

		firstLine << this->engine.get_leftPips() << " ";
		secondLine << "| ";
	}

	for(Tile &tile : this->rightSide)
	{
		if(tile.is_double())
		{
			firstLine << tile.get_leftPips() << " ";
			secondLine << "| ";
		}
		else
		{
			secondLine << tile << " ";
			firstLine << "    ";
		}
	}

	secondLine << "R";

	string first = firstLine.str();
	string second = secondLine.str();
	cout << first << endl;
	cout << second << endl;
	cout << first << endl;
}
