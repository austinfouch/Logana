#ifndef BOARDVIEW_H
#define BOARDVIEW_H
#include "board.h"
#include <vector>
#include <algorithm>

class BoardView {
public:
	// default cstor/dstor
	BoardView() {}
	~BoardView() {}

	// display passed board
	void display_board(Board &board);
};
#endif