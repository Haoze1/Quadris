#include"gameplay.h"
#include"block.h"
#include<iostream>
#include<cstdlib>
#include"textdisplay.h"
#include<sstream>
#include<string>

string int_to_string(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}
void Gameplay::next_block(char c) {//if cannot be put
	if (c == 'I') {
		for (int i = 0; i < 4; i++)
		{
			if(this->board->get_i_j(14,i)->get_char()!=' ') this->over=true;
		}
	}
	else if (c == 'J') {
		if (this->board->get_i_j(14, 0)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 0)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 1)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 2)->get_char() != ' ') this->over = true;
	}
	else if (c == 'L') {
		if (this->board->get_i_j(14, 2)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 2)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 1)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 0)->get_char() != ' ') this->over = true;
	}
	else if (c == 'O') {
		if (this->board->get_i_j(14, 0)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(14, 1)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 0)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 1)->get_char() != ' ') this->over = true;
	}
	else if (c == 'S') {
		if (this->board->get_i_j(14, 1)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(14, 2)->get_char() != ' ') this->over = true;
		if(this->board->get_i_j(13, 0)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 1)->get_char() != ' ') this->over = true;
	}
	else if (c == 'Z') {
		if (this->board->get_i_j(14, 0)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(14, 1)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 1)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 2)->get_char() != ' ') this->over = true;
	}
	else if (c == 'T') {
		if (this->board->get_i_j(14, 0)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(14, 1)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(14, 2)->get_char() != ' ') this->over = true;
		if (this->board->get_i_j(13, 1)->get_char() != ' ') this->over = true;
	}
	if (over == true) {
		std::string s;
		std::cout << "Game Over!!!!!!!!!" << std::endl<< "Restart ? (yes / no)" << std::endl;
		while (true) {
			std::cin >> s;
			if (s == "yes") {
				over = false; this->restart(); return;
			}
			else if (s == "no") { exit(0); }
		}

	}
	std::shared_ptr<Block> block ( new Block(c, *(this->board),this->level));
	this->cur_block = block;
	this->next_char(this->level);
}

void Gameplay::next_char(int level) {
	if ((level>=3) && (!random)) {
		char c=' ';
		while(c==' '&&sequence>>c)
		char_next = c;
	}
	else if (level == 0) {
		std::string s;
		if (this->sequence >> s) this->char_next = s[0];
		//this->char_next = 'J';
	}
	else if (level == 1) {
		int random_number = (rand() % 12);
		std::cout << random_number << std::endl;
		if (random_number == 0) this->char_next = 'S';
		else if (random_number == 1) this->char_next = 'Z';
		else if (random_number == 2 || random_number == 3) this->char_next = 'I';
		else if (random_number == 4 || random_number == 5) this->char_next = 'J';
		else if (random_number == 6 || random_number == 7) this->char_next = 'L';
		else if (random_number == 8 || random_number == 9) this->char_next = 'O';
		else this->char_next = 'T';

	}
	else if (level == 2) {
		int random_number = (rand() % 7);
		std::cout << random_number << std::endl;
		if (random_number == 0) this->char_next = 'S';
		else if (random_number == 1) this->char_next = 'Z';
		else if (random_number == 2) this->char_next = 'I';
		else if (random_number == 3) this->char_next = 'J';
		else if (random_number == 4) this->char_next = 'L';
		else if (random_number == 5) this->char_next = 'O';
		else this->char_next = 'T';
	}
	else {
		int random_number = (rand() % 9);
		std::cout << random_number << std::endl;
		if (random_number == 0 || random_number == 1) this->char_next = 'S';
		else if (random_number == 2 || random_number == 3) this->char_next = 'Z';
		else if (random_number == 4) this->char_next = 'I';
		else if (random_number == 5) this->char_next = 'J';
		else if (random_number == 6) this->char_next = 'L';
		else if (random_number == 7) this->char_next = 'O';
		else this->char_next = 'T';
	}
}

