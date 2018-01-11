/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "board.h"

using namespace std;

Board::Board(const Board &b)
{
	this->engine = b.engine;
	this->leftSide = b.leftSide;
	this->rightSide = b.rightSide;
}

void Board::push_left(const Tile &t)
{
	this->leftSide.push_back(t);
}

void Board::push_right(const Tile &t)
{
	this->rightSide.push_back(t);
}

void Board::operator=(const Board &b)
{
	this->engine = b.engine;
	this->leftSide = b.leftSide;
	this->rightSide = b.rightSide;
}

void Board::clear_board()
{
	while(!this->leftSide.empty())
		this->leftSide.pop_back();

	while(!this->rightSide.empty())
		this->rightSide.pop_back();

	this->engine = Tile(-1, -1);
}