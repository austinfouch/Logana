/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "human.h"

Turn Human::play(Board &board, Boneyard &boneyard, Turn &lastTurn)
{
	int choice;
	Turn turn;
	BoardView bv;
	pair<int, string> currPlay;
	while(true)
	{
		cout << this->name << "'s turn: " << endl;
		choice = get_input();
		switch(choice)
		{
			case 1:
				bv.display_board(board);
				show_hand();
				currPlay = play_tile(board, lastTurn);
				if(currPlay.second == "Q")
				{
					cout << "Returning to choice menu..." << endl << endl;
				}
				else if(currPlay.second == "E")
				{
					turn.tilePlayed = this->hand[currPlay.first];
					turn.sidePlayed = "E";
					turn.wasPassed = false;
					cout << endl;
					cout << this->name << " played " << currPlay.first << ", ";
					cout << "the engine." << endl;
					board.set_engine(turn.tilePlayed);
					remove_tile(currPlay.first);
					return turn;
				}
				else if(legal_play(currPlay, board))
				{
					turn.tilePlayed = this->hand[currPlay.first];
					cout << endl;
					cout << this->name << " played " << turn.tilePlayed << " ";
					cout << "on " << currPlay.second <<  "." << endl;
					turn.sidePlayed = currPlay.second;
					turn.wasPassed = false;
					if(turn.sidePlayed == "L")
					{
						int tmpLeftPips;
						if(board.get_leftSide().empty())
							tmpLeftPips = board.get_engine().get_leftPips();
						else
							tmpLeftPips = board.get_leftSide().back().get_leftPips();

						if(turn.tilePlayed.get_rightPips() != tmpLeftPips)
							turn.tilePlayed.swap_pips();
						
						board.push_left(turn.tilePlayed);
					}
					else if(turn.sidePlayed == "R")
					{
						int tmpRightPips;
						if(board.get_rightSide().empty())
							tmpRightPips = board.get_engine().get_rightPips();
						else
							tmpRightPips = board.get_rightSide().back().get_rightPips();

						if(turn.tilePlayed.get_leftPips() != tmpRightPips)
							turn.tilePlayed.swap_pips();
						
						board.push_right(turn.tilePlayed);
					}

					remove_tile(currPlay.first);
					return turn;	
				}
				else
					cout << "Invalid play. Attempt a new play." << endl << endl;
				
				break;

			case 2:
				cout << "Attempting to pass turn..." << endl << endl;
				// call help which will return the tile for the best play
				// if help returns a tile of -1--1, then pass turn
				// otherwise, tell player that there is a possible turn
				if(pass(board, lastTurn))
				{
					turn.tilePlayed = Tile(-1, -1);
					turn.sidePlayed = "None";
					turn.wasPassed = true;
					cout << this->name << " passed.";
					if(!boneyard.empty())
					{
						Tile temp = boneyard.back();
						this->hand.push_back(temp);
						cout << " Drawing from the boneyard..." << temp;
						cout << " was drawn" << endl;
						boneyard.pop_back();
						int drawnIndex = this->hand.size() - 1;
						pair<int, string> thePlay;
						thePlay.first = drawnIndex;
						thePlay.second = "L";
						if(legal_play(thePlay, board))
						{
							Tile temp;
							temp = this->hand[thePlay.first];
							Turn turn;
							turn.wasPassed = false;
							turn.sidePlayed = "L";
							turn.tilePlayed = temp;
							remove_tile(thePlay.first);
							if(temp.get_rightPips() != board.get_leftSide().back().get_leftPips())
								temp.swap_pips();
							board.push_left(temp);
							cout << "Human's 'best' play: ";
							cout << turn.tilePlayed << " on " << turn.sidePlayed << endl;
							return turn;
						}
						else
						{
							thePlay.second = "R";
							if(legal_play(thePlay, board) && lastTurn.wasPassed)
							{
								Tile temp;
								temp = this->hand[thePlay.first];
								Turn turn;
								turn.wasPassed = false;
								turn.sidePlayed = "R";
								turn.tilePlayed = temp;
								remove_tile(thePlay.first);
								if(temp.get_leftPips() != board.get_rightSide().back().get_rightPips())
									temp.swap_pips();
								board.push_right(temp);
								cout << "Human's 'best' play: ";
								cout << turn.tilePlayed << " on " << turn.sidePlayed << endl;
								return turn;
							}
						}

					}	
					cout << endl;
					return turn;
				}
				else
				{
					cout << "You cannot pass your turn while legal plays are still";
					cout << " possible." << endl;
					cout << "If you do not see any legal plays, try using help." << endl;
					break;
				}

			case 3:
				cout << "Displaying help..." << endl << endl;
				help(board, boneyard, lastTurn);
				break;
		}
	}
}