void Gameplay::graphic() {
	this->graph->fillRectangle(0, 22 * 20, 10000, 10000, 1);
	this->graph->drarstring(0, 23 * 20, "Score:     " + int_to_string(this->cur_score), 7);
	this->graph->drarstring(0, 24 * 20, "Level:     " + int_to_string(this->level), 6);
	this->graph->drarstring(0, 25 * 20, "Hi Score:  " + int_to_string(this->high_score), 9);
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 11; j++) {
			this->graph->notify(i,j,this->board->get_td()->get_i_j(i,j));
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->graph->notify(-4+i, j, '?');
		}
	}
	this->graph->drarstring(0, 19 * 20, "Next", 6);
	if (this->char_next == 'I') { for (int i = 0; i < 4; i++) { this->graph->notify(-3, i, 'I'); } }
	else if (this->char_next == 'J') {
		this->graph->notify(-2, 0, 'J');
		this->graph->notify(-3, 0, 'J');
		this->graph->notify(-3, 1, 'J');
		this->graph->notify(-3, 2, 'J');
	}
	else if (this->char_next == 'L') {
		this->graph->notify(-2, 2, 'J');
		this->graph->notify(-3, 0, 'J');
		this->graph->notify(-3, 1, 'J');
		this->graph->notify(-3, 2, 'J');
	}
	else if (this->char_next == 'O') {
		this->graph->notify(-2, 1, 'O');
		this->graph->notify(-2, 0, 'O');
		this->graph->notify(-3, 1, 'O');
		this->graph->notify(-3, 0, 'O');
	}
	else if (this->char_next == 'S') {
		this->graph->notify(-2, 2, 'S');
		this->graph->notify(-2, 1, 'S');
		this->graph->notify(-3, 0, 'S');
		this->graph->notify(-3, 1, 'S');
	}
	else if (this->char_next == 'L') {
		this->graph->notify(-2, 0, 'Z');
		this->graph->notify(-2, 1, 'Z');
		this->graph->notify(-3, 1, 'Z');
		this->graph->notify(-3, 2, 'Z');
	}
	else if (this->char_next == 'T') {
		this->graph->notify(-3, 1, 'T');
		this->graph->notify(-2, 0, 'T');
		this->graph->notify(-2, 1, 'T');
		this->graph->notify(-2, 2, 'T');
	}
	else if (this->char_next == 'Z') {
		this->graph->notify(-3, 1, 'Z');
		this->graph->notify(-2, 0, 'Z');
		this->graph->notify(-2, 1, 'Z');
		this->graph->notify(-3, 0, 'Z');
	}
}

std::ostream &operator<<(std::ostream &out, Gameplay &gameplay) {
	out << "Level:        " << gameplay.level << std::endl;
	out << "Score:        " << gameplay.cur_score << std::endl;
	if (gameplay.cur_score > gameplay.high_score) gameplay.high_score = gameplay.cur_score;
	out << "Hi Score:     " << gameplay.high_score << std::endl;
	out << "-----------" << std::endl;
	out << *(gameplay.board);
	out << "Next:" << std::endl;
	if (gameplay.char_next == 'I') { out << "IIII" << std::endl; }
	else if (gameplay.char_next == 'L') { out << "  L" << std::endl << "LLL" << std::endl; }
	else if (gameplay.char_next == 'J') { out << "J" << std::endl << "JJJ" << std::endl; }
	else if (gameplay.char_next == 'O') { out << "OO" << std::endl << "OO" << std::endl; }
	else if (gameplay.char_next == 'S') { out << " SS" << std::endl << "SS" << std::endl; }
	else if (gameplay.char_next == 'Z') { out << "ZZ" << std::endl << " ZZ" << std::endl; }
	else if (gameplay.char_next == 'T') { out << "TTT" << std::endl << " T" << std::endl; }

}

void Gameplay::drop() {
	//std::cout << "here1" << std::endl;
	this->cur_block->drop(*this->board);
 //std::cout<<"here"<<std::endl;
	for (int j = 0; j < this->board->getcol(); j++) {
		if (this->board->get_i_j(this->board->getrow()-4, j)->get_char() != ' ') this->over = true;
	}
	this->blocks.push_back(this->cur_block);
	this->clear_lines();
	this->next_block(this->char_next);
	if (this->level >= 4) this->force();
	//std::cout << "here2" << std::endl;
}

void Gameplay::clock() {
	this->cur_block->rotate_clock(*this->board);
	if (this->level >= 3) { this->cur_block->move_down(*this->board); }
	if (this->level >= 5) { this->cur_block->rotate_clock(*this->board); }
}

void Gameplay::counter() {
	this->cur_block->rotate_counter(*this->board);
	if (this->level >= 3) { this->cur_block->move_down(*this->board); }
	if (this->level >= 5) { this->cur_block->rotate_clock(*this->board); }
}

