#include "hand.cpp"
#include ""

class Player {
public:
	Player();
	~Player();
	Player(const int &s, const Hand &h);
	virtual void play();
	void drawTile();
private:
	Hand hand;
	int score;
};

class Human(Player) {
public:
	void play(vector<Tile> &board);
	void help();
};

class Computer(Player) {
public:
	void play(vector<Tile> &board);
};