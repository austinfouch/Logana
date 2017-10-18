#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include "computer.h"
#include "human.h"
#include "round.h"
#include <vector>
#include <memory> 
#include <string>

class Tournament {
public:
	Tournament() {}
	~Tournament() {}

	Tournament(const int& score, const int& round) : score(score), round(round) {}
	void set_score(const int &score) { this->score = score; }
	void run();
	void run(string &filename);

	Player get_winner();
	bool check_score(Player &player);

private:
	int score;
	int round;
	vector<unique_ptr<Player>> players;
};
#endif