void Gameplay::left(){
	this->cur_block->move_left(*this->board);
	if (this->level >= 3) { this->cur_block->move_down(*this->board); }
	if (this->level >= 5) { this->cur_block->rotate_clock(*this->board); }
}

void Gameplay::right() {
	this->cur_block->move_right(*this->board);
	if (this->level >= 3) { this->cur_block->move_down(*this->board); }
	if (this->level >= 5) { this->cur_block->rotate_clock(*this->board); }
}

void Gameplay::down(){
	this->cur_block->move_down(*this->board);
	if (this->level >= 3) { this->cur_block->move_down(*this->board); }
	if (this->level >= 5) { this->cur_block->rotate_clock(*this->board); }
}

void Gameplay::setboard(std::shared_ptr<Board> board) { this->board = board; }
char Gameplay::getchar_next() { return this->char_next; }
void Gameplay::readsequence(std::string &s) {
	//std::cout << s << std::endl;
	 this->sequence.open(s.c_str());
}

void Gameplay::setseed() {
	srand(this->seed);
}

void Gameplay::levelup() {
	this->level++;
}

void Gameplay::leveldown() {
	this->level--;
}

void Gameplay::restart() {
	this->blocks.resize(0);
	this->board->init();
	this->level = 0;
	this->next_char(this->level);
	this->next_block(this->char_next);
	this->cur_score = 0;
}

void Gameplay::mutate_blocks_size(std::shared_ptr<Cell> cell) {
	for (int i = 0; i < this->blocks.size(); i++) {
		for (int j = 0; j < this->blocks[i]->getsize(); j++) {
			//std::cout<<i << " block_size " << this->blocks[i]->getsize() << std::endl;
			if (this->blocks[i]->get_cells()[j] == cell) {
				for (int k = j; k < this->blocks[i]->getsize()-1; k++) {
					this->blocks[i]->get_cells()[k] = this->blocks[i]->get_cells()[k + 1];
				}
				this->blocks[i]->size_minus();
			}
		}
		if (this->blocks[i]->getsize() == 0) {
			//std::cout << i<<"size 0 " << std::endl;
			int level = this->blocks[i]->get_level();
			this->blocks.erase(this->blocks.begin() + i);
			this->cur_score += (level + 1)*(level + 1);
		}
	}
}

void Gameplay::clear_lines() {
	int number_of_lines = 0;
	for (int i = this->board->getrow() - 1; i >= 0; i--) {
		if (this->board->line_is_full(i)) {
			//std::cout<<"full " <<i<< std::endl;
			for (int j = 0; j < this->board->getcol(); j++)
			{
				this->mutate_blocks_size(this->board->get_i_j(i, j));
			}
			//std::cout << "mumtate " << i << std::endl;
			this->board->delete_line(i);
			//std::cout << "delete " << i << std::endl;
			number_of_lines++;
		}
	}
	if (number_of_lines != 0) {
		this->cur_score += (number_of_lines + this->level)*(number_of_lines + this->level);
	}
}

void Gameplay::set_graphic(std::shared_ptr<GraphicsDisplay> graph) {
	this->graph = graph;
}

void Gameplay::set_random(bool b) {
	random = b;
}

void Gameplay::force() {
	int i = this->board->getrow() - 1;
	while (i >= 0&& this->board->get_i_j(i, 5)->get_char() == ' ') {
		i--;
		//std::cout << "row" << i << std::endl;
	}
	i++;
	//std::cout << "row" << i << std::endl;
	this->board->get_i_j(i, 5)->set_cell_char('*');
}

void Gameplay::readseed(int seed) {
	this->seed = seed;
}

void Gameplay::setlevel(int thelevel) {
	this->level = thelevel;
}

int Gameplay::getlevel() {
	return this->level;
}

struct point {
	int r;
	int c;
};
struct fourpoints {
	point pts[4];
};

