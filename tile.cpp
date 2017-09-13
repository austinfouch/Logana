#include "tile.h"

using namespace std;

Tile::Tile(int lPips, int rPips)
{
	this->leftPips = lPips;
	this->rightPips = rPips;
}

void Tile::swapPips()
{
	cout << "Tile's pips were swapped: " << this->leftPips << "-" << this->rightPips;
	int tmp;
	tmp = this->leftPips;
	this->leftPips = this->rightPips;
	this->rightPips = tmp;
	cout << " -> " << this->leftPips << "-" << this->rightPips << "\n";
}

void Tile::operator=(const Tile &t)
{
	this->leftPips = t.leftPips;
	this->rightPips = t.rightPips;
}

ostream &operator<<(ostream& out, const Tile &t)
{
	out << t.leftPips << "-" << t.rightPips;
}