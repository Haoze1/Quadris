#ifndef CELL_H
#define CELL_H

class Cell {
	int r, c;
	char ch = ' ';
	bool disappear = false;
public:
	char get_char();
	Cell(int r, int c);
	void set_cell_char(char c);
	int get_row();
	int get_col();
	void set_row(int row);
};
#endif // CELL_H

