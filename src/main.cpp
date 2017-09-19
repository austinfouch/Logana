#include "round.h"
#include "human.h"
#include "computer.h"
#include "hand.h"

using namespace std;

int main()
{	
	string usr_name;
	cout << "Enter Human player's name: ";
	cin >> usr_name;
	cout << "\n";
	
	Human player1(0, usr_name);
	Computer player2(0, "Computer");

	vector<Player> players;
	players.push_back(player1);
	players.push_back(player2);

	for(auto &it : players)
		cout << it << "\n";

	Round r1;
	r1.run(players, 6);

	for(auto &it : players)
		cout << it << "\n";
}