fourpoints shape(char c) {
	fourpoints temp;
	if (c == 'I') {
		for (int i = 0; i < 4; i++) {
			temp.pts[i].r = 0;
			temp.pts[i].c = i;
		}
	}
	else if (c == 'J') {
		temp.pts[0].r = 0; temp.pts[0].c = 0;
		temp.pts[1].r = 0; temp.pts[1].c = 1;
		temp.pts[2].r = 0; temp.pts[2].c = 2;
		temp.pts[3].r = 1; temp.pts[3].c = 0;
	}
	else if (c == 'L') {
		temp.pts[0].r = 0; temp.pts[0].c = 0;
		temp.pts[1].r = 0; temp.pts[1].c = 1;
		temp.pts[2].r = 0; temp.pts[2].c = 2;
		temp.pts[3].r = 1; temp.pts[3].c = 2;
	}
	else if (c == 'S') {
		temp.pts[0].r = 0; temp.pts[0].c = 0;
		temp.pts[1].r = 0; temp.pts[1].c = 1;
		temp.pts[2].r = 1; temp.pts[2].c = 1;
		temp.pts[3].r = 1; temp.pts[3].c = 2;
	}
	else if (c == 'Z') {
		temp.pts[0].r = 0; temp.pts[0].c = 1;
		temp.pts[1].r = 0; temp.pts[1].c = 2;
		temp.pts[2].r = 1; temp.pts[2].c = 0;
		temp.pts[3].r = 1; temp.pts[3].c = 2;
	}
	else if (c == 'O') {
		temp.pts[0].r = 0; temp.pts[0].c = 0;
		temp.pts[1].r = 0; temp.pts[1].c = 1;
		temp.pts[2].r = 1; temp.pts[2].c = 0;
		temp.pts[3].r = 1; temp.pts[3].c = 1;
	}
	else if (c == 'T')
	{
		temp.pts[0].r = 0; temp.pts[0].c = 1;
		temp.pts[1].r = 1; temp.pts[1].c = 0;
		temp.pts[2].r = 1; temp.pts[2].c = 1;
		temp.pts[3].r = 1; temp.pts[3].c = 2;
	}
	return temp;
}

bool canbeput(fourpoints cur, int i, int j, std::shared_ptr<TextDisplay> td) {
	bool flag = true;
	bool solid_below = false;
	int row = td->get_row();
	int col = td->get_col();
	//std::cout << "canbeput " <<i<<' '<<j<< std::endl;
	bool flags[4] = { false,false,false,false };
	for (int k = 0; k < 4; k++) {
		int newi = i + cur.pts[k].r;
		int newj = j + cur.pts[k].c;
		if (td->get_i_j(newi, newj) == ' ')
		{
			if ((newi - 1 < 0) || ((td->get_i_j(newi - 1, newj)) != ' ')) solid_below = true;
			//std::cout << "canbeput1 "<<k<<' ' << i << ' ' << j << std::endl;
			flags[k] = true;
			for (int l = newi + 1; l < row-3; l++) { if (td->get_i_j(l, newj) != ' ') flags[i] = false; }
			//if (flags[k]==true) std::cout << "canbeput2 " << k << ' ' << i << ' ' << j << std::endl;
		}
	}
		for (int k = 0; k < 4; k++)
		{
			if (flags[k] == false) {
				flag = false;
				//std::cout << "fail"<<k << std::endl;
			}
		}
		if (!solid_below) flag = false;
		return flag;
}

void Gameplay::hint() {
	char c = this->cur_block->get_char();
	this->cur_block->clear();
	this->board->get_td()->notify(*this->board);
	fourpoints cur = shape(c);
	//std::cout << cur.pts[0].r<<',' << cur.pts[0].c <<' '<< cur.pts[1].r << ',' << cur.pts[1].c << ' ' << cur.pts[2].r << ',' << cur.pts[2].c << ' ' << cur.pts[3].r << ',' << cur.pts[3].c << std::endl;
	//std::cout << "hint" << std::endl;
	for (int i = 0; i< this->board->getrow()-3; i++) {
		for (int j = 0; j < this->board->getcol(); j++)
		{
			if (canbeput(cur, i, j, this->board->get_td())) {
				//std::cout << i << ' ' << j << "canbeput" << std::endl;
				for (int k = 0; k < 4; k++) {
					this->board->get_td()->set_i_j(i + cur.pts[k].r, j + cur.pts[k].c, '?');
				}
				std::cout << *this->board->get_td();
				this->cur_block->mutate(this->cur_block->get_char());
				return;
			}
		}
	}
	this->cur_block->mutate(this->cur_block->get_char());
}

std::shared_ptr<Block> Gameplay::get_cur_block() {
	return this->cur_block;
}

void Gameplay::remove_cur() {
	this->cur_block.~shared_ptr();
}
