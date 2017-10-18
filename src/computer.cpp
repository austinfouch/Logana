#include "computer.h"

Turn Computer::play(Board &board, Boneyard &boneyard, Turn &lastTurn)
{
	cout << this->name << "'s turn: " << endl;
	show_hand();
	// check to see if engine is empty, meaning the computer must play it
	Tile tempEng(-1, -1);
	if(board.get_engine() == tempEng)
	{
		for(int i = 0; i < this->hand.size(); i++)
		{
			if(this->hand[i] == lastTurn.tilePlayed)
			{	
				cout << this->name << " played " << this->hand[i] << ", ";
				cout << "the engine." << endl;

				Turn turn;
				turn.tilePlayed = this->hand[i];
				turn.sidePlayed = "E";
				turn.wasPassed = false;

				board.set_engine(this->hand[i]);
				remove_tile(i);

				return turn;
			}
		}
	}
	
	// used to store last tile in hand
	string currSide, bestSide;
	int currTile, bestTile;
	int possiblePlays = 0;
	int bestSum = 0;
	int currSum = 0;
	for(currTile = 0; currTile < this->hand.size(); currTile++)
	{
		currSum = this->hand[currTile].get_leftPips() + 
							this->hand[currTile].get_rightPips();
		if(currSum > bestSum)
		{
			currSide = "R";
			// play single on right first, if not, try left
			if(!(this->hand[currTile].is_double()) && lastTurn.wasPassed)
			{
				currSide = "R";
				if(legal_play(make_pair(currTile, currSide), board))
				{
					bestSum = currSum;
					bestTile = currTile;
					bestSide = currSide;
					possiblePlays++;
				}
				currSide = "L";
				if(legal_play(make_pair(currTile, currSide), board))
				{
					bestSum = currSum;
					bestTile = currTile;
					bestSide = currSide;
					possiblePlays++;
				}
			}
			// play double on right first, then left
			else if(this->hand[currTile].is_double())
			{
				currSide = "R";
				if(legal_play(make_pair(currTile, currSide), board))
				{
					bestSum = currSum;
					bestTile = currTile;
					bestSide = currSide;
					possiblePlays++;
				}
				currSide = "L";
				if(legal_play(make_pair(currTile, currSide), board))
				{
					bestSum = currSum;
					bestTile = currTile;
					bestSide = currSide;
					possiblePlays++;
				}
			}
			// play single on right side
			else
			{
				currSide = "R";
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

	Turn turn;
	if(possiblePlays < 1)
	{
		turn.wasPassed = true;
		turn.tilePlayed = Tile(-1, -1);
		turn.sidePlayed = "None";
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
			thePlay.second = "R";
			if(legal_play(thePlay, board))
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
				cout << "Computer's 'best' play: ";
				cout << turn.tilePlayed << " on " << turn.sidePlayed << endl;
				return turn;
			}
			else
			{
				thePlay.second = "L";
				if(legal_play(thePlay, board) && lastTurn.wasPassed)
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
					cout << "Computer's 'best' play: ";
					cout << turn.tilePlayed << " on " << turn.sidePlayed << endl;
					return turn;
				}
			}
		}	
		else
			cout << "Boneyard is empty!";
		cout << endl;
	}
	else
	{
		turn.wasPassed = false;
		turn.tilePlayed = this->hand[bestTile];
		turn.sidePlayed = bestSide;
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
		
		cout << "Computer's 'best' play: ";
		cout << turn.tilePlayed << " on " << turn.sidePlayed << endl;
		remove_tile(bestTile);
	}

	return turn;
}