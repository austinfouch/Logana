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
	this->name = p.name;
}

/*
** 	Player::Player(const Player &p)
**		Copy constructor	
*/
Player::Player(const int &s, const string &n)
{
	this->score = s;
	this->name = n;
}

/*
**	void Player::drawTile()
**		This function pops an tile from the boneyard stack and adds the tile to the calling
**		player's hand.
*/
void Player::clear_hand()
{
	while(!this->hand.empty())
		this->hand.pop_back();
}

/*
**	ostream &operator<<(ostream& out, const Player &p)
**		Overloaded ostream operator, prints hand and score of the player
*/
ostream &operator<<(ostream& out, Player &p)
{
	out << "Name: " << p.name << "\n";
	out << "Score: " << p.score << "\n";
	out << "Hand: " << p.hand;
}