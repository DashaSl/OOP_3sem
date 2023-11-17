#include "controller.h"
#include "fieldgenerator.h"
#include "gamemover.h"
#ifndef GAME
#define GAME

class Game{
private:
	Controller* controller;
	Player* player;
	FieldGenerator gen;
	GameMover* read;
public:
	Game(GameMover* rd, std::string name = "Noname", int lvl = 0);
	void start_new(std::string name = "Noname", int lvl = 0);
	void end_programm();
	int run(); //exit, new game, end
	bool is_alive();
	bool is_finish();
	~Game();
};

#endif
