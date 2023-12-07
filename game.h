#include "controller.h"
#include "fieldgenerator.h"
#include "stream.h"
#ifndef GAME
#define GAME
class GameStalker;
enum status{killed, win_lvl2, none};
enum end_of_cycle{started_new, next_level, nothing_new};
class Game{
private:
	Controller controller;
	Player player;
	FieldGenerator gen;
	Stream& config;
	Read& read;
	int level;
	uint8_t beg_level_health;
	uint16_t beg_level_score;
public:
	Game(Stream& conf, Read& rd, std::string name = "Noname");
	void start_new(std::string name = "Noname");
	//void change_stream();
	int run(GameStalker& gmstkr); //exit, new game, end
	bool is_alive();
	bool is_finish();
	std::pair<uint8_t, uint8_t> get_finish();
	Controller& get_controller();
	Player& get_player();
	int get_level();
	std::pair<uint8_t, uint8_t> get_cur_cords();
	void restore_game();
	void start_again();
};

#endif
