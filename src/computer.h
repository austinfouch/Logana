#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include "board.h"

class Computer : public Player {
public:
	Turn play(Board &board, Boneyard &boneyard, Turn &lastTurn) 
	{ 
		Turn turn;
		turn.wasPassed = false;
		turn.sidePlayed = 'C';
		turn.tilePlayed = Tile(-1, -1);
		return turn;
	}

	Computer(const int &s, const string &n) : Player()
	{
		this->score = s;
		this->name = n;
	}
};

#endif