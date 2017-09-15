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

/*
	void createTiles(vector<Tile>)
		This function creates Tile objects until the fill MAX_PIPS by MAX_PIPS set is
		complete, pushing the objects into a vector for easy random access (shuffling).
*/
vector<Tile> Round::create_tiles()
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

	return tileList;
}

/*
	void distributeTiles(vector<Tile>)
		This function randomly accesses elements within the passed and erases them until the 
		vector is empty. This function will later have implementation to distrbiute tiles
		the players' hands and boneyard. 
*/
void Round::distribute_tiles(vector<Tile> &tileList)
{
	random_shuffle(tileList.begin(), tileList.end());
	for(int i = 0; i < NUM_PLAYERS; i++)
	{
		for(int j = 0; j < MAX_HAND_SIZE; j++)
		{
			this->players[i].push_back(tileList.back());
			tileList.pop_back();
		}
	}

	while(!tileList.empty())
	{
		this->boneyard.push(tileList.back());
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
	Player human;
	Player computer;
	this->players.push_back(human);
	this->players.push_back(computer);
}

/*
**	void Round::run()
**		Acts as a main function for the Round class, setting up the players, their hands, and
**		the boneyard for the round. Need implementation for setting up the board as well.
*/
void Round::run()
{	
	setup_players();
	vector<Tile> tileList = create_tiles();
	distribute_tiles(tileList);

	/* distributes to the player's hands. need to make it dynamic indexing instead of 0 and 1 */
	for(int i = 0; i < MAX_HAND_SIZE; i++)
	{
		cout << this->players[0][i] << " ";
		cout << this->players[1][i] << "\n";
	}

	/* rest of the tiles are copied to the boneyard and then popped */
	while(!this->boneyard.empty())
	{
		cout << this->boneyard.top() << "\n";
		this->boneyard.pop();
	}
}