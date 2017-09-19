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

	Round r1;
	r1.run(players);
}