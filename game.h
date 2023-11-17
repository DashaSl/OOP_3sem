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
	GameMover* read_ex;
public:
	Game(GameMover* rd, std::string name = "Noname", int lvl = 0, GameMover* rd_ex = nullptr);
	void start_new(std::string name = "Noname", int lvl = 0);
	void end_programm();
	void change_stream();
	int run(); //exit, new game, end
	bool is_alive();
	bool is_finish();
	~Game();
};

#endif
