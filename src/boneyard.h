/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef BONEYARD_H
#define BONEYARD_H
#include "tile.h"
#include <vector>
#include <iterator>

class Boneyard {
public:
	// default cstor
	Boneyard() {}
	// copy cstor
	Boneyard(const Boneyard &by) { this->tiles = by.tiles; }
	/**************************************************************************
	Function Name: pop_back
	Purpose: 
		To remvoe the the back tile from the boneyard
	Paramaters: None
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void pop_back() { this->tiles.pop_back(); }
	/**************************************************************************
	Function Name: clear
	Purpose: 
		To clear the boneyard
	Paramaters: None
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void clear();
	/**************************************************************************
	Function Name: back
	Purpose: 
		To return a reference to back tile of the boneyard
	Paramaters: None
	Return Value:
		reference to the back tile
	Assistance Received: None
	**************************************************************************/
	Tile& back() { return this->tiles.back(); }
	/**************************************************************************
	Function Name: push_back
	Purpose: 
		To push a tile back onto the boneyard
	Paramaters: 
		t, a tile to push back
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void push_back(const Tile &t) { this->tiles.push_back(t); }
	/**************************************************************************
	Function Name: empty
	Purpose: 
		To return true if the boneyard is empty, false if not
	Paramaters: None
	Return Value: 
		true, if the boneyard is empty
		false, if the boneyard is not empty
	Assistance Received: None
	**************************************************************************/
	bool empty() { return this->tiles.empty(); }
	/**************************************************************************
	Function Name: begin
	Purpose: 
		To return a iterator pointing to the begining of the boneyard
	Paramaters: None
	Return Value: 
		iterator of type tile in a vector of type tile
	Assistance Received: None
	**************************************************************************/
	vector<Tile>::iterator begin() { return this->tiles.begin(); }
	/**************************************************************************
	Function Name: end
	Purpose: 
		To return a iterator pointing to the end of the boneyard
	Paramaters: None
	Return Value: 
		iterator of type tile in a vector of type tile
	Assistance Received: None
	**************************************************************************/
	vector<Tile>::iterator end() { return this->tiles.end(); }
	/**************************************************************************
	Function Name: operator=
	Purpose: 
		To overload the assignment operator
	Paramaters: 
		by, the boneyard to initialize this boneyard to
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void operator=(const Boneyard &by) { this->tiles = by.tiles; }
	/**************************************************************************
	Function Name: operator<<
	Purpose: 
		To overload the ostream operator
	Paramaters: 
		out, the ostream that will be wrote to
		by, the boneyard to write to out
	Return Value: 
		an ostream object
	Assistance Received: None
	**************************************************************************/
	friend ostream &operator<<(ostream& out, Boneyard &by);
private:
	vector<Tile> tiles;
};

#endif