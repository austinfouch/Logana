/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include "board.h"

class Computer : public Player {
public:
	/**************************************************************************
	Function Name: Computer
	Purpose: 
		To intialize a Computer object with parameters
	Paramaters:
		s, an integer to set this player's score to
		n, a string to set this player's name to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	Computer(const int &s, const string &n) : Player()
	{
		this->score = s;
		this->name = n;
	}
	/**************************************************************************
	Function Name: play
	Purpose: 
		To display to the user a recommended play based on their hand and the board
	Paramaters:
		board, the board of the current round
		boneyard, the boneyard of the current round
		lastTurn, the last turn of the round for determing if there was a pass
	Return Value: None
	Local Variables:
		possiblePlays, an integer representing the number of possible, legal plays
		the user can make
		bestSum, an integer representing the highest sum of pips for each tile in
		the player's hand
		bestSide, a string representing the side of the recommended play
		bestTile, an integer representing an index of the player's hand
		representing the recommended tile to be played
	Algorithm:
		1) Create an empty tile (-1,-1) and compare it against the engine of the
		board. If they are equal, the computer must have the engine.
			1.b) Iterate over the computer's hand and find the index representing
			the engine. Set bestTile equal to this index, bestSide equal to 
			E(for engine). Increment possiblePlays.
		2) If the engine is not empty, iterate over the computer's hand, summing
		up the pips of each tile. The tile with the highest pip sum has the 
		highest priority in the computer's attempt at a play.
		3) Check to see if the highest priority tile is a legal play on the board.
			3.a) If it is, play that tile and the side of the board it can be 
			played. If the tile can be played on either side, play it on their 
			opponent's side. Set the bestSide to the side being played, and set 
			bestTile to the tile's index in the computer's hand. Increment
			possiblePlays
			3.b) If the highest priority tile is not a legal play, then look for the
			next highest priority tile and repeat the process.
		4) If possiblePlays is greater than 0, then complete the play according
		to bestTile and bestSide and return a turn object representing this play
		5) If possiblePlays is 0, then return a turn object representing the
		computer has passed its turn
	Assistance Received: None
	**************************************************************************/
	Turn play(Board &board, Boneyard &boneyard, Turn &lastTurn);
	
};

#endif