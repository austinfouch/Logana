#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "board.h"
#include <sstream>

class Human : public Player {
public:
	void play();
	void test() { cout << "Human test" << endl; }
	void help();
	int get_input();

	Human(const int& s, const string &n) : Player()
	{
		this->score = s;
		this->name = n;
	}
};

#endif