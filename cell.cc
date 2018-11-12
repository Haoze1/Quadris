#include"cell.h"

char Cell::get_char()
{
	return this->ch;
}

Cell::Cell(int r, int c) {
	this->r = r;
	this->c = c;
	this->ch = ' ';
}

void Cell::set_cell_char(char c) {
	this->ch = c;
}

int Cell::get_row() {
	return r;
}

int Cell::get_col() {
	return c;
}

void Cell::set_row(int row) {
	r = row;
}

