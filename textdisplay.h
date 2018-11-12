#ifndef _TEXT_H
#define _TEXT_H
#include <iostream>
#include <vector>
#include"observer.h"
class Cell;
class Board;

class TextDisplay{
	std::vector<std::vector<char>> theDisplay;

	const int col = 11;
	const int row = 18;
public:
	void notify(Board &whoNotified);
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
	char get_i_j(int i, int j); 
	void set_i_j(int i, int j, char c); 
	int get_col();
	int get_row();
};


#endif // !_TEXT_H
