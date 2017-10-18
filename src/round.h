#ifndef ROUND_H
#define ROUND_H
#include "boneyard.h"
#include "tile.h"
#include "board.h"
#include "human.h"
#include "computer.h"
#include "turn.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <fstream>

#define MAX_PIPS 6
#define MIN_PIPS 0
#define MAX_HAND_SIZE 8
#define MAX_ROUNDS 7

class Round {
public:
	// default cstor
	Round();

	// copy cstor
	Round(const Round &r);
	
	// caller function
	void run(vector<unique_ptr<Player>> &players, int &round, 
					int &score, bool isSerialized);

	// creates player objects and pushes them to players vector
	void setup_players(vector<unique_ptr<Player>> &players);

	void setup_board();
	
	void find_engine(vector<unique_ptr<Player>> &players, const int &round);

	void tally_score(vector<unique_ptr<Player>> &players, const int &winner);
	void tally_score(vector<unique_ptr<Player>> &players);
	void serialize(Board &board, vector<unique_ptr<Player>> &players, int &round, 
							Boneyard &boneyard, Turn &lastTurn, int &currPlayer, int &score);

	void set_board(const Board &board);
	void set_boneyard(const Boneyard &Boneyard);
	void set_wasPassed(const bool &wasPassed);
	void set_currPlayer(const int &currPlayer);
	// pop shuffled vector into players' hands and boneyard
	void distribute_tiles(vector<unique_ptr<Player>> &players);
private:
	Boneyard boneyard;
	Board board;
	int currPlayer;
	Turn lastTurn;
};

#endif