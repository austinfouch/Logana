#include "round.h"
#include "human.h"
#include "computer.h"
#include "hand.h"

using namespace std;

int main()
{	
	Human player1(100, "Austin");
	Computer player2(150, "Computer");

	vector<Player> players;
	players.push_back(player1);
	players.push_back(player2);

	cout << players[0] << "\n";
	Round r1(players);
	players = r1.run();
	cout << players[0] << "\n";
}