int Human::get_input()
{
	int choice = 0;
	string tmp;
	cout << "1 - Play tile" << endl;
	cout << "2 - Pass" << endl;
	cout << "3 - Help" << endl;
	cout << "Choice: ";
	while(getline(cin, tmp))
	{
		if(stringstream(tmp) >> choice && (choice > 0 && choice <= 5))
			break;
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
void Human::help(Board &board, Boneyard &boneyard, Turn &lastTurn)
{
	int possiblePlays = 0;
	string currSide, bestSide;
	int currTile, bestTile;
	int bestSum = 0;
	int currSum = 0;
	// check to see if engine is empty, meaning the computer must play it
	Tile tempEng(-1, -1);
	if(board.get_engine() == tempEng)
	{
		for(int i = 0; i < this->hand.size(); i++)
		{
			if(this->hand[i] == lastTurn.tilePlayed)
			{	
				bestTile = i;
				bestSide = "E";
				possiblePlays++;
			}
		}
	}
	else
	{		
		// used to store last tile in hand
		for(currTile = 0; currTile < this->hand.size(); currTile++)
		{
			currSum = this->hand[currTile].get_leftPips() + 
								this->hand[currTile].get_rightPips();
			if(currSum > bestSum)
			{
				currSide = "L";
				// play single on left first, if not, try right
				if(!(this->hand[currTile].is_double()) && lastTurn.wasPassed)
				{
					currSide = "L";
					if(legal_play(make_pair(currTile, currSide), board))
					{
						bestSum = currSum;
						bestTile = currTile;
						bestSide = currSide;
						possiblePlays++;
					}
					currSide = "R";
					if(legal_play(make_pair(currTile, currSide), board))
					{
						bestSum = currSum;
						bestTile = currTile;
						bestSide = currSide;
						possiblePlays++;
					}
				}
				// play double on left first, then right
				else if(this->hand[currTile].is_double())
				{
					currSide = "L";
					if(legal_play(make_pair(currTile, currSide), board))
					{
						bestSum = currSum;
						bestTile = currTile;
						bestSide = currSide;
						possiblePlays++;
					}
					currSide = "R";
					if(legal_play(make_pair(currTile, currSide), board))
					{
						bestSum = currSum;
						bestTile = currTile;
						bestSide = currSide;
						possiblePlays++;
					}
				}
				// play single on right left
				else
				{
					currSide = "L";
					if(legal_play(make_pair(currTile, currSide), board))
					{
						bestSum = currSum;
						bestTile = currTile;
						bestSide = currSide;
						possiblePlays++;
					}
				}
			}
		}
	}

	string playStr = this->name + "'s 'best' play: ";
	if(possiblePlays < 1)
		cout << playStr << "pass" << endl;
	else
	{
		cout << playStr << this->hand[bestTile] << " (index " << bestTile + 1;
		cout << ") " << bestSide << endl;
	}
}

/*
	pair<int, string> Human::play_tile()
		This function is called by the Turn Human::play() function, and is used to 
		prompt the user two inputs: an integer as the index for the tile in their
		hand they wish to play and a string representing the side they wish to play
		the tile, "L" or "R". "Q" can also be inputted to return to the calling 
		play() function, bringing the user back to the initial choice menu.
*/
pair<int, string> Human::play_tile(Board &board, Turn &lastTurn)
{
	Tile tempEng(-1, -1);
	if(board.get_engine() == tempEng)
	{
		cout << "NOTE: You hold the current round engine. You must play ";
		cout << lastTurn.tilePlayed << " to continue your turn." << endl;
		pair<int, string> thePlay;
		thePlay = play_engine(lastTurn.tilePlayed);
		return thePlay;
	}

	// get tile input as an index
	int tileIdx;
	string tmp;
	cout << "Please enter the index of the tile you wish to play: ";
	while(getline(cin, tmp))
	{
		stringstream ss(tmp);
		ss >> tileIdx;
		if(!ss || (tileIdx < 1 || tileIdx > this->hand.size()))
		{
			cout << "Invalid index. Try again with an integer between 1-";
			cout << this->hand.size() << "." << endl;
			cout << endl;
			cout << "Please enter the index of the tile you wish to play: ";
		}
		else
		{
			break;
		}
	}

	// decrement to change indexing start from 1 to 0
	tileIdx -= 1; 

	// build a regex for side base on the last turn
	string side;
	string sideRegex = "[LlQq";
	if(lastTurn.wasPassed || this->hand[tileIdx].is_double())
		sideRegex += "Rr";
	sideRegex += "]";
	regex rgx(sideRegex);

	// get side input
	cout << "Please enter the side you wish to play ";
	cout << this->hand[tileIdx] << ": ";
	while(getline(cin, tmp))
	{
		stringstream ss(tmp);
		ss >> side;
		if(side == "Q")
			break;
		if(!regex_match(side, rgx))
		{
			if(side == "R" || side == "r")
			{
				cout << "You cannot play on the R side. The last turn was not passed ";
				cout << "or you are not playing a double tile." << endl << endl;
			}
			else
			{
				cout << "Invalid side. Type 'L' for left, 'R' for right." << endl;
				cout << endl;
			}
		}
		else
		{
			break;
		}
		
		cout << "To cancel current play and return to the choice menu, type 'Q'.";
		cout << endl;
		cout << "Please enter the side you wish to play ";
		cout << this->hand[tileIdx] << ": ";
	}

	// for converting string to uppercase with ::toupper()
	locale loc;	
	for(string::size_type i = 0; i < side.length(); i++)
		side[i] = toupper(side[i], loc);

	// thePlay holds the index of the tile that was played and the side played
	pair<int, string> thePlay(tileIdx, side);
	// user wants to go back to initial menu, canceling the current play
	if(side == "Q")
		thePlay.first = -1;

	return thePlay;
}

pair<int, string> Human::play_engine(Tile &eng)
{
	int tileIdx;
	string tmp;
	cout << "Please enter the index of the engine " << eng << ": ";
	while(getline(cin, tmp))
	{
		stringstream ss(tmp);
		ss >> tileIdx;
		if(!ss || !(this->hand[tileIdx - 1] == eng))
		{
			cout << "Invalid index. Try again with an integer between 1-";
			cout << this->hand.size() << "." << endl;
			cout << endl;
			cout << "Please enter the index of the engine " << eng << ": ";
		}
		else
		{
			// bring tileIdx back to 0 indexing
			tileIdx -= 1;
			pair<int, string> thePlay;
			thePlay.first = tileIdx;
			thePlay.second = "E";
			return thePlay;
		}
	}	
}

bool Human::pass(Board &board, Turn &lastTurn)
{
	int possiblePlays = 0;
	// check to see if engine is empty, meaning the computer must play it
	Tile tempEng(-1, -1);
	if(board.get_engine() == tempEng)
	{
		for(int i = 0; i < this->hand.size(); i++)
		{
			if(this->hand[i] == lastTurn.tilePlayed)
			{	
				string playStr = this->name + "'s 'best' play: ";
				cout << playStr << this->hand[i] << " (index " << i + 1;
				cout << ") as the engine." << endl;
				possiblePlays++;
			}
		}
	}
	
	string currSide;
	int currTile;
	for(currTile = 0; currTile < this->hand.size(); currTile++)
	{
		currSide = "L";
		// play single on left first, if not, try right
		if(!(this->hand[currTile].is_double()) && lastTurn.wasPassed)
		{
			currSide = "L";
			if(legal_play(make_pair(currTile, currSide), board))
				possiblePlays++;
			
			currSide = "R";
			if(legal_play(make_pair(currTile, currSide), board))
				possiblePlays++;
		}
		// play double on left first, then right
		else if(this->hand[currTile].is_double())
		{
			currSide = "L";
			if(legal_play(make_pair(currTile, currSide), board))
				possiblePlays++;
			
			currSide = "R";
			if(legal_play(make_pair(currTile, currSide), board))
				possiblePlays++;
		}
		// play single on right left
		else
		{
			currSide = "L";
			if(legal_play(make_pair(currTile, currSide), board))
				possiblePlays++;
		}
	}

	return possiblePlays < 1;
}