#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"
#include "board.h"

class Player {
public:
	// default cstor
	Player() : score(0) {}
	~Player();

	// copy cstor for serialization
	Player(const int &s, const Hand &h);

	// implemented in human.cpp and computer.cpp
	virtual void play();

	// will be implemented in player.cpp
	void drawTile();
private:
	Hand hand;
	int score;
};

#endif