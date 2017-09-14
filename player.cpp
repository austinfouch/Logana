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

void Player::play()
{
}

void Player::push_back(const Tile &t)
{
	this->hand.push_back(t);
}

Tile& Player::operator[](const int index)
{
	this->hand[index];
}