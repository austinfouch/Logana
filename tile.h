#ifndef TILE_H
#define TILE_H
#include <iostream>		// ostream overloading

using namespace std;

class Tile {
public:
	Tile();
	~Tile();
	
	Tile(const int &lPips, const int &rPips);
	void swapPips();
	void operator=(const Tile &t);
	friend ostream &operator<<(ostream& out, const Tile &t);
private:
	int leftPips, rightPips;
};

#endif