#ifndef TILE_H
#define TILE_H
#include <iostream>		// ostream overloading

using namespace std;

class Tile {
public:
	// default cstor
	Tile() : leftPips(0), rightPips(0) {}

	// simple initialization cstor 
	Tile(const int &lPips, const int &rPips);

	// copy cstor
	Tile(const Tile &t);

	// swaps leftPips and rightPips value
	void swap_pips();

	// overloading
	void operator=(const Tile &t);
	bool operator==(const Tile &t);
	friend ostream &operator<<(ostream& out, const Tile &t);
private:
	int leftPips, rightPips;
};

#endif