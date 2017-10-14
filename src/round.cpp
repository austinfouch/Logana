#include "round.h"

using namespace std;

/*
	Round::Round()
		default cstor
*/
Round::Round()
{
	this->currPlayer = 0;
	this->lastTurn.sidePlayed = '0';
	this->lastTurn.wasPassed = false;
}

/*
	Round::Round(const Round &r)
		Copy cstor.
*/
Round::Round(const Round &r)
{
	this->boneyard = r.boneyard;
	this->board = r.board;
}

/*
	void distributeTiles()
		This function creates Tile objects until the fill MAX_PIPS by MAX_PIPS 
		set is complete, pushing the objects into a vector for easy random
		access (shuffling). Then the created vector is distributed first to the
		players' hands and then to the boneyard.
*/
void Round::distribute_tiles(vector<unique_ptr<Player>> &players)
{
	cout << "Distributing tiles...";

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

	// new RNG seed
	srand(time(0));
	random_shuffle(tileList.begin(), tileList.end());
	
	// distribute full hands to the players (one at a time)
	for(int i = 0; i < players.size(); i++)
	{
		for(int j = 0; j < MAX_HAND_SIZE; j++)
		{
			players[i]->push_back(tileList.back());
			tileList.pop_back();
		}
	}

	// rest of tiles dumped to boneyard
	while(!tileList.empty())
	{
		this->boneyard.push_back(tileList.back());
		tileList.pop_back();
	}
}

/*
	void Round::setup_players()
		This function creates two player objects and pushes them into the member
		vector of Player type. For serialization and tournament purposes, the 
		Player class should allow for constructor of a Player object given just 
		the score as the vector hand will be empty to start (used for new round)
		 and a constructor that takes vector and score (for serialization).
*/
void Round::setup_players(vector<unique_ptr<Player>> &players)
{
	cout << "Setuping up players...";
	for(auto &p : players)
		p->clear_hand();
}

/*
	void Round::find_engine()
 		Searches player's hands for engine. If not found, players are forced to
 		 draw tiles from the boneyard until a player draws the valid engine.
*/
void Round::find_engine(vector<unique_ptr<Player>> &players, const int &round)
{
	// create temp engine based on round loop over player's unntil its found
	Tile eng(MAX_ROUNDS - round, MAX_ROUNDS - round);
	cout << "Finding the engine (" << eng << ")..." << endl << endl;
	for(this->currPlayer = 0; 
		this->currPlayer < players.size(); 
		this->currPlayer++)
	{	
		// check player's hand for tile equal to the tmp engine
		for(Tile &tile : *players[this->currPlayer])
		{	// return if the player has the eng	
			if(tile == eng)
			{
				cout << "Engine (" << eng << ") found in ";
				cout << players[this->currPlayer]->get_name(); 
				cout << "'s hand." << endl << endl;
				return;
			}
		}
	}

	// If eng not found, toggle currPlayer and draw a tile until engine found
	cout << "Engine is in boneyard, players must draw..." << endl << endl;
	this->currPlayer = 0;
	Tile temp;
	while(!(temp == eng))
	{
		temp = this->boneyard.back();

		cout << players[this->currPlayer]->get_name();
		cout << " must draw from the boneyard..." << endl;
		
		players[this->currPlayer]->draw_tile(temp);
		this->boneyard.pop_back();
		// return if player drew the engine, currPlayer is already this player
		if(temp == eng)
		{	
			cout << players[this->currPlayer]->get_name();
			cout << " has the engine" << endl << endl;
			return;
		}
		// otherwise toggle -- only works for 2 player games
		this->currPlayer = 1 - this->currPlayer;
	}
}

/*
	void Round::run()
		Acts as a main function for the Round class, setting up the players, 
		their hands, and the boneyard for the round. Need implementation for 
		setting up the board as well.
*/
void Round::run(vector<unique_ptr<Player>> &players, const int &round)
{	
	cout << "Starting round " << round << endl << endl;
	setup_players(players);
	distribute_tiles(players);
	find_engine(players, round);

	// toggle current player, calling play, until a hand is empty
	int testcount = 0;	// for testing while play() doesnt do much
	while(!players[this->currPlayer]->empty())
	{
		cout << players[this->currPlayer]->get_name() << "'s turn:" << endl;
		this->lastTurn = players[this->currPlayer]->play(this->board,
		 												this->boneyard,
		 												this->lastTurn);
		cout << "\tTurn summary: ";
		if(this->lastTurn.wasPassed)
		{
			cout << " Passed";
		}
		else
		{
			cout << "Tile " << this->lastTurn.tilePlayed;
			cout << " was played on side " << this->lastTurn.sidePlayed;
		}

		cout << endl << endl;
		this->currPlayer = 1 - this->currPlayer;

		if(testcount > 2)
			return;
		else
			testcount++;
	}
}