/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "player.h"

using namespace std;

Player::Player(const Player &p)
{
	this->hand = p.hand;
	this->score = p.score;
	this->name = p.name;
}

Player::Player(const int &s, const string &n)
{
	this->score = s;
	this->name = n;
}

void Player::clear_hand()
{
	while(!this->hand.empty())
		this->hand.pop_back();
}

bool Player::legal_play(pair<int, string> thePlay, Board &board)
{	
	int inLeftPips, inRightPips;
	inLeftPips = this->hand[thePlay.first].get_leftPips();
	inRightPips = this->hand[thePlay.first].get_rightPips();

	int tmpLeftSide, tmpRightSide;
	if(thePlay.second == "L")
		if(board.get_leftSide().empty())
			tmpLeftSide = board.get_engine().get_leftPips();
		else
			tmpLeftSide = board.get_leftSide().back().get_leftPips();
	else if(thePlay.second == "R")
		if(board.get_rightSide().empty())
			tmpRightSide = board.get_engine().get_leftPips();
		else
			tmpRightSide = board.get_rightSide().back().get_rightPips();

	if(inLeftPips == tmpLeftSide || inLeftPips == tmpRightSide)
		return true;
	if(inRightPips == tmpLeftSide || inRightPips == tmpRightSide)
		return true;
	
	return false;
}

void Player::remove_tile(const int &index)
{
	this->hand.erase_tile(index);
}

ostream &operator<<(ostream& out, Player &p)
{
	out << "Name: " << p.name << "\n";
	out << "Score: " << p.score << "\n";
	out << p.hand;
}