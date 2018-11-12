#ifndef _GAMEPLAY
#define _GAMEPLAY
#include"block.h"
#include"board.h"
#include<cstdlib>
#include"graphicsdisplay.h"
#include<fstream>

class Gameplay
{
	unsigned int seed=1000;
	bool random = true;
	std::ifstream sequence;
	std::shared_ptr<GraphicsDisplay> graph;
	int cur_score=0;
	int high_score=0;
	int level=0;
	char char_next;
	bool over = false;
	std::shared_ptr<Board> board;
	std::vector<std::shared_ptr<Block>> blocks;
	std::shared_ptr<Block> cur_block;
public:
	void next_char(int level);
	void next_block(char c);
	void drop();
	void clock();
	void counter();
	void left();
	void right();
	void down();
	void graphic();
	friend std::ostream &operator<<(std::ostream &out, Gameplay &gameplay);
	void setboard(std::shared_ptr<Board> board);
	char getchar_next();
	void readsequence(std::string &s);
	void setseed();
	void levelup();
	void leveldown();
	void restart();
	void clear_lines();
	void mutate_blocks_size(std::shared_ptr<Cell> cell);
	void set_graphic(std::shared_ptr<GraphicsDisplay> graph);
	void set_random(bool b);
	void force();
	void readseed(int seed);
	void setlevel(int thelevel);
	int getlevel();
	void hint();
	std::shared_ptr<Block> get_cur_block();
	void remove_cur();
};



#endif // _GAMEPLAY



