#include "hand.h"

using namespace std;

/*
**	Tile Hand::remove(const Tile &t)
**		This function will search for tile in member tiles that is equal to the input object.
**		If no equal object is found in the member tiles, then the action will be cancelled and
**		handled.
*/
Tile Hand::play_tile(const Tile &t)
{
	//
}

/*
**	ostream &operator<<(ostream& out, const Hand &h)
**		Overloaded ostream operator, prints tiles of the hand member to console.
*/
ostream &operator<<(ostream& out, const Hand &h)
{
	if(h.size() > 0)
		for(int i = 0; i < h.size(); i++)
			out << h.tiles[i] << " ";
	out << "";
}