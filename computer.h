#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include "board.h"

class Computer : public Player {
public:
	Computer();
	~Computer();
	
	void play(Board &board);
};

#endif