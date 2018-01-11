/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "hand.h"

using namespace std;

void Hand::erase_tile(const int &index)
{
	this->tiles.erase(this->tiles.begin() + index);
}

ostream &operator<<(ostream& out, Hand &hand)
{
	out << "Hand: " << endl;
	if(hand.empty())
	{
		cout << "(empty)";
	}
	else
	{
		ostringstream tileStream, idxStream;
		string tiles, idxs;
		int i = 1;
		for(Tile &tile : hand)
		{
			tileStream << tile << " ";
			idxStream << "(" << i << ")";
			if(i < 9)
				idxStream << " ";
			tiles = tileStream.str();
			idxs = idxStream.str();
			i++;
		}
		out << "\tIndicies:\t" << idxs << endl;
		out << "\tTiles:\t\t" << tiles << endl;
	}
	cout << endl;
}