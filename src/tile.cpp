#include "tile.h"

using namespace std;

/*
**	Tile::Tile(const int &lPips, const int &rPips)
**		Simple cstor.
*/
Tile::Tile(const int &lPips, const int &rPips)
{
	this->leftPips = lPips;
	this->rightPips = rPips;
}

/*
**	Tile::Tile(const Tile &t)
**		Copy cstor.
*/
Tile::Tile(const Tile &t)
{
	this->leftPips = t.leftPips;
	this->rightPips = t.rightPips;
}

/*
**	void Tile::swap_pips()
**		This function swaps the values of members leftPips and rightPips.
*/
void Tile::swap_pips()
{
	int tmp;
	tmp = this->leftPips;
	this->leftPips = this->rightPips;
	this->rightPips = tmp;
}

/*
**	void Tile::operator=(const Tile &t)
**		Overloaded assignment operator.
*/
void Tile::operator=(const Tile &t)
{
	this->leftPips = t.leftPips;
	this->rightPips = t.rightPips;
}

/*
**	bool Tile::operator==(const Tile &t)
**		Overloaded equal to comparison operator, used for Hand::remove(const Tile &t)
*/
bool Tile::operator==(const Tile &t)
{
	return ((this->leftPips == t.leftPips) && (this->rightPips == t.rightPips));
}

/*
**	ostream &operator<<(ostream& out, const Tile &t)
**		Overloaded ostream operator, prints tile to console.
*/
ostream &operator<<(ostream& out, const Tile &t)
{
	out << t.leftPips << "-" << t.rightPips;
}