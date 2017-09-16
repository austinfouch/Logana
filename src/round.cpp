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
	this->players = r.players;
}

Round::Round(vector<Player> &ps)
{
	this->players = ps;
}

/*
	void distributeTiles()
		This function creates Tile objects until the fill MAX_PIPS by MAX_PIPS set is
		complete, pushing the objects into a vector for easy random access (shuffling).
		Then the created vector is distributed first to the players' hands and then to 
		the boneyard.
*/
void Round::distribute_tiles()
{
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
	
	for(int i = 0; i < NUM_PLAYERS; i++)
	{
		cout << "Player " << i+1 << ": \n";
		for(int j = 0; j < MAX_HAND_SIZE; j++)
		{
			this->players[i].push_back(tileList.back());
			cout << tileList.back() << "\n";
			tileList.pop_back();
		}
	}

	cout << "Boneyard: \n";
	while(!tileList.empty())
	{
		this->boneyard.push(tileList.back());
		cout << tileList.back() << "\n";
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
void Round::setup_players()
{
	for(int i = 0; i < this->players.size(); i++)
		this->players[i].clear_hand();
}

/*
**	void Round::run()
**		Acts as a main function for the Round class, setting up the players, their hands, and
**		the boneyard for the round. Need implementation for setting up the board as well.
*/
void Round::run()
{	
	setup_players();
	distribute_tiles();
}