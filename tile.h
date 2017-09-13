#include <iostream>

using namespace std;

class Tile {
public:
	Tile(): leftPips(0), rightPips(0) {}
	Tile(int lPips, int rPips);
	void swapPips();
	void operator=(const Tile &t);
	friend ostream &operator<<(ostream& out, const Tile &t);
private:
	int leftPips, rightPips;
};

