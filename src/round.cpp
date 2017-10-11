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
void Round::distribute_tiles(vector<unique_ptr<Player>> &players)
{
	cout << "Distributing tiles..." << endl;
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
	
	for(int i = 0; i < players.size(); i++)
	{
		for(int j = 0; j < MAX_HAND_SIZE; j++)
		{
			// need to use -> now because its accessing a vector of unique_ptr<Player>
			players[i]->push_back(tileList.back());
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
void Round::setup_players(vector<unique_ptr<Player>> &players)
{
	cout << "Setuping up players for round..." << endl;
	for(auto &p : players)
		p->clear_hand();
}

/*
** 	searches players' hands for the engine for this round
*/
void Round::find_engine(vector<unique_ptr<Player>> &players, const int &round_num)
{
	Tile eng(round_num, round_num);		// create temp engine
	cout << "Locating round's engine (" << eng << ")..." << endl;
	// loop over players
	for(this->current_player = 0; 
		this->current_player < players.size(); 
		this->current_player++)
	{	
		// check player's hand for tile equal to the tmp engine
		for(Tile &tile : *players[this->current_player])
		{		
			if(tile == eng)
			{
				cout << "Engine (" << eng << ") found in ";
				cout << players[this->current_player]->get_name(); 
				cout << "'s hand." << endl << endl;
				return;
			}
		}
	}
	cout << "Engine is in boneyard, players must draw..." << endl << endl;
	this->current_player = 0;
	Tile temp;	// holding value of boneyard's next drawable tile
	while(!(temp == eng))
	{
		temp = this->boneyard.back();

		cout << players[this->current_player]->get_name();
		cout << " must draw from the boneyard..." << endl << endl;
		
		players[this->current_player]->draw_tile(temp);
		this->boneyard.pop_back();
		current_player = 1 - current_player;	// toggles between player 0 and 1
	}

	cout << players[this->current_player]->get_name() << " has the engine." << endl;
	return;
}

/*
**	void Round::run()
**		Acts as a main function for the Round class, setting up the players, their hands, and
**		the boneyard for the round. Need implementation for setting up the board as well.
*/
void Round::run(vector<unique_ptr<Player>> &players, const int &round_num)
{	
	// NOTE: players is a vector of unique pointers of type Player. In order to access the
	// individual players in the vector, you must derefence the elements of the vector (*).
	setup_players(players);
	distribute_tiles(players);
	find_engine(players, round_num);
	for(auto &player : players)
		player->play(this->board, this->boneyard);
}