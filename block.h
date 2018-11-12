#ifndef BLOCK_H
#define BLOCK_H
#include<memory>
class Cell;
class Board;

class Block {
	std::shared_ptr<Cell> cells[4];
	int size = 4;
	int level;
	char c;
public:
	Block(char c, Board& board,int level);
	void clear();
	void mutate(char c);
	void rotate_clock(Board& board);
	void rotate_counter(Board& board);
	void move_left(Board& board);
	void move_right(Board& board);
	void move_down(Board& board);
	void drop(Board& board);
	int getsize();
	void size_minus();
	std::shared_ptr<Cell>* get_cells();
	int get_level();
	char get_char();
};
#endif // !BLOCK_H
