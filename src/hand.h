#ifndef HAND_H
#define HAND_H
#include "tile.h"
#include <vector>
#include <algorithm>
#include <sstream>

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

	vector<Tile>::iterator begin() { return this->tiles.begin(); }

	vector<Tile>::iterator end() { return this->tiles.end(); }

	void erase_tile(const int &index);
	
	// overloading operators
	void operator=(const Hand &h) { this->tiles = h.tiles; }
	
	Tile &operator[](const int &index) { return this->tiles[index]; }

	friend ostream &operator<<(ostream& out, Hand &h);

private:
	vector<Tile> tiles;
};

#endif