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
	string usr_name;
	cout << "Enter Human player's name: ";
	cin >> usr_name;
	cout << endl;

	/*
	Human human(100, "Austin");
	Computer computer(50, "Computer");

	vector<Player> players;
	players.push_back(computer);
	players.push_back(human);
	*/

	vector<unique_ptr<Player>> players;
	players.push_back(make_unique<Human>(100, "Austin"));
	players.push_back(make_unique<Computer>(50, "Computer"));
	
	for(auto &it : players)
		it->test();

	Round r1;
	r1.run(players, 6);
}