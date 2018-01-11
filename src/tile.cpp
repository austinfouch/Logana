/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "tile.h"

using namespace std;

Tile::Tile(const int &lPips, const int &rPips)
{
	this->leftPips = lPips;
	this->rightPips = rPips;
}

Tile::Tile(const Tile &t)
{
	this->leftPips = t.leftPips;
	this->rightPips = t.rightPips;
}

void Tile::swap_pips()
{
	int tmp;
	tmp = this->leftPips;
	this->leftPips = this->rightPips;
	this->rightPips = tmp;
}

void Tile::operator=(const Tile &t)
{
	this->leftPips = t.leftPips;
	this->rightPips = t.rightPips;
}

bool Tile::operator==(const Tile &t)
{
	return ((this->leftPips == t.leftPips) && (this->rightPips == t.rightPips));
}

ostream &operator<<(ostream& out, const Tile &t)
{
	out << t.leftPips << "-" << t.rightPips;
}