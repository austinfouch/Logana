#ifndef BONEYARD_H
#define BONEYARD_H
#include "tile.h"
#include <stack>

class Boneyard {
public:
	Boneyard() {}
	Boneyard(const stack<Tile> &ts);
	Tile pop();
	Tile& top();
	void push(const Tile &t);
	bool empty();
	void operator=(const Boneyard &by);
private:
	stack<Tile> tiles;
};

#endif