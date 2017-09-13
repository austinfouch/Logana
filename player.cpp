#include "player.h"

Player::Player(const int &s, const Hand &h)
{
	this->hand = h;
	this->score = s;
}


/*
**	void Player::drawTile()
**		This function pops an tile from the boneyard stack and adds the tile to the calling
**		player's hand.
*/
void Player::drawTile()
{
	// pop tile from boneyard and copy to hand
}

/*
**	void Human::play(vector<Tile>&)
**		This function gives the human player the ability to play a tile if they have a legal
**		move. If the human player has no legal moves, they must pass and drawTile.
*/
void Human::play(vector<Tile> &board)
{
	// allow user to:
		// display hand
		// display board
		// attempt to play tile (need to verify and respond success or fail)
		// if attempt came as a fail and there are no playable moves (help is empty)
		// pass turn and drawTile()
}

/*
**	void Human::help()
**		This function is only callable by the human player during their turn. It will
**		display the next best legal move the player has to make, and if no legal moves
**		can be made, will instruct the player to pass their turn.
*/
void Human::help()
{

}

/*
**	void Computer::play(vector<Tile>&)
**		This function will simulate a computer player playing against a human. It will
**		make the the best tile play possible, and if no legal moves are available, the 
**		computer will pass and drawTile.
*/
void Computer::play(vector<Tile> &board)
{
	// create algorithm to assess hand against the board, and play or pass
}