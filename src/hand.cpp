#include "hand.h"

using namespace std;

/*
**	Hand::Hand(const Hand &h)
**		Copy cstor.
*/
Hand::Hand(const Hand &h)
{
	this->tiles = h.tiles;
}

/*
**	void Hand::push_back(const Tile &t)
**		This functions gives acccess to pushing objects into the member vector tiles.
*/
void Hand::push_back(const Tile &t)
{
	this->tiles.push_back(t);
}

/*
**	Tile Hand::remove(const Tile &t)
**		This function will search for tile in member tiles that is equal to the input object.
**		If no equal object is found in the member tiles, then the action will be cancelled and
**		handled.
*/
Tile Hand::remove(const Tile &t)
{
	//
}

/*
**	void Hand::operator=(const Hand &h)
**		Overloaded assignment operator.
*/
void Hand::operator=(const Hand &h)
{
	this->tiles = h.tiles;
}

/*
**	Tile& Hand::operator[](const int index)
**		Overloaded element access to the member tiles, used for searching in Hand::remove().
*/
Tile& Hand::operator[](const int index)
{
	return this->tiles[index];
}