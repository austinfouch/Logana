/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include "computer.h"
#include "human.h"
#include "round.h"
#include <vector>
#include <memory> 
#include <string>

class Tournament {
public:
	// default cstor
	Tournament() {}

	/**************************************************************************
	Function Name: run
	Purpose: 
		To intitialize a tournament and run rounds until a player's score
		exceeds the tournmanet score
	Paramaters: None
	Return Value: None
	Local Variables:
		choice, a string used to store user input on serialization
		inFile, the file being used for serialization if needed
		user_score, the tournmanet score entered by the user
		round, round object used to set and initialize the tournament round
	Algorithm:
		1) Get user input on serialization
			1.a) If yes, get file name from user and run the tournament with
			runSerialize()
		2) If user selected no serialization, get tournanment score input
		3) Set up first round and run until a player's score exceeds the 
		tournmanet score.
	Assistance Received: None.
	**************************************************************************/
	void run();
	/**************************************************************************
	Function Name: runSerialized
	Purpose: 
		To intitialize a tournament and run rounds until a player's score
		exceeds the tournmanet score. This tournament is based off of the game
		store in the input text file.
	Paramaters:
		filename, a string containing the name of the file containing the stored
		game.
	Return Value: None
	Local Variables:
		board, a board object containing the parsed board from the input file
		boneyard, a boneyard object containing the parsed board from the input file
		wasPassed, a bool variable containing the parsed previous turn passed value
		currPlayer, a integer containing the index value of the current player in
		the players vector
		round, round object used to set and initialize the tournament round
	Algorithm:
		1) Open the file filename and parse the data into the local variables
		2) Set up round based on parsed data and run until a player's score 
		exceeds the tournmanet score.
	Assistance Received: None.
	**************************************************************************/
	void run_serialized(string &filename);
	/**************************************************************************
	Function Name: get_winner
	Purpose: 
		To return the winning player of the tournament
	Paramaters: None
	Return Value: an object of type Player
	Assistance Received: None.
	**************************************************************************/
	Player get_winner();
	/**************************************************************************
	Function Name: check_score
	Purpose: 
		To return true if the player's score is greater than or equal to the
		tournament score
	Paramaters: 
		player, the player who's score will be checked
	Return Value: 
		true, if the player's score is greater than or equal to the
		tournament score
		false, if not
	Assistance Received: None.
	**************************************************************************/
	bool check_score(Player &player);
	/**************************************************************************
	Function Name: set_score
	Purpose: 
		To set the member variable score
	Paramaters: 
		score, the integer that the member variable score is set to
	Return Value: 
		None
	Assistance Received: None.
	**************************************************************************/
	void set_score(const int &score) { this->score = score; }
private:
	// holds the tournamnet score set by the user
	int score;
	// holds the round number to be passed to a round object
	int round;
	// holds the players of the current tournament
	vector<unique_ptr<Player>> players;
};
#endif