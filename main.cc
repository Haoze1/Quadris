#include"gameplay.h"
#include<iostream>
#include"textdisplay.h"
#include<memory>
#include<sstream>
#include<fstream>

int main(int argc, char *argv[])
{
	int theseed;
	int thelevel;
	std::string filename = "sequence.txt";
	bool text = false;
	bool seed = false;
	bool startlevel = false;
	for (int arg = 1; arg < argc; ++arg) {
		std::string option = argv[arg];
		if (option == "-text") {
			text = true;
		}
		else if (option == "-seed") {
			seed = true;
			std::string seed = argv[arg + 1];
			istringstream iss1{ seed };
			iss1 >> theseed;
		}
		else if (option == "-scriptfile") {
			filename = argv[arg + 1];
		}
		else if (option == "-startlevel") {
			startlevel = true;
			std::string Level = argv[arg + 1];
			istringstream iss2{ Level };
			iss2 >> thelevel;
		}
	}

	std::string command;
	Gameplay gameplay;
	if (startlevel) {
		gameplay.setlevel(thelevel);
	}
	gameplay.readsequence(filename);
    std::shared_ptr<Board> board(new Board());
	gameplay.setboard(board);
	if (!text) {
		std::shared_ptr<GraphicsDisplay> graphic(new GraphicsDisplay(18, 11));
		gameplay.set_graphic(graphic);
	}
	if (seed) {
		gameplay.readseed(theseed);
	}
	gameplay.setseed();
	gameplay.next_char(gameplay.getlevel());
	gameplay.next_block(gameplay.getchar_next());
	std::cout << gameplay << std::endl;
	if(!text) gameplay.graphic();
	while (getline(std::cin,command)) {
		bool hint = false;
		std::istringstream iss{ command };
		std::string s;
		int n = 1;
		if (command[0] >= '0' && command[0] <= '9') {
			iss >> n;
		}
		iss >> s;
		for (int i = 0; i < n; ++i) {
			if (s[0] == 'd') {
				if (s[1] == 'o') {
					gameplay.down();
				}
				else {
					gameplay.drop();
				}
			}
			else if (s[0] == 'c') {
				if (s[1] == 'l') {
					gameplay.clock();
				}
				else {
					gameplay.counter();
				}
			}
			else if (s[0] == 'l') {
				if (s[2] == 'f') {
					gameplay.left();
				}
				else if (s[5] == 'u') {
					gameplay.levelup();
				}
				else if(s[5]=='d'){
					gameplay.leveldown();
				}
			}
			else if (s[0] == 'r') {
				if (s[1] == 'a') {
					gameplay.set_random(true);//random
				}
				else if (s[1] == 'e') {
					gameplay.restart();
					gameplay.setseed();
					gameplay.next_char(0);

				}
				else {
					gameplay.right();

				}
			}
			else if (s[0] == 'h') {
				hint = true;
				gameplay.hint();
				if (!text) gameplay.graphic();
			}
			else if (s[0] == 's' || s[0] == 'n') {
				std::string file;
				iss >> file;
				if (s[0] == 's') {
					std::ifstream ifs {file.c_str()};
					std::string command_in_file;
					while (ifs>>command_in_file) {
						std::istringstream iss3{ command_in_file.c_str() };
						std::string s3;
						int n3 = 1;
						if (command_in_file[0] >= '0' && command_in_file[0] <= '9') {
							iss3 >> n3;
						}
						iss3 >> s3;
						for (int q = 0; q < n3; ++q) {
							if (s3[0] == 'd') {
								if (s3[1] == 'o') {
									gameplay.down();
								}
								else {
									gameplay.drop();
								}
							}
							else if (s3[0] == 'c') {
								if (s3[1] == 'l') {
									gameplay.clock();
								}
								else {
									gameplay.counter();
								}
							}
							else if (s3[0] == 'l') {
								if (s3[2] == 'f') {
									gameplay.left();
								}
								else if (s3[5] == 'u') {
									gameplay.levelup();
								}
								else if (s3[5] == 'd') {
									gameplay.leveldown();
								}
							}
							else if (s3[0] == 'r') {
								if (s3[1] == 'a') {
									gameplay.set_random(true);//random
								}
								else if (s3[1] == 'e') {
									gameplay.restart();
									gameplay.setseed();
									gameplay.next_char(0);

								}
								else {
									gameplay.right();

								}
							}
							else if (s3[0] == 'h') {
								hint = true;
								gameplay.hint();
								if (!text) gameplay.graphic();
							}
							else if (s3[0] == 'n') {
								std::string file3;
								iss3 >> file3;
								gameplay.readsequence(file3);
								gameplay.set_random(false);//norandom
							}
							else if (s3[0] == 'I' || s3[0] == 'J' || s3[0] == 'K' || s3[0] == 'L' || s3[0] == 'O' || s3[0] == 'S' || s3[0] == 'T') {
								char this_char = s3[0];
								gameplay.get_cur_block()->clear();
								gameplay.next_block(this_char);
							}
						}
					}

				}

				else {
					gameplay.readsequence(file);
					gameplay.set_random(false);//norandom
				}
			}
			else if (s[0] == 'I' || s[0] == 'J' || s[0] == 'K' || s[0] == 'L' || s[0] == 'O' || s[0] == 'S' || s[0] == 'T') {
				char this_char = s[0];
				gameplay.get_cur_block()->clear();
				//gameplay.remove_cur();
				gameplay.next_block(this_char);
			}

		}
		if(!hint) std::cout << gameplay << std::endl;
		if (!text&&!hint) {
			gameplay.graphic();
		}
	}


	return 0;

}
