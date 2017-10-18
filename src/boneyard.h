#ifndef BONEYARD_H
#define BONEYARD_H
#include "tile.h"
#include <vector>
#include <iterator>

class Boneyard {
public:
	// default cstor
	Boneyard() {}
	
	// copy cstor
	Boneyard(const Boneyard &by) { this->tiles = by.tiles; }

	// access to member stack tiles
	void pop_back() { this->tiles.pop_back(); }

	void clear();

	Tile& back() { return this->tiles.back(); }

	void push_back(const Tile &t) { this->tiles.push_back(t); }

	bool empty() { return this->tiles.empty(); }

	vector<Tile>::iterator begin() { return this->tiles.begin(); }

	vector<Tile>::iterator end() { return this->tiles.end(); }

	// assignment overloading
	void operator=(const Boneyard &by) { this->tiles = by.tiles; }

	friend ostream &operator<<(ostream& out, Boneyard &by);

private:
	vector<Tile> tiles;
};

#endif