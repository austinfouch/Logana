#ifndef ROUND_H
#define ROUND_H
#include "boneyard.h"
#include "tile.h"
#include "board.h"
#include "player.h"
#include <deque>
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
	Round(const Boneyard &by, const Board &b, const vector<Player> &ps);
	
	// caller function
	void run();

	// creates player objects and pushes them to players vector
	void setup_players();

	// creates tiles and shuffles them
	deque<Tile> create_tiles();

	// pop shuffled deque into players' hands and boneyard
	void distribute_tiles(deque<Tile> &ts);
private:
	Boneyard boneyard;
	Board board;
	vector<Player> players;
};

#endif