#include "human.h"

/*
**	void Human::play(vector<Tile>&)
**		This function gives the human player the ability to play a tile if they have a legal
**		move. If the human player has no legal moves, they must pass and drawTile.
*/
void Human::play(Board &board)
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
	// TODO: access player.hand, board.pushLeft or board.pushRight
}