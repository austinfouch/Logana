#include <stack>
#include "tile.cpp"

using namespace std;

class Board{
public:
	Board();
	~Board();
	Board(const Tile &eng, const vector<Tile> &left, const vector<Tile> &right);
	void clear();
	void pushLeft(const Tile &t);
	void pushRight(const Tile &t);
	void operator=(const Board &b);
	friend ostream &operator<<(ostream& out, const Board &b);
private:
	Tile engine;
	vector<Tile> leftSide;
	vector<Tile> rightSide;
};