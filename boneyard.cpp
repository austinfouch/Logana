#include "boneyard.h"

Boneyard::Boneyard(const stack<Tile> &ts)
{
	this->tiles = ts;
}

Tile Boneyard::pop()
{
	Tile tmp = this->tiles.top();
	this->tiles.pop();
	return tmp;
}

void Boneyard::push(const Tile &t)
{
	this->tiles.push(t);
}

bool Boneyard::empty()
{
	return this->tiles.empty();
}

void Boneyard::operator=(const Boneyard &by)
{
	this->tiles = by.tiles;
}

Tile& Boneyard::top()
{
	return this->tiles.top();
}