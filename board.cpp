#include "board.h"

using namespace std;

Board::Board(const Tile &eng, const vector<Tile> &left, const vector<Tile> &right)
{
	this->engine = eng;
	this->leftSide = left;
	this->rightSide = right;
}

void Board::pushLeft(const Tile &t)
{
	this->leftSide.push_back(t);
}

void Board::pushRight(const Tile &t)
{
	this->rightSide.push_back(t);
}

void Board::operator=(const Board &b)
{
	this->engine = b.engine;
	this->leftSide = b.leftSide;
	this->rightSide = b.rightSide;
}

ostream &operator<<(ostream& out, const Board &b)
{
	out << "L ";
	for(int i = 0; i < b.leftSide.size(); i++)
		out << b.leftSide[i] << " ";

	out << "\n" << b.engine << "\n";

	for(int i = 0; i < b.rightSide.size(); i++)
		out << "|" << b.rightSide[i] << " ";
	out << " R";
}
