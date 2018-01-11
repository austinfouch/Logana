/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "tournament.h"

void Tournament::run()
{
	// Allow user to choose serialization option
	string choice, tempChoice;
	cout << "Load a game? (Y/N): ";
	while(getline(cin, tempChoice))
	{
		stringstream ss(tempChoice);
		ss >> choice;
		if(choice == "Y")
		{
			string tempFile, inFile;
			cout << "Enter a file name to load from: ";
			while(getline(cin, tempFile))
			{
				stringstream ss(tempFile);
				ss >> inFile;
				if(!inFile.empty())
				{
					if(tempFile == "Q")
						break;
					stringstream ss(tempFile);
					ss >> inFile;
					if(!ifstream(inFile))
					{
						cout << "Invalid file name." << endl;
						cout << "Type 'Q' to continue a fresh game." << endl;
						cout << "Enter a file name to load from: ";
					}
					else
					{
						// input was valid, run a game from file
						run_serialized(inFile);
					}
				}
				else
				{
					cout << "File name cannot be empty." << endl;
					cout << "Type 'Q' to continue a fresh game." << endl;
					cout << "Enter a file name to load from: ";
				}
			}
			break;
		}
		else if(choice == "N")
			break;
		else
			cout << "Invalid input. Please input 'Y' to serialize or 'N' continue: ";
	}	
	cout << endl;

	// Set up a non-serialized tournament
	// get score via user input
	string tmp;
	int usr_score;
	cout << "Enter the tournament score: ";
	while(getline(cin, tmp))
	{
		if(stringstream(tmp) >> usr_score)
			break;
		cout << "Invalid input. Try again with an integer." << endl;
		cout << "Enter the tournament score: ";
	}
	cout << endl;

	// set the tournament's players, score, round number
	this->players.push_back(make_unique<Computer>(0 , "Computer"));
	this->players.push_back(make_unique<Human>(0, "Human"));	
	this->score = usr_score;
	this->round = 0;
	Round round;
	// run until a player's score is greater than the tourney score
	do
	{
		this->round = (this->round % 7) + 1;
		round.run(this->players, this->round, this->score, false);
	} 
	while(!(check_score(*this->players[0]) || check_score(*this->players[1])));

	// display winner
	cout << get_winner().get_name() << " has won the tournament with a score of ";
	cout << get_winner().get_score() << "!" << endl;
	exit(0);
}

