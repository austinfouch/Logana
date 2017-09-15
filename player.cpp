#include "player.h"

using namespace std;

/*
** 	Player::Player(const Player &p)
**		Copy constructor	
*/
Player::Player(const Player &p)
{
	this->hand = p.hand;
	this->score = p.score;
}

/*
**	void Player::drawTile()
**		This function pops an tile from the boneyard stack and adds the tile to the calling
**		player's hand.
*/
void Player::draw_tile(const Tile &t)
{
	push_back(t);
}

/*
**	void Player::push_back(const Tile &t)
**		This function gives access to Player.hand.push_back().
*/
void Player::push_back(const Tile &t)
{
	this->hand.push_back(t);
}

/*
**	Tile& Player::operator[](const int &index
**		This function allows access to the elements of the Player.hand memeber variable.
**		A player's hand can now be accessed with the syntax Player p[some_index].
*/
Tile& Player::operator[](const int &index)
{
	this->hand[index];
}