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
	Boneyard(const Boneyard &by);

	// access to member stack tiles
	void pop_back();
	Tile& back();
	void push_back(const Tile &t);
	bool empty();
	vector<Tile>::iterator begin() { return this->tiles.begin(); }
	vector<Tile>::iterator end() { return this->tiles.end(); }

	// assignment overloading
	void operator=(const Boneyard &by);
	friend ostream &operator<<(ostream& out, Boneyard &by);
private:
	vector<Tile> tiles;
};

#endif