void Tournament::run_serialized(string &filename)
{
	Board board;
	Boneyard boneyard;
	bool wasPassed;
	int currPlayer;
	// set up players
	this->players.push_back(make_unique<Computer>(0 , "Computer"));
	this->players.push_back(make_unique<Human>(0 , "Human"));
	// read serialization file into variables 
	ifstream inFile(filename);
	string line, tileStr;
	// line by line parsing
	while(getline(inFile, line))
	{
		// parse by word
		istringstream ss(line);
		string word;
		while(ss >> word)
		{
			if(word == "Tournament")
			{
				ss >> word;
				ss >> this->score;
				cout << "Tournament Score: " << this->score << endl;
				ss.clear();
			}

			if(word == "No.:")
			{
				ss >> this->round;
				cout << "Round No.: " << this->round << endl << endl;
				ss.clear();
			}

			if(word == "Computer:")
			{
				cout << word << endl;
				getline(inFile, line);
				istringstream ss1(line);
				ss1 >> word;
				ss1.clear();
				if(word == "Hand:")
				{
					cout << "   Hand: ";
					while(ss1 >> tileStr)
					{
						cout << tileStr << " ";
						// converts char to int
						int leftPips = tileStr[0] - 48;
						int rightPips = tileStr[2] - 48;
						Tile temp(leftPips, rightPips);
						// push temp to hand
						this->players[0]->push_back(temp);
					}
					cout << endl;
					ss1.clear();
				}

				getline(inFile, line);
				istringstream ss2(line);
				ss2 >> word;
				if(word == "Score:")
				{
					cout << "   Score: ";
					ss2 >> word;
					cout << word << endl;
					int score = stoi(word);
					this->players[0]->set_score(score);
				}
			}

			if(word == "Human:")
			{
				cout << endl;
				cout << word << endl;
				getline(inFile, line);
				istringstream ss1(line);
				ss1 >> word;
				ss1.clear();
				if(word == "Hand:")
				{
					cout << "   Hand: ";
					while(ss1 >> tileStr)
					{
						cout << tileStr << " ";
						// converts char to int
						int leftPips = tileStr[0] - 48;
						int rightPips = tileStr[2] - 48;
						Tile temp(leftPips, rightPips);
						// push temp to hand
						this->players[1]->push_back(temp);
					}
					cout << endl;
					ss1.clear();
				}

				getline(inFile, line);
				istringstream ss2(line);
				ss2 >> word;
				if(word == "Score:")
				{
					cout << "   Score: ";
					ss2 >> word;
					cout << word << endl;
					int score = stoi(word);
					this->players[1]->set_score(score);
				}
			}

			if(word == "Layout:")
			{
				// used to switch from leftside to rightside
				Tile tempEng(MAX_ROUNDS - round, MAX_ROUNDS - round);
				cout << endl << word << endl;
				getline(inFile, line);
				istringstream ss1(line);
				ss1 >> word;
				ss1.clear();
				if(word == "L")
					cout << "  L ";
				ss1 >> word;
				tileStr = word;
				if(word == "R")
				{
					cout << "R" << endl;
				}
				else
				{
					while(true)
					{
						cout << tileStr << " ";
						int leftPips = tileStr[0] - 48;
						int rightPips = tileStr[2] - 48;
						Tile temp(leftPips, rightPips);
						if(temp == tempEng)
						{
							board.set_engine(tempEng);
							break;
						}
						board.push_left(temp);
						ss1 >> tileStr;
					}
					ss1.clear();
					while(ss1 >> tileStr)
					{
						if(tileStr == "R")
						{
							cout << "R" << endl;
							break;
						}

						cout << tileStr << " ";
						int leftPips = tileStr[0] - 48;
						int rightPips = tileStr[2] - 48;
						Tile temp(leftPips, rightPips);
						if(temp == tempEng)
						{
							board.set_engine(tempEng);
							break;
						}
						board.push_right(temp);
					}
				}
			}

			if(word == "Boneyard:")
			{
				cout << endl;
				cout << word << endl;
				getline(inFile, line);
				istringstream ss1(line);
				ss1.clear();
				while(ss1 >> tileStr)
				{
					cout << tileStr << " ";
					int leftPips = tileStr[0] - 48;
					int rightPips = tileStr[2] - 48;
					Tile temp(leftPips, rightPips);
					boneyard.push_back(temp);
				}
				cout << endl << endl;
				ss1.clear();
			}

			if(word == "Passed:")
			{
				cout << "Previous Player Passed: ";
				ss >> word;
				if(word == "Yes")
				{
					cout << word << endl;
					wasPassed = true;
				}
				if(word == "No")
				{
					cout << word << endl;
					wasPassed = false;
				}
				else
					wasPassed = false;
				ss.clear();
				cout << endl;
			}

			if(word == "Player:")
			{
				cout << "Next Player: ";
				ss >> word;
				if(word == "Computer")
				{
					cout << word << endl;
					currPlayer = 0;
				}
				if(word == "Human")
				{
					cout << word << endl;
					currPlayer = 1;
				}
				else
					currPlayer = 0;
				ss.clear();
				cout << endl;
			}
		}
	}
	
	// create round and set it with parsed data
	Round round;
	round.set_board(board);
	round.set_boneyard(boneyard);
	round.set_wasPassed(wasPassed);
	round.set_currPlayer(currPlayer);
	bool isSerialized = true;
	// run serialized game
	do
	{
		cout << this->players[0]->get_name() << " : ";
		cout << this->players[0]->get_score() << endl;
		cout << this->players[1]->get_name() << " : ";
		cout << this->players[1]->get_score() << endl;
		round.run(this->players, this->round, this->score, isSerialized);
		isSerialized = false;
		this->round = (this->round % 7) + 1;
	} 
	while(!(check_score(*this->players[0]) || check_score(*this->players[1])));

	cout << get_winner().get_name() << " has won the tournament with a score of ";
	cout << get_winner().get_score() << "!" << endl;
	exit(0);
}

Player Tournament::get_winner()
{
	for(auto &player : this->players)
		if(check_score(*player))
			return *player;
}

bool Tournament::check_score(Player &player)
{
	return player.get_score() >= this->score;
}

