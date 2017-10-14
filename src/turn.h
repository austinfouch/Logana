#ifndef TURN_H
#define TURN_H
#include "tile.h"

class Turn {
public:
	// default cstor
	Turn() : wasPassed(false), sidePlayed('0') {}

	// selectors
	Tile get_tilePlayed() const { return this->tilePlayed; }
	bool get_wasPassed() const { return this->wasPassed; }
	char get_sidePlayed() const { return this->sidePlayed; }

	// mutators
	void set_tilePlayed(const Tile &tile);
	void set_wasPassed(const bool &wasPassed);
	void set_sidePlayed(const char &side);
	
	Tile tilePlayed;
	bool wasPassed;
	char sidePlayed;
};

#endif
