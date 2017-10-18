#include "round.h"

using namespace std;

/*
	Round::Round()
		default cstor
*/
Round::Round()
{
	this->currPlayer = 0;
	this->lastTurn.sidePlayed = "None";
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
	Tile temp0, temp1;
	while(true)
	{
		temp0 = this->boneyard.back();
		cout << players[0]->get_name();
		players[0]->draw_tile(temp0);
		cout << " must draw from the boneyard..." << temp0;
		cout << " was drawn." << endl;
		this->boneyard.pop_back();

		temp1 = this->boneyard.back();
		cout << players[1]->get_name();
		players[1]->draw_tile(temp1);
		cout << " must draw from the boneyard..." << temp1;
		cout << " was drawn." << endl;
		this->boneyard.pop_back();
		// return if player drew the engine, currPlayer is already this player
		if(temp0 == eng)
		{	
			cout << players[0]->get_name();
			cout << " has the engine" << endl << endl;
			this->currPlayer = 0;
			return;
		}
		else if(temp1 == eng)
		{
			cout << players[1]->get_name();
			cout << " has the engine" << endl << endl;
			this->currPlayer = 1;
			return;
		}
	}
}

/*
	void Round::run()
		Acts as a main function for the Round class, setting up the players, 
		their hands, and the boneyard for the round. Need implementation for 
		setting up the board as well.
*/
void Round::run(vector<unique_ptr<Player>> &players, int &round, 
							int &score, bool isSerialized)
{	
	Tile temp(-1, -1);
	cout << "Starting round " << round << endl << endl;
	if(isSerialized && (this->board.get_engine() == temp))
	{
		find_engine(players, round);
		this->lastTurn.tilePlayed = Tile(MAX_ROUNDS - round, MAX_ROUNDS - round);
	}
	else if(!isSerialized)
	{	
		setup_players(players);
		setup_board();
		distribute_tiles(players);
		find_engine(players, round);
		this->lastTurn.tilePlayed = Tile(MAX_ROUNDS - round, MAX_ROUNDS - round);
	}

	// toggle current player, calling play, until a hand is empty
	// for testing while play() doesnt do much
	bool doublePassed = false;
	while(true)
	{
		BoardView bv;
		string choice, tmp;
		cout << "Serialize current game? (Y/N): ";
		while(getline(cin, tmp))
		{
			stringstream ss(tmp);
			ss >> choice;
			if(choice == "Y")
				serialize(board, players, round, boneyard, lastTurn, currPlayer, score);
			else if(choice == "N")
				break;
			else
				cout << "Invalid input. Please input 'Y' to serialize or 'N' continue: ";
		}
		if(this->lastTurn.wasPassed)
			doublePassed = true;
		else
			doublePassed = false;

		this->lastTurn = players[this->currPlayer]->play(
																									this->board,
		 																							this->boneyard,
		 																							this->lastTurn);
		if(this->lastTurn.wasPassed)
		{	
			if(doublePassed)
			{
				tally_score(players);
				return;
			}
		}

		cout << "Last turn: ";
		if(this->lastTurn.wasPassed)
		{
			cout << " passed." << endl;
		}
		else
		{
			cout << this->lastTurn.tilePlayed << " on ";
			cout << this->lastTurn.sidePlayed << endl;
		}

		bv.display_board(board);
		cout << "Boneyard:" << endl;
		cout << this->boneyard;
		
		if(players[currPlayer]->empty())
		{
			tally_score(players, currPlayer);
			return;
		}
		this->currPlayer = 1 - this->currPlayer;
		cout << endl;
	}
} 

void Round::tally_score(vector<unique_ptr<Player>> &players, const int& winner)
{
	int tempLeftPips;
	int tempRightPips;
	int scoreSum = 0;
	int loser = 1 - winner;
	for(Tile &tile : *players[loser])
	{
		tempLeftPips = tile.get_leftPips();
		tempRightPips = tile.get_rightPips();
		scoreSum += tempRightPips + tempLeftPips;
	}

	players[winner]->add_score(scoreSum);
	cout << players[winner]->get_name() << "'s hand is empty. They have won the ";
	cout << "round with a score of ";
	cout << scoreSum << "!" << endl;
}

void Round::tally_score(vector<unique_ptr<Player>> &players)
{
	int score0 = 0;
	int score1 = 0;
	int scoreSum;
	for(Tile &tile : *players[0])
	{
		score0 += tile.get_leftPips() + tile.get_rightPips();
	}
	for(Tile &tile : *players[1])
	{
		score1 += tile.get_leftPips() + tile.get_rightPips();
	}

	int winner;
	if(score0 > score1)
	{
		winner = 1;
		scoreSum = score0;
	}
	else if(score1 > score0)
	{
		winner = 0;
		scoreSum = score1;
	}
	else
	{
		cout << "It's a draw!" << endl;
		return;
	}

	players[winner]->add_score(scoreSum);
	cout << "Both players passed back-to-back. ";
	cout << players[winner]->get_name() << " has won the round with a score of ";
	cout << scoreSum << "!" << endl;
}

void Round::setup_board()
{
	this->board.clear_board();
	this->boneyard.clear();
}

void Round::serialize(Board &board, vector<unique_ptr<Player>> &players, 
										int &round,Boneyard &boneyard, Turn &lastTurn, 
										int &currPlayer, int &score)
{
	// open save.txt using truncate
	ofstream out ("serialize.txt", std::ofstream::trunc);
	// Tournament
	out << "Tournament Score: " << score << endl;
	cout << endl;
	out << "Round No.: " << round << endl << endl;
	// Computer
	out << "Computer: " << endl;
	out << "   Hand: ";
	for(Tile &tile : *players[0])
		out << tile << " ";
	out <<  endl;
	out << "   Score: " << players[0]->get_score() << endl;
	out << endl;
	// Human
	out << "Human: " << endl;
	out << "   Hand: ";
	for(Tile &tile : *players[1])
		out << tile << " ";
	out <<  endl;
	out << "   Score: " << players[1]->get_score() << endl;
	out << endl;
	// Board
	BoardView bv;
	out << "Layout: " << endl;
	out << "  L ";
	for(Tile &tile : board.get_leftSide())
		out << tile << " ";
	Tile temp(-1, -1);
	if(board.get_engine() == temp)
		out << " ";
	else
		out << board.get_engine() << " ";
	for(Tile &tile : board.get_rightSide())
		out << tile << " ";
	out << "R" << endl;
	out << endl;
	out << "Boneyard: " << endl;
	out << boneyard << endl;
	// Last Turn
	out << "Previous Player Passed: ";
	if (lastTurn.wasPassed)
		out << "Yes" << endl;
	else
		out << "No" << endl;
	out << endl;
	// Curr Player
	out << "Next Player: ";
	if(currPlayer == 0)
		out << "Computer" << endl;
	if(currPlayer == 1)
		out << "Human" << endl;
	// write out to file
	// close file
	out.close();
	cout << "Serialization has been written to serialize.txt" << endl;
	// exit program
	exit(0);
}

void Round::set_board(const Board &board)
{
	this->board = board;
}
void Round::set_boneyard(const Boneyard &boneyard)
{
	this->boneyard = boneyard;
}
void Round::set_wasPassed(const bool &wasPassed)
{
	this->lastTurn.wasPassed = wasPassed;
}
void Round::set_currPlayer(const int &currPlayer)
{
	this->currPlayer = currPlayer;
}