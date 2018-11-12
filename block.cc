#include"block.h"
#include"board.h"

Block::Block(char c, Board& board,int level) {
	this->level = level;
	this->c = c;
	if (c == 'I') {
		for (int i = 0; i < 4; i++)
		{
			this->cells[i] = board.get_i_j(14, i);
		}
	}
	else if (c == 'J') {
			this->cells[0] = board.get_i_j(14, 0);
			this->cells[1] = board.get_i_j(13, 0);
			this->cells[2] = board.get_i_j(13, 1);
			this->cells[3] = board.get_i_j(13, 2);
		}
	else if (c == 'L') {
		this->cells[0] = board.get_i_j(14, 2);
		this->cells[1] = board.get_i_j(13, 2);
		this->cells[2] = board.get_i_j(13, 1);
		this->cells[3] = board.get_i_j(13, 0);
	}
	else if (c == 'O') {
		this->cells[0] = board.get_i_j(14, 0);
		this->cells[1] = board.get_i_j(14, 1);
		this->cells[2] = board.get_i_j(13, 0);
		this->cells[3] = board.get_i_j(13, 1);
	}
	else if (c == 'S') {
		this->cells[0] = board.get_i_j(14, 1);
		this->cells[1] = board.get_i_j(14, 2);
		this->cells[2] = board.get_i_j(13, 0);
		this->cells[3] = board.get_i_j(13, 1);
	}
	else if (c == 'Z') {
		this->cells[0] = board.get_i_j(14, 0);
		this->cells[1] = board.get_i_j(14, 1);
		this->cells[2] = board.get_i_j(13, 1);
		this->cells[3] = board.get_i_j(13, 2);
	}
	else if (c == 'T') {
		this->cells[0] = board.get_i_j(14, 0);
		this->cells[1] = board.get_i_j(14, 1);
		this->cells[2] = board.get_i_j(14, 2);
		this->cells[3] = board.get_i_j(13, 1);
	}
	for (int i = 0; i < 4; i++) {
		this->cells[i]->set_cell_char(c);//render the char
	}
}

void Block::clear() {
	for (int i = 0; i < 4; ++i) {
		//std::cout<<i<<std::endl;
		//if( cells[i].get()!=nullptr
		cells[i]->set_cell_char(' ');
	}
}

void Block::mutate(char c) {
	this->c = c;
	for (int i = 0; i < 4; ++i) {
		cells[i]->set_cell_char(c);
	}
}

int max_difference(int a, int b, int c, int d, int& base) {
	int max = a;
	int min = a;
	if (b > max) {
		max = b;
	}
	else if (b < min) {
		min = b;
	}
	if (c > max) {
		max = c;
	}
	else if (c < min) {
		min = c;
	}
	if (d > max) {
		max = d;
	}
	else if (d < min) {
		min = d;
	}
	base = min;
	return max - min;
}

void Block::rotate_clock(Board& board) {
	if (c != 'O') {
		char old = c;
		this->clear();
		int newpoints[4][2];
		int base_row;
		int base_col;
		int row_type = max_difference(cells[0]->get_row(), cells[1]->get_row(), cells[2]->get_row(), cells[3]->get_row(), base_row);
		int col_type = max_difference(cells[0]->get_col(), cells[1]->get_col(), cells[2]->get_col(), cells[3]->get_col(), base_col);
		for (int i = 0; i < 4; ++i) {
			if (row_type == 0 && col_type == 3) {
				newpoints[i][0] = 3 - cells[i]->get_col() + base_row + base_col;
				newpoints[i][1] = base_col;
			}
			else if (row_type == 3 && col_type == 0) {
				newpoints[i][0] = base_row;
				newpoints[i][1] = cells[i]->get_row() - base_row + base_col;
			}
			else if (row_type == 1 && col_type == 2) {
				newpoints[i][0] = 2 - cells[i]->get_col() + base_row + base_col;
				newpoints[i][1] = cells[i]->get_row() - base_row + base_col;
			}
			else {
				newpoints[i][0] = 1 - cells[i]->get_col() + base_row + base_col;
				newpoints[i][1] = cells[i]->get_row() - base_row + base_col;
			}
		}
		bool has_effect = true;
		for (int i = 0; i < 4; ++i) {
			if (newpoints[i][0] < 0 || newpoints[i][0] > 17 || newpoints[i][1] < 0 || newpoints[i][1] > 10 ||
				board.get_i_j(newpoints[i][0], newpoints[i][1])->get_char() != ' ') {
				has_effect = false;
				this->mutate(old);
				break;
			}
		}
		if (has_effect) {
			for (int i = 0; i < 4; ++i) {
				cells[i] = board.get_i_j(newpoints[i][0], newpoints[i][1]);
			}
			this->mutate(old);
		}
	}
}

