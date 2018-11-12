#include"textdisplay.h"
#include"board.h"

void TextDisplay::notify(Board &whoNotified) {
	//std::cout << "TD notify" << std::endl;
	this->theDisplay.resize(this->row);
	for (int i = 0; i < this->row; i++) {
		this->theDisplay[i].resize(this->col);
	}
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			//std::cout << "TD notify"<<j << std::endl;
			this->theDisplay[i][j] = whoNotified.get_i_j(i, j)->get_char();
		}
	}
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
	//std::cout << "TD's <<" <<std::endl;
	for (int i = td.row-1; i>=0; i--) {
		for (int j = 0; j < td.col; j++) {
			out << td.theDisplay[i][j];
		}
		out << std::endl;
	}
	for (int i = 0; i < td.col; i++) {
		out << "-";
	}
	out << std::endl;
}

char TextDisplay::get_i_j(int i,int j) { return theDisplay[i][j]; }

void TextDisplay::set_i_j(int i, int j, char c) { this->theDisplay[i][j] = c;}

int TextDisplay::get_col() { return this->col; }

int TextDisplay::get_row() { return this->row; }
