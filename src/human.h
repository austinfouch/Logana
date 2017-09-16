#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "board.h"

class Human : public Player {
public:
	void play(Board &board);
	void help();

	Human(const int& s, const string &n) : Player()
	{
		this->score = s;
		this->name = n;
	}
};

#endif