void Block::rotate_counter(Board& board) {
	if (c != 'O') {
		char old = c;
		this->clear();
		int newpoints[4][2];
		int base_row;
		int base_col;
		int row_type = max_difference(cells[0]->get_row(), cells[1]->get_row(), cells[2]->get_row(), cells[3]->get_row(), base_row);
		int col_type = max_difference(cells[0]->get_col(), cells[1]->get_col(), cells[2]->get_col(), cells[3]->get_col(), base_col);
		for (int i = 0; i < 4; ++i) {
			if (row_type == 0 && col_type == 3) {
				newpoints[i][0] = cells[i]->get_col() + base_row - base_col;
				newpoints[i][1] = base_col;

			}
			else if (row_type == 3 && col_type == 0) {
				newpoints[i][0] = base_row;
				newpoints[i][1] = 3 - cells[i]->get_row() + base_row + base_col;
			}
			else if (row_type == 1 && col_type == 2) {
				newpoints[i][0] = cells[i]->get_col() + base_row - base_col;
				newpoints[i][1] = 1 - cells[i]->get_row() + base_row + base_col;
			}
			else {
				newpoints[i][0] = cells[i]->get_col() + base_row - base_col;
				newpoints[i][1] = 2 - cells[i]->get_row() + base_row + base_col;
			}
		}
			bool has_effect = true;
			for (int i = 0; i < 4; ++i) {
				if (newpoints[i][0] < 0 || newpoints[i][0] > 17 || newpoints[i][1] < 0 || newpoints[i][1] > 10 ||
					board.get_i_j(newpoints[i][0], newpoints[i][1])->get_char() != ' ') {
					this->mutate(old);
					has_effect = false;
					break;
				}
			}
			if (has_effect) {
				for (int i = 0; i < 4; ++i) {
					cells[i] = board.get_i_j(newpoints[i][0], newpoints[i][1]);
				}
				this->mutate(old);
			}
		}
}


void Block::move_left(Board& board) {
	char old = c;
	this->clear();
	bool has_effect = true;
	for (int i = 0; i < 4; ++i) {
		if (cells[i]->get_col() == 0 || board.get_i_j(cells[i]->get_row(), cells[i]->get_col() - 1)->get_char() != ' ') {
			this->mutate(old);
			has_effect = false;
			break;
		}
	}
	if (has_effect) {

		for (int i = 0; i < 4; ++i) {
			cells[i] = board.get_i_j(cells[i]->get_row(), cells[i]->get_col() - 1);
		}
		this->mutate(old);
	}
}

void Block::move_right(Board& board) {
	//std::cout << "right" << std::endl;
	char old = c;
	this->clear();
	bool has_effect = true;
	for (int i = 0; i < 4; ++i) {
		if (cells[i]->get_col() == 10 || board.get_i_j(cells[i]->get_row(), cells[i]->get_col() + 1)->get_char() != ' ') {
			this->mutate(old);
			has_effect = false;
			break;
		}
	}
	if (has_effect) {
		//std::cout << "haseffect" << std::endl;

		for (int i = 0; i < 4; ++i) {
			cells[i] = board.get_i_j(cells[i]->get_row(), cells[i]->get_col() + 1);
		}
		this->mutate(old);
	}
	else { this->mutate(old); }
}

void Block::move_down(Board& board) {
	char old = c;
	this->clear();
	bool has_effect = true;
	for (int i = 0; i < 4; ++i) {
		if (cells[i]->get_row() == 0 || board.get_i_j(cells[i]->get_row() - 1, cells[i]->get_col())->get_char() != ' ') {
			this->mutate(old);
			has_effect = false;
			break;
		}
	}
	if (has_effect) {

		for (int i = 0; i < 4; ++i) {
			cells[i] = board.get_i_j(cells[i]->get_row() - 1, cells[i]->get_col());
		}
		this->mutate(old);
	}
}

void Block::drop(Board& board) {

	while (true) {
		this->clear();
		//std::cout<<"here"<<std::endl;
		bool need_more = true;
		for (int i = 0; i < 4; ++i) {
			if (cells[i]->get_row() == 0 || board.get_i_j(cells[i]->get_row() - 1, cells[i]->get_col())->get_char() != ' ') {
				need_more = false;
				this->mutate(this->c);
				break;
			}
		}
		if (need_more) {
			this->move_down(board);
		}
		else {
			break;
		}
	}
}

int Block::getsize() { return this->size; }
void Block::size_minus() { this->size--; }

std::shared_ptr<Cell>* Block::get_cells() { return this->cells; }

int Block::get_level() { return this->level; }

char Block::get_char() { return this->c; }
