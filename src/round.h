#ifndef ROUND_H
#define ROUND_H
#include "boneyard.h"
#include "tile.h"
#include "board.h"
#include "human.h"
#include "computer.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <memory>

#define MAX_PIPS 6
#define MIN_PIPS 0
#define MAX_HAND_SIZE 8
#define MAX_ROUNDS 7

class Round {
public:
	// default cstor
	Round() : currPlayer(0) {}

	// copy cstor
	Round(const Round &r);
	
	// caller function
	void run(vector<unique_ptr<Player>> &players, const int &round);

	// creates player objects and pushes them to players vector
	void setup_players(vector<unique_ptr<Player>> &players);

	void find_engine(vector<unique_ptr<Player>> &players, const int &round);

	// pop shuffled vector into players' hands and boneyard
	void distribute_tiles(vector<unique_ptr<Player>> &players);
private:
	Boneyard boneyard;
	Board board;
	int currPlayer;
};

#endif