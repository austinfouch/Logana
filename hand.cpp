#include "hand.h"

Hand::Hand(const vector<Tile> &ts)
{
	this->tiles = ts;
}

void Hand::operator=(const Hand &h)
{
	this->tiles = h.tiles;
}