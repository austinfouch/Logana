#ifndef TILE_H
#define TILE_H
#include <iostream>		// ostream overloading

using namespace std;

class Tile {
public:
	Tile() : leftPips(0), rightPips(0) {}
	Tile(const int &lPips, const int &rPips);
	void swap_pips();
	void operator=(const Tile &t);
	bool operator==(const Tile &t);
	friend ostream &operator<<(ostream& out, const Tile &t);
private:
	int leftPips, rightPips;
};

#endif