#ifndef HAND_H
#define HAND_H
#include "tile.h"
#include <vector>
#include <algorithm>

class Hand {
public:
	// default cstor
	Hand() {}	

	// copy cstor
	Hand(const Hand &h) { this->tiles = h.tiles; }
	
	// vector functions
	void push_back(const Tile &t) { this->tiles.push_back(t); }
	void pop_back() { this->tiles.pop_back(); }
	int size() const { return this->tiles.size(); }
	bool empty() { return this->tiles.empty(); }

	// will return a copy of the passed tile (if it exists in the hand), and pop the tile
	Tile play_tile(const Tile &t);
	
	// overloading operators
	void operator=(const Hand &h) { this->tiles = h.tiles; }
	Tile &operator[](const int index) { return this->tiles[index]; }

	
	friend ostream &operator<<(ostream& out, const Hand &h);

private:
	vector<Tile> tiles;
};

#endif