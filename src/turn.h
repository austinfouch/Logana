#ifndef TURN_H
#define TURN_H
#include "tile.h"

class Turn {
public:
	Turn() : wasPassed(false), sidePlayed('0') {}
	Tile tilePlayed;
	bool wasPassed;
	char sidePlayed;
};

#endif
