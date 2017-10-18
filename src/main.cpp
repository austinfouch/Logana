#include "round.h"
#include "human.h"
#include "computer.h"
#include "hand.h"
#include "player.h"
#include "board.h"
#include "boardView.h"
#include "tournament.h"
#include <memory>
#include <vector>

using namespace std;

int main()
{
	Tournament tourney;
	tourney.run();
	return 0;
}