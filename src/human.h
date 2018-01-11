/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "board.h"
#include <sstream>
#include <regex>
#include <utility>
#include <locale>

class Human : public Player {
public:
	/**************************************************************************
	Function Name: Human
	Purpose: 
		To intialize a Human object with parameters
	Paramaters:
		s, an integer to set this player's score to
		n, a string to set this player's name to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	Human(const int& s, const string &n) : Player()
	{
		this->score = s;
		this->name = n;
	}
	/**************************************************************************
	Function Name: get_input
	Purpose: 
		To get user input of the choice menu
	Paramaters: None
	Return Value:
		an integer representing the user's choice in the turn menu
	Assistance Received: None
	**************************************************************************/
	int get_input();
	/**************************************************************************
	Function Name: play
	Purpose: 
		To allow a Human player to play a turn. The choices of the turn are:
			1 - Play tile
			2 - Pass
			3 - Help
		Based on the user choice, the player will either attempt to play a
		tile, attempt to pass their turn, or request help
	Paramaters: 
		board, the board the user will interact with
		boneyard, the boneyard the user will draw from if they pass their turn
		lastTurn, a turn object representing the previous turn of the round
	Return Value: 
		an object of type Turn with the tile the user played, the side they
		played the tile, and whether or not they passed their turn
	Local Variables:
		choice, integer holding the user's choice of the menu
		turn, the turn of the user that is the returned value
		bv, the board view object used to display the board
		currPlay, a <integer, string> pair, where the integer is an index of
		their hand representing a tile and the string is the side of the board 
		the player is playing the tile on
	Algorithm:
		1) Get user input
		2) If the user chooses to play a tile, prompt the user for the index of
		their hand representing the tile to be played and the side they want to
		attempt to play the tile on. The program checks the user's attempted play
		for legality. 
			2.a) If the play is legal, the tile is removed from the player's hand
			and pushed back on the appropriate side of the board. 
			2.b) If the the play is illegal, the user is notified and they are
			returned to the initial choice menu
		3) If the user chooses to pass their turn, their hand is checked against
		the board for any legal moves.
			3.a) If their hand contains a legal move, they are notified and returned
			to the intial choice menu
			3.b) If their hand contains no legal move, they successfully pass their
			turn
		4) If the user chooses to request help, the help function is called and a
		recommended move is displayed
	Assistance Received: None
	**************************************************************************/
	Turn play(Board &board, Boneyard &boneyard, Turn &lastTurn);
	/**************************************************************************
	Function Name: help
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
		board. If they are equal, the user must have the engine.
			1.b) Iterate over the player's hand and find the index representing the
			engine. Set bestTile equal to this index, bestSide equal to E(for engine)
			and increment possiblePlays by 1;
		2) If the engine is not empty, iterate ovr the player's hand, summing up
		the pips of each tile. The tile with the highest pip sum has the highest 
		priority to be recommended.
		3) Check to see if the highest priority tile is a legal play on the board.
			3.a) If it is, recommend that tile and the side of the board it can be 
			played. If the tile can be played on either side, play it on their 
			opponent's side. Increment possiblePlays by one, set the bestSide to the
			side being played, and set bestTile to the tile's index in the player's
			hand.
			3.b) If the highest priority tile is not a legal play, then look for the
			next highest priority tile and repeat the process.
		4) If possiblePlays is greater than 0, then the recommended play is
		displayed.
		5) If possiblePlays is 0, then recommend the user passes.
	Assistance Received: None
	**************************************************************************/
	void help(Board &board, Boneyard &boneyard, Turn &lastTurn);
	/**************************************************************************
	Function Name: play_tile
	Purpose: 
		To prompt the user for two inputs, the tile's index in their hand they wish
		to play and the side they wish to play the tile on
	Paramaters:
		board, the board of the round
		lastTurn, the last turn of the round
	Return Value:
		a pair of <int, string> type, where the integer is the tile's index in the
		user's hand they are playing and the string is the side on which the user
		is playing
	Local Variables:
		tileIdx, the user's input for which tile they wish to play
		side, the user's input for which side they wish to play
	Algorithm:
		1) The user is prompted for which tile they wish to play from their hand.
		The choice is made by supplying the program with an integer representing
		the index of their hand where the tile is.
		2) The user is prompted for which side they want to attempt to play the
		tile.
			2.a) If the last turn was passed or the user is attempting to play a
			double, they can play on either side of the board.
			2.b) Otherwise, the user can only play on the left side of the board
			2.c) If the user attempts to play on an illegal side, they are notified
			and given the option to input "Q" as a side to return to the initial
			choice menu
		3) The user's attmepted play is returned as a pair of type <int, string>,
		where the integer is the tile's index in the player's hand and the string
		is the side on which the play is attempting to play on
	Assistance Received: None
	**************************************************************************/
	pair<int, string> play_tile(Board &board, Turn &lastTurn);
	/**************************************************************************
	Function Name: play_engine
	Purpose: 
		To prompt the user to play the engine for the round. The user must enter
		the correct index for the engine or the program will not continue
	Paramaters:
		eng, a tile representing the engine for the round
	Return Value:
		a pair of <int, string> type, where the integer is the tile's index in the
		user's hand they are playing and the string is the side on which the user
		is playing. In this case, the string will always be "E".
	Assistance Received: None
	**************************************************************************/
	pair<int, string> play_engine(Tile &eng);
	/**************************************************************************
	Function Name: pass
	Purpose: 
		To check the user's hand for possible moves and determine if a pass is a
		legal play
	Paramaters:
		b, the board of the round
		lastTurn, the last turn of the round
	Return Value:
		a boolean value representing whether or not the player can pass
	Local variables:
		possiblePlays, an integer representing the number of possible plays in the
		user's hand
	Algorithm:
		1) Check to see if the user is supposed to be playing the engine.
			1.a) If the user is supposed to play engine, increment possiblePlays and
			notify the user of the index and side to play the engine.
		2) If the user is not supposed to play the engine, iterate over the 
		player's hand and check for legal moves.
			2.a) If a legal move is found, increment possiblePlays.
		3) If possible plays is greater than 0, return false, meaning the user
		cannot pass their turn
		4) If possiblePlays is less than 1, return true, meaning the user can pass
		their turn
	Assistance Received: None
	**************************************************************************/
	bool pass(Board &b, Turn &lastTurn);
};

#endif