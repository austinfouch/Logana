#ifndef HAND_H
#define HAND_H
#include "tile.h"
#include <vector>

class Hand {
public:
	Hand();
	~Hand();
	
	Hand(const vector<Tile> &ts);
	void operator=(const Hand &h);
private:
	vector<Tile> tiles;
};

#endif