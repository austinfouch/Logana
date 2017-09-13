#include "board.h"
#include <algorithm>

#define MAX_PIPS 6
#define MIN_PIPS 0
#define NUM_PLAYERS 2

using namespace std;

/*
	void createTiles(vector<Tile>)
		This function creates Tile objects until the fill MAX_PIPS by MAX_PIPS set is
		complete, pushing the objects into a vector for easy random access (shuffling).
*/
void createTiles(vector<Tile> &tileList)
{
	// creates the tile objects 0-0 through 6-6 and pushes into the tileList
	int leftPips, rightPips;
	for(leftPips = MIN_PIPS; leftPips <= MAX_PIPS; leftPips++)
	{
		for(rightPips = leftPips; rightPips <= MAX_PIPS; rightPips++)
		{
			Tile tile(leftPips, rightPips);
			tileList.push_back(tile);
		}
	}
}

/*
	void distributeTiles(vector<Tile>)
		This function randomly accesses elements within the passed and erases them until the 
		vector is empty. This function will later have implementation to distrbiute tiles
		the players' hands and boneyard.
*/
void distributeTiles(vector<Tile> &tileList)
{
	// random access of the tileList and erase of the accessed element
	int size, accessIdx;
	while(!tileList.empty())
	{
		size = tileList.size();
		accessIdx = rand() % size;
		cout << "Size: " << size << "\n";
		cout << "Index " << accessIdx << "\n";

		cout << tileList[accessIdx] << "\n";

		tileList.erase(tileList.begin() + accessIdx);
	}
}

int main()
{	
	// create 6-6 set list, randomly access and erase
	vector<Tile> tileList;
	createTiles(tileList);
	// RNG seed once
	srand(time( NULL));
	random_shuffle(tileList.begin(), tileList.end());
	// ranged-based for-loop printing tiles
	for(const Tile& i : tileList)
		cout << i << "\n";
}