/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "turn.h"
#include "board.h"
#include "boardView.h"
#include "hand.h"
#include "boneyard.h"

class Player {
public:
	// default cstor
	Player() {}
	// copy cstor
	Player(const Player &p);
	// copy cstor
	Player(const int &s, const string &n);
	/**************************************************************************
	Function Name: play
	Purpose: 
		Nothing, virtual fucnction
	Paramaters:
		board, the board of the round
		boneyard, the boneyard of the round
		lastTurn, the last turn of the round
	Return Value:
		an object of type Turn
	Assistance Received: None
	**************************************************************************/
	virtual Turn play(Board &board, Boneyard &boneyard, Turn &lastTurn) {}
	/**************************************************************************
	Function Name: clear_hand
	Purpose: 
		To clear the player's hand. Until the player's hand is empty, the
		player's hand is popped
	Paramaters: None
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void clear_hand();
	/**************************************************************************
	Function Name: show_hand
	Purpose: 
		To display the player's hand
	Paramaters: None
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void show_hand() { cout << this->name << "'s " << this->hand; }
	/**************************************************************************
	Function Name: draw_tile
	Purpose: 
		To push back a tile to the player's hand
	Paramaters:
		t, the tile to be pushed back
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void draw_tile(const Tile &t) { push_back(t); }
	/**************************************************************************
	Function Name: add_score
	Purpose: 
		To add a round score to the player's tournament score
	Paramaters:
		s, an integer to add to the player's score
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void add_score(const int &s) { this->score += s; }
	/**************************************************************************
	Function Name: set_score
	Purpose: 
		To set the player's score
	Paramaters:
		s, an integer to set this player's score to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void set_score(const int &s) { this->score = s; }
	/**************************************************************************
	Function Name: get_score
	Purpose: 
		To return the player's score
	Paramaters: None
	Return Value:
		an integer representing the player's score
	Assistance Received: None
	**************************************************************************/
	int get_score() const { return this->score; }
	/**************************************************************************
	Function Name: size
	Purpose: 
		To return the size of the player's hand
	Paramaters: None
	Return Value:
		an interger representing the size of the player's hand
	Assistance Received: None
	**************************************************************************/
	int size() const { return this->hand.size(); }
	/**************************************************************************
	Function Name: empty
	Purpose: 
		To return true if the player's hand is empty or false if otherwise
	Paramaters: None
	Return Value:
		true if the player's hand is empty
		false if the player's hand is not empty
	Assistance Received: None
	**************************************************************************/
	bool empty() { return this->hand.empty(); }
	/**************************************************************************
	Function Name: push_back
	Purpose: 
		To push back a tile onto the player's hand
	Paramaters:
		t, the tile to be pushed back onto the player's hand
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void push_back(const Tile &t) { this->hand.push_back(t); }
	/**************************************************************************
	Function Name: get_name
	Purpose: 
		To return the player's name
	Paramaters: None
	Return Value:
		a string representing the player's name
	Assistance Received: None
	**************************************************************************/
	const string get_name() { return this->name; }
	/**************************************************************************
	Function Name: operator[]
	Purpose: 
		To overload the index operator, giving index access to the player's
		hand
	Paramaters:
		index, the index of the player's hand the player is accessing
	Return Value:
		a reference to the tile in the player's hand reprensented by the passed
		index
	Assistance Received: None
	**************************************************************************/
	Tile& operator[](const int &index) { this->hand[index]; }
	/**************************************************************************
	Function Name: begin
	Purpose: 
		To return a iterator pointing to the begining of the player's hand
	Paramaters: None
	Return Value: 
		iterator of type tile in a vector of type tile
	Assistance Received: None
	**************************************************************************/
	vector<Tile>::iterator begin() { return this->hand.begin(); }
	/**************************************************************************
	Function Name: end
	Purpose: 
		To return a iterator pointing to the end of the player's hand
	Paramaters: None
	Return Value: 
		iterator of type tile in a vector of type tile
	Assistance Received: None
	**************************************************************************/
	vector<Tile>::iterator end() { return this->hand.end(); }
	/**************************************************************************
	Function Name: legal_play
	Purpose: 
		To check the passed play for legality against the passed board
	Paramaters:
		thePlay, a pair of type <int, string> representing the play being
		attempted. The integer is a tile index and the string is a board side
		board, the board of the round
	Return Value: 
		true if the play is legal
		fasle if it is not
	Local variables:
		inLeftPips, an integer representing the left pips of the tile in the 
		player's hand at the index passed
		inRightPips, an integer representing the right pips of the tile in the 
		player's hand at the index passed
	Algorithm:
		1) Set inLeftPips and inRightPips based on the player's hand and the
		index passed to the function
		2) If the play is attempting to play a tile on the left side, check the
		board's left most tile. If this tile's left pips are equal to either
		inRightPips or inLeftPips, return true.
		3) If the play is attempting to play on the right side, check the
		board's right most tile. If this tile's right pips are equal to either
		inRightPips or in LeftPips, return true.
		4) Otherwise, return false.
	Assistance Received: None
	**************************************************************************/
	bool legal_play(pair<int, string> thePlay, Board &board);
	/**************************************************************************
	Function Name: remove_tile
	Purpose: 
		To remove the tile in the player's hand at the given index
	Paramaters:
		index, an integer representing the index of the tile the player wishes
		to remove
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void remove_tile(const int &index);
	/**************************************************************************
	Function Name: operator<<
	Purpose: 
		To overload the ostream operator
	Paramaters: 
		out, the ostream that will be wrote to
		p, the player to write to out
	Return Value: 
		an ostream object
	Assistance Received: None
	**************************************************************************/
	friend ostream &operator<<(ostream& out, Player &p);
protected:
	Hand hand;
	int score;
	string name;
};

#endif