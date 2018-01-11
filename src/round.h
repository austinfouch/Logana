/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef ROUND_H
#define ROUND_H
#include "boneyard.h"
#include "tile.h"
#include "board.h"
#include "human.h"
#include "computer.h"
#include "turn.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <fstream>

// constants
// largets pip size
#define MAX_PIPS 6
// smallest pip size
#define MIN_PIPS 0
// standard hand size
#define MAX_HAND_SIZE 8
// number of rounds in a tournament
#define MAX_ROUNDS 7

class Round {
public:
	// default cstor
	Round();
	// copy cstor
	Round(const Round &r);
	/**************************************************************************
	Function Name: run
	Purpose: 
		To run a round until a player wins the round or both players cannot
		play a tile
	Paramaters:
		players, a player vector containing the players of the round
		round, the round number of the round
		score, the tournament score
		isSerialized, bool for loading a serialized game or not
	Return Value: None
	Local Variables:
		doublePassed, true if the current turn and last turn are passed
		bv, a board view object for displaying the round board
		choice, user input to serialize the round or not
	Algorithm:
		1) If the round was serialized, find the engine.
		2) If the round was not serialized, setup the players, setup the board,
		distribute the tiles, find the engine, toggle between the players until
		a player's hand is empty or if both player's passed their turns
		back-to-back
	Assistance Received: None
	**************************************************************************/
	void run(vector<unique_ptr<Player>> &players, int &round, 
					int &score, bool isSerialized);
	/**************************************************************************
	Function Name: setup_players
	Purpose:
		To clear each player's hand 
	Paramaters:
		players, the player vector of the round
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void setup_players(vector<unique_ptr<Player>> &players);
	/**************************************************************************
	Function Name: setup_board
	Purpose: 
		To clear the board of the round
	Paramaters:	None
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void setup_board();
	/**************************************************************************
	Function Name: find_engine
	Purpose: 
		To find the engine for the round and set the current player if they
		have the engine
	Paramaters:
		players, the player vector for the round
		round, an interger containing the current round number
	Local Variables:
		eng, a temporary tile object representing the engine for the round
	Algorithm:
		1) Loop over each player's hand looking for the engine
		2) If it is found in a player's hand, set the player that has the 
		engine as the current player
		3) If the engine is not in a player's hand, both players draw from the
		boneyard.
		4) If a player draws the engine, they are the current player
		5) If not, both players continue to draw until one has the engine
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void find_engine(vector<unique_ptr<Player>> &players, const int &round);
	/**************************************************************************
	Function Name: tally_score
	Purpose: 
		To sum the pips in the losing player's hand and add the sum to the 
		winning player's score. This function is used when the round ends
		due to a player's hand being empty
	Paramaters:
		players, the player vector
		winner, an integer representing the index of the winning player in the
		players vector
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void tally_score(vector<unique_ptr<Player>> &players, const int &winner);
	/**************************************************************************
	Function Name: tally_score
	Purpose: 
		To sum the pips in each player's hand and determine the winner of the 
		round based on which player has a lower pip sum
	Paramaters:
		players, the player vector
	Local Variables:
		score0, an integer representing the sum of the pips in the first 
		player's hand
		score1, an integer representing the sunm of the pips in the second 
		player's hand
	Algorithm:
		1) Loop over each player's hands, summing their pips
		2) The player with the lower pip sum is declared the winner of the 
		round and their opponents pip sum is added to their score
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void tally_score(vector<unique_ptr<Player>> &players);
	/**************************************************************************
	Function Name: serialize
	Purpose: 
		To save the current tournament state to a file
	Paramaters:
		board, the board to be written to the file
		players, the player vector containing the players to be written to the 
		file
		round, the round number to be written to the file
		boneyard, the boneyard to be written to the file
		lastTurn, the turn to be written to the file
		currPlayer, the index representing the next player to have their turn
		score, the tournmanet score to be written to the file
	Local Variables:
		out, the ostream object that is written to during the function
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void serialize(Board &board, vector<unique_ptr<Player>> &players, int &round, 
							Boneyard &boneyard, Turn &lastTurn, int &currPlayer, int &score);
	/**************************************************************************
	Function Name: distribute_tiles
	Purpose: 
		To create a tile vector containing all of the tiles in the round,
		shuffle the list, and distribute the list to each player's hand and the
		boneyard
	Paramaters:
		players, the player vector
	Local Variables:
		tileList, the tile vector where the tiles are initially store to be
		shuffled and distributed
	Algorithm:
		1) Using the constants in round.h, create all of the tiles needed for 
		the round and push them into a vector of tiles
		2) Using std::random_shuffle(), shuffle the tile list
		3) Distribute eight tiles from the shuffled tile list to each player,
		then pop the rest of the tiles in the tile list into the boneyard 
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void distribute_tiles(vector<unique_ptr<Player>> &players);
	/**************************************************************************
	Function Name: set_board
	Purpose: 
		To set the board for the round
	Paramaters:
		board, the board that the round's board will be set to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void set_board(const Board &board);
	/**************************************************************************
	Function Name: set_boneyard
	Purpose: 
		To set the board for the round
	Paramaters:
		boneyard, the boneyard that the round's boneyard will be set to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void set_boneyard(const Boneyard &boneyard);
	/**************************************************************************
	Function Name: set_wasPassed
	Purpose: 
		To set the round's lastTurn property, wasPassed
	Paramaters:
		wasPassed, the boool that the round's lastTurn.wasPassed will be set to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void set_wasPassed(const bool &wasPassed);
	/**************************************************************************
	Function Name: set_currPlayer
	Purpose: 
		To set the round's current player index
	Paramaters:
		currPlayer, the integer that the round's currPlayer will be set to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void set_currPlayer(const int &currPlayer);
private:
	Boneyard boneyard;
	Board board;
	int currPlayer;
	Turn lastTurn;
};

#endif