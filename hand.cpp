#include "hand.h"

using namespace std;

Hand::Hand(const vector<Tile> &ts)
{
	this->tiles = ts;
}

void Hand::push_back(const Tile &t)
{
	this->tiles.push_back(t);
}

Tile Hand::remove(const Tile &t)
{
	//
}

void Hand::operator=(const Hand &h)
{
	this->tiles = h.tiles;
}

Tile& Hand::operator[](const int index)
{
	return this->tiles[index];
}