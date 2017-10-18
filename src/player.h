#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "turn.h"
#include "board.h"
#include "boardView.h"
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
	virtual Turn play(Board &board, Boneyard &boneyard, Turn &lastTurn) {}

	// will clear the hand of the player
	void clear_hand();

	void show_hand() { cout << this->name << "'s " << this->hand; }

	// will be implemented in player.cpp
	void draw_tile(const Tile &t) { push_back(t); }

	void add_score(const int &s) { this->score += s; }

	void set_score(const int &s) { this->score = s; }
	
	int get_score() const { return this->score; }

	// access the member Hand hand
	int size() const { return this->hand.size(); }

	bool empty() { return this->hand.empty(); }

	void push_back(const Tile &t) { this->hand.push_back(t); }

	const string get_name() { return this->name; }

	Tile& operator[](const int &index) { this->hand[index]; }

	vector<Tile>::iterator begin() { return this->hand.begin(); }

	vector<Tile>::iterator end() { return this->hand.end(); }

	bool legal_play(pair<int, string> thePlay, Board &board);

	void remove_tile(const int &index);

	friend ostream &operator<<(ostream& out, Player &p);

protected:
	Hand hand;
	int score;
	string name;
};

#endif