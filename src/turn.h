/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef TURN_H
#define TURN_H
#include <string>
#include "tile.h"

class Turn {
public:
	// default cstor
	Turn() : wasPassed(false), sidePlayed("None") {}
	
	Tile tilePlayed;
	bool wasPassed;
	string sidePlayed;
};

#endif
