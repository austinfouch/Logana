#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "board.h"

class Human : public Player {
public:
	Human();
	~Human();
	
	void play(Board &board);
	void help();
};

#endif