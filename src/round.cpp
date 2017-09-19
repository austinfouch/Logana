#include "round.h"

using namespace std;

/*
**	Round::Round(const Round &r)
**		Copy cstor.
*/
Round::Round(const Round &r)
{
	this->boneyard = r.boneyard;
	this->board = r.board;
}

/*
	void distributeTiles()
		This function creates Tile objects until the fill MAX_PIPS by MAX_PIPS set is
		complete, pushing the objects into a vector for easy random access (shuffling).
		Then the created vector is distributed first to the players' hands and then to 
		the boneyard.
*/
void Round::distribute_tiles(vector<Player> &players)
{
	srand(time(0));
	// creates the tile objects 0-0 through 6-6 and pushes into the tileList
	vector<Tile> tileList;
	int leftPips, rightPips;
	for(leftPips = MIN_PIPS; leftPips <= MAX_PIPS; leftPips++)
	{
		for(rightPips = leftPips; rightPips <= MAX_PIPS; rightPips++)
		{
			Tile tile(leftPips, rightPips);
			tileList.push_back(tile);
		}
	}

	random_shuffle(tileList.begin(), tileList.end());
	
	for(int i = 0; i < players.size(); i++)
	{
		for(int j = 0; j < MAX_HAND_SIZE; j++)
		{
			players[i].push_back(tileList.back());
			tileList.pop_back();
		}
	}

	while(!tileList.empty())
	{
		this->boneyard.push_back(tileList.back());
		tileList.pop_back();
	}
}

/*
	void Round::setup_players()
		This function creates two player objects and pushes them into the member vector
		of Player type. For serialization and tournament purposes, the Player class should
		allow for constructor of a Player object given just the score as the vector hand will
		be empty to start (used for new round) and a constructor that takes vector and score
		(for serialization).
*/
void Round::setup_players(vector<Player> &players)
{
	for(auto &p : players)
		p.clear_hand();
}

/*
** 	searches players' hands for the engine for this round
*/
void Round::find_engine(vector<Player> &players, const int &round_num)
{
	Tile eng(round_num, round_num);
	for(auto &player : players)
		for(auto &tile : player)
			if(tile == eng)
				cout << "Engine Found\n";
}

/*
**	void Round::run()
**		Acts as a main function for the Round class, setting up the players, their hands, and
**		the boneyard for the round. Need implementation for setting up the board as well.
*/
void Round::run(vector<Player> &players, const int &round_num)
{	
	setup_players(players);
	distribute_tiles(players);
	find_engine(players, round_num);
}