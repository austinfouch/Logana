/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef HAND_H
#define HAND_H
#include "tile.h"
#include <vector>
#include <algorithm>
#include <sstream>

class Hand {
public:
	// default cstor
	Hand() {}	
	// copy cstor
	Hand(const Hand &h) { this->tiles = h.tiles; }
	/**************************************************************************
	Function Name: push_back
	Purpose: 
		To push back a tile to this hand
	Paramaters: 
		t, the tile to be pushed back
	Return Value: None
	Assistance Received: None
	**************************************************************************/	
	void push_back(const Tile &t) { this->tiles.push_back(t); }
	/**************************************************************************
	Function Name: pop_back
	Purpose: 
		To pop back this hand
	Paramaters: None
	Return Value: None
	Assistance Received: None
	**************************************************************************/	
	void pop_back() { this->tiles.pop_back(); }
	/**************************************************************************
	Function Name: size
	Purpose: 
		To return the size of this hand
	Paramaters: None
	Return Value:
		an interger representing the size of this hand
	Assistance Received: None
	**************************************************************************/		
	int size() const { return this->tiles.size(); }
	/**************************************************************************
	Function Name: empty
	Purpose: 
		To return true if this hand is empty, false otherwise
	Paramaters: None
	Return Value:
		true if this hand is empty
		false otherwise
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
	Function Name: erase_tile
	Purpose: 
		To erase the tile at the given index in this hand
	Paramaters:
		index, an integer representing the tile to be erased in this hand
	Return Value: None
	Assistance Received: None
	**************************************************************************/
	void erase_tile(const int &index);
	/**************************************************************************
	Function Name: operator=
	Purpose: 
		To overload the assignment operator
	Paramaters: 
		h, the hand to initialize this hand to
	Return Value: None
	Assistance Received: None
	**************************************************************************/	
	void operator=(const Hand &h) { this->tiles = h.tiles; }
	/**************************************************************************
	Function Name: operator[]
	Purpose: 
		To overload the index operator, giving index access to this hand
	Paramaters:
		index, the index of this hand
	Return Value:
		a reference to the tile in this hand reprensented by the passed
		index
	Assistance Received: None
	**************************************************************************/	
	Tile &operator[](const int &index) { return this->tiles[index]; }
	/**************************************************************************
	Function Name: operator<<
	Purpose: 
		To overload the ostream operator
	Paramaters: 
		out, the ostream that will be wrote to
		h, the hand to write to out
	Return Value: 
		an ostream object
	Assistance Received: None
	**************************************************************************/
	friend ostream &operator<<(ostream& out, Hand &h);
private:
	vector<Tile> tiles;
};

#endif