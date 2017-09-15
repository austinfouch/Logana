#ifndef BONEYARD_H
#define BONEYARD_H
#include "tile.h"
#include <stack>

class Boneyard {
public:
	// default cstor
	Boneyard() {}
	
	// copy cstor
	Boneyard(const Boneyard &by);

	// access to member stack tiles
	Tile pop();
	Tile& top();
	void push(const Tile &t);
	bool empty();

	// assignment overloading
	void operator=(const Boneyard &by);
private:
	stack<Tile> tiles;
};

#endif