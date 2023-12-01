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
public:
	void stream_change(std::string path);
	Move_constant key_operator();
};

#endif
