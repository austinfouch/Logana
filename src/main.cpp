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

	vector<unique_ptr<Player>> players;
	players.push_back(make_unique<Human>(0, usr_name));
	players.push_back(make_unique<Computer>(0 , "Computer"));
	
	for(auto &player : players)
		cout << *player << endl;

	Round r1;
	r1.run(players, 1);
	
}