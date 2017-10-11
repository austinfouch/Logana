#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include "board.h"

class Computer : public Player {
public:
	void play(Board &board, Boneyard &boneyard) 
	{ 
		cout << "uhh" << endl << endl;
	}

	Computer(const int &s, const string &n) : Player()
	{
		this->score = s;
		this->name = n;
	}
};

#endif