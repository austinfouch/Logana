#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "board.h"
#include <sstream>
#include <regex>
#include <utility>
#include <locale>

class Human : public Player {
public:
	Turn play(Board &board, Boneyard &boneyard, Turn &lastTurn);

	void help(Board &board, Boneyard &boneyard, Turn &lastTurn);
	int get_input();
	pair<int, string> play_tile(Board &board, Turn &lastTurn);
	pair<int, string> play_engine(Tile &eng);
	bool pass(Board &b, Turn &lastTurn);

	Human(const int& s, const string &n) : Player()
	{
		this->score = s;
		this->name = n;
	}
};

#endif