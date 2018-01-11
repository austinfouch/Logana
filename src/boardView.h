/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#ifndef BOARDVIEW_H
#define BOARDVIEW_H
#include "board.h"
#include <vector>
#include <algorithm>

class BoardView {
public:
	// default cstor
	BoardView() {}
	/**************************************************************************
	Function Name: display_board
	Purpose: 
		To display the passed board
	Paramaters: 
		board, a board object that will be displayed
	Return Value: None
	Assistance Received: None.
	**************************************************************************/
	void display_board(Board &board);
};
#endif