#include "round.h"

using namespace std;

/*
	void createTiles(vector<Tile>)
		This function creates Tile objects until the fill MAX_PIPS by MAX_PIPS set is
		complete, pushing the objects into a vector for easy random access (shuffling).
*/
deque<Tile> Round::create_tiles()
{
	// creates the tile objects 0-0 through 6-6 and pushes into the tileList
	deque<Tile> tileList;
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
		the players' hands and boneyard. I chose std::deque for this function because I 
		wanted to be able to use random_shuffle(), which is not usable on std::stack or 
		std::queue (not containers, but container adaptors), but also wanted the ability 
		to push, pop, and top which are not possible with std::vector.
*/
void Round::distribute_tiles(deque<Tile> &tileList)
{
	random_shuffle(tileList.begin(), tileList.end());
	for(int i = 0; i < NUM_PLAYERS; i++)
	{
		for(int j = 0; j < MAX_HAND_SIZE; j++)
		{
			this->players[i].push_back(tileList.front());
			tileList.pop_front();
		}
	}

	while(!tileList.empty())
	{
		this->boneyard.push(tileList.front());
		tileList.pop_front();
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

void Round::run()
{	
	setup_players();
	deque<Tile> tileList = create_tiles();
	distribute_tiles(tileList);

	for(int i = 0; i < MAX_HAND_SIZE; i++)
	{
		cout << this->players[0][i] << " ";
		cout << this->players[1][i] << "\n";
	}

	while(!this->boneyard.empty())
	{
		cout << this->boneyard.top() << "\n";
		this->boneyard.pop();
	}
}