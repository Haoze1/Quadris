#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "cell.h"
#include<memory>

class TextDisplay;
class GraphicDisplay;

using namespace std;


class Board
{
	vector<vector<shared_ptr<Cell>>> theBoard; //  The board.
	shared_ptr<TextDisplay>td = nullptr; // The text display.
	shared_ptr<GraphicDisplay> gd = nullptr; // The graphic display.
	int col = 11;
	int row = 18;
public:
	Board();
	shared_ptr<Cell> get_i_j(int i, int j);
	void init(int row=18, int col=11);
	bool line_is_full(int line);
	void delete_line(int line);
	friend ostream &operator<<(ostream &out, Board &board);
	int getrow();
	int getcol();
	shared_ptr<TextDisplay> get_td() { return this->td; }
};
#endif // !board

