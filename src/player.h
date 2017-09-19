#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "board.h"
#include "hand.h"
#include "boneyard.h"

class Player {
public:
	// default cstor
	Player() {}

	// copy cstor
	Player(const Player &p);

	Player(const int &s, const string &n);

	// implemented in human.cpp and computer.cpp
	virtual void play() {}

	// will clear the hand of the player
	void clear_hand();

	// will be implemented in player.cpp
	void draw_tile(const Tile &t) { push_back(t); }

	void add_score(const int &s) { this->score += s; }

	// access the member Hand hand
	int size() const { return this->hand.size(); }

	void push_back(const Tile &t) { this->hand.push_back(t); }

	Tile& operator[](const int &index) { this->hand[index]; }

	vector<Tile>::iterator begin() { return this->hand.begin(); }

	vector<Tile>::iterator end() { return this->hand.end(); }

	friend ostream &operator<<(ostream& out, Player &p);

protected:
	Hand hand;
	int score;
	string name;
};

#endif