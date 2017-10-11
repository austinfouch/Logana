#include "human.h"

/*
**	void Human::play(vector<Tile>&)
**		This function gives the human player the ability to play a tile if they 
**		have a legal move. If the human player has no legal moves, they must 
**		pass and draw a tile.
*/
void Human::play(Board &board, Boneyard &boneyard)
{
	int choice;
	while(true)
	{
		choice = get_input();
		switch(choice)
		{
			case 1:
				cout << "Displaying player hand..." << endl;
				show_hand();
				continue;

			case 2:
				cout << "Viewing board..." << endl << endl;
				cout << board;
				continue;

			case 3:
				cout << "Playing tile..." << endl << endl;

				break;

			case 4:
				cout << "Attempting to pass turn..." << endl << endl;
				// call help which will return the tile for the best play
				// if help returns a tile of -1--1, then pass turn
				// otherwise, tell player that there is a possible turn
				continue;

			case 5:
				cout << "Displaying help..." << endl << endl;
				continue;
		}
	}
}

int Human::get_input()
{
	int choice = 0;
	cout << "1 - Show hand" << endl;
	cout << "2 - Show board" << endl;
	cout << "3 - Play tile" << endl;
	cout << "4 - Pass" << endl;
	cout << "5 - Help" << endl;
	cout << "Choice: ";
	while(!(cin >> choice) || (choice < 1 || choice > 5))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again with an integer between 1-5." << endl;
		cout << "Choice: ";
	}
	cout << endl;
	return choice;
}
/*
**	void Human::help()
**		This function is only callable by the human player during their turn. It will
**		display the next best legal move the player has to make, and if no legal moves
**		can be made, will instruct the player to pass their turn.
*/
void Human::help()
{
	// TODO: access player.hand, board.pushLeft or board.pushRight
}