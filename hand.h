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
	Hand(const vector<Tile> &ts);
	
	// access to member tiles vector

	// 
	void push_back(const Tile &t);
	Tile remove(const Tile &t);
	void operator=(const Hand &h);
	Tile &operator[](const int index);
private:
	vector<Tile> tiles;
};

#endif