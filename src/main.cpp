/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
/******************************************************************************
* Program Listing:
* 1. Tournament::run()
* 2. Round::run()
* 3. Player::play()
* 4. Human::play() or Computer::play()
******************************************************************************/
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