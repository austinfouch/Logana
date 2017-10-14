#include "round.h"
#include "human.h"
#include "computer.h"
#include "hand.h"
#include "player.h"
#include <memory>
#include <vector>

using namespace std;

int main()
{	
	/*
	string usr_name;
	cout << "Enter Human player's name: ";
	cin >> usr_name;
	cout << endl;

	vector<unique_ptr<Player>> players;
	players.push_back(make_unique<Human>(0, usr_name));
	players.push_back(make_unique<Computer>(0 , "Computer"));
	
	for(auto &player : players)
		cout << *player << endl;

	Round r1;
	r1.run(players, 1);
	*/

	Board board;
	Tile l0(3, 4); board.push_left(l0);
	Tile l1(4, 4); board.push_left(l1);
	Tile l2(3, 1); board.push_left(l2);
	Tile l3(5, 3); board.push_left(l3);
	Tile eng(6, 6); board.set_eng(eng);
	Tile r0(1, 0); board.push_right(r0);
	Tile r1(6, 3); board.push_right(r1);
	Tile r2(3, 3); board.push_right(r2);
	board.display_board();
}