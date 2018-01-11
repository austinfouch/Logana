/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "boardView.h"

void BoardView::display_board(Board &board)
{
	ostringstream firstLine, secondLine;
	cout << "The board:" << endl;
	firstLine << "  ";
	secondLine << "L ";

	for(int tile = board.get_leftSide().size() - 1; tile >= 0; --tile)
	{
		if(board.get_leftSide()[tile].is_double())
		{
			firstLine << board.get_leftSide()[tile].get_leftPips() << " ";
			secondLine << "| ";
		}
		else
		{
			secondLine << board.get_leftSide()[tile] << " ";
			firstLine << "    ";
		}
	}

	Tile tmp(-1, -1);
	if(board.get_engine() == tmp)
	{
		secondLine << "(empty) ";
	}
	else
	{
		firstLine << board.get_engine().get_leftPips() << " ";
		secondLine << "| ";
	}

	for(Tile &tile : board.get_rightSide())
	{
		if(tile.is_double())
		{
			firstLine << tile.get_leftPips() << " ";
			secondLine << "| ";
		}
		else
		{
			secondLine << tile << " ";
			firstLine << "    ";
		}
	}

	secondLine << "R";

	string first = firstLine.str();
	string second = secondLine.str();
	cout << first << endl;
	cout << second << endl;
	cout << first << endl;
}
