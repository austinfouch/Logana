#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "board.h"
#include "hand.h"

class Player {
public:
	// default cstor
	Player() : score(0) {}

	// copy cstor for serialization
	Player(const int &s, const Hand &h);

	// implemented in human.cpp and computer.cpp
	virtual void play();

	// will be implemented in player.cpp
	void drawTile();

	void push_back(const Tile &t);
	Tile& operator[](const int index);
private:
	Hand hand;
	int score;
};

#endif