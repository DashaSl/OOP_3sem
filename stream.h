#ifndef GAMEMOVER_FILE
#define GAMEMOVER_FILE
#include "filereader.h"
#include "read.h"
class Game;
enum Move_constant;
class Stream{
private:
	char up_ = 'w';
	char down_ = 's';
	char left_ = 'a';
	char right_ = 'd';
	char exit_ = 'q';
	char new_ = 'e';
	char restore_ = 'r';
	char save_ = 't';
public:
	void stream_change(std::string path);
	Move_constant key_operator(char c);
};

#endif
