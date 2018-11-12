#include"board.h"
#include"textdisplay.h"

shared_ptr<Cell> Board::get_i_j(int i, int j) {
	return this->theBoard[i][j];
}

std::ostream &operator<<(std::ostream &out, Board &board) {
	//std::cout << "Board's<<" << std::endl;
	board.td->notify(board);
	std::cout << *(board.td);
}

void Board::init(int row, int col) {
	this->row = row;
	this->col = col;
	this->theBoard.resize(row);
	for (int i = 0; i < row; i++) { this->theBoard[i].resize(col); }
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::shared_ptr<Cell> cell(new Cell(i, j));
			this->theBoard[i][j] = cell;
		}
	}
}



Board::Board() {
	this->init();
	std::shared_ptr<TextDisplay>td_new(new TextDisplay());
	this->td = td_new;
}

bool Board::line_is_full(int line) {
	for (int i = 0; i < 11; ++i) {
		if (theBoard[line][i]->get_char() == ' ') {
			return false;
		}
	}
	return true;
}

void Board::delete_line(int line) {
	theBoard.erase(theBoard.begin() + line);
	for (int i = line; i < 17; ++i) {
		for (int j = 0; j < 11; ++j) {
			theBoard[i][j]->set_row(theBoard[i][j]->get_row() - 1);
		}
	}
	vector<std::shared_ptr<Cell>> v;
	for (int k = 0; k < 11; ++k) {
		std::shared_ptr<Cell> cell(new Cell(17, k));
		v.push_back(cell);
	}
	theBoard.push_back(v);
}

int Board::getrow() { return this->row;}
int Board::getcol() { return this->col; }
