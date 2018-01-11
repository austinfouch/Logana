/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef TILE_H
#define TILE_H
#include <iostream>

using namespace std;

class Tile {
public:
	// default cstor, (-1,-1) is recognized as an empty tile in this program
	Tile() : leftPips(-1), rightPips(-1) {}
	// copy cstor
	Tile(const int &lPips, const int &rPips);
	// copy cstor
	Tile(const Tile &t);
	/**************************************************************************
	Function Name: swap_pips
	Purpose: 
		To swap the pips of this tile
	Paramaters: None
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void swap_pips();
	/**************************************************************************
	Function Name: is_double
	Purpose: 
		To return true if this tile's pips are equal or false if they are not
	Paramaters: None
	Return Value:
		a boolean that is true if the tile's pips are equal or false if they
		are not
	Assistance Received: None
	**************************************************************************/
	bool is_double() { return this->leftPips == this-> rightPips; }
	/**************************************************************************
	Function Name: get_leftPips
	Purpose: 
		To return this tile's left pip value
	Paramaters: None
	Return Value:
		an integer representing this tile's right pip value
	Assistance Received: None
	**************************************************************************/
	int get_leftPips() const { return this->leftPips; }
	/**************************************************************************
	Function Name: get_rightPips
	Purpose: 
		To return this tile's right pip value
	Paramaters: None
	Return Value: 
		an integer representing this tile's right pip value
	Assistance Received: None
	**************************************************************************/
	int get_rightPips() const { return this->rightPips; }
	/**************************************************************************
	Function Name: operator==
	Purpose: 
		To compare this tile against the passed tile for equality
	Paramaters:
		t, the tile to compare equality against
	Return Value:
		true if this tile's pips are equal to t's pips
		false if not
	Assistance Received: None
	**************************************************************************/
	bool operator==(const Tile &t);
	/**************************************************************************
	Function Name: operator=
	Purpose: 
		To overload the assignment operator
	Paramaters:
		t, the tile to set this tile to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void operator=(const Tile &t);
	/**************************************************************************
	Function Name: operator<<
	Purpose: 
		To overload ostream operator
	Paramaters:
		out, the stream to write the tile out to
		t, the tile to be written to out
	Return Value:
		an ostream object containing the written tile
	Assistance Received: None
	**************************************************************************/
	friend ostream &operator<<(ostream& out, const Tile &t);
private:
	int leftPips, rightPips;
};

#endif