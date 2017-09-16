#ifndef ROUND_H
#define ROUND_H
#include "boneyard.h"
#include "tile.h"
#include "board.h"
#include "player.h"
#include <vector>
#include <algorithm>

#define MAX_PIPS 6
#define MIN_PIPS 0
#define MAX_HAND_SIZE 8
#define NUM_PLAYERS 2

class Round {
public:
	// default cstor
	Round() {}

	// copy cstor
	Round(const Round &r);

	Round(vector<Player> &ps);
	
	// caller function
	void run();

	// creates player objects and pushes them to players vector
	void setup_players();

	// pop shuffled vector into players' hands and boneyard
	void distribute_tiles();
private:
	Boneyard boneyard;
	Board board;
	vector<Player> players;
};

#endif