#include "controller.h"
#include "fieldgenerator.h"
#include "stream.h"
#ifndef GAME
#define GAME

class Game{
private:
	Controller controller;
	Player player;
	FieldGenerator gen;
	Stream read;
public:
	Game(std::string name = "Noname", std::string path = "");
	void start_new(std::string name = "Noname");
	//void change_stream();
	int run(); //exit, new game, end
	bool is_alive();
	bool is_finish();
};

#endif
