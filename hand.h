#include "tile.cpp"

class Hand {
public:
	Hand(const vector<Tile> &ts);
	void operator=(const Hand &h);
private:
	vector<Tile> tiles;
}