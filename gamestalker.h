#include "controller.h"
#include "game.h"
#include "drawer.h"

#include "eventmessage.h"
#include "evemeswin.h"
#include "evemesdead.h"
#include "evemesnew.h"
#include "evemesmove.h"
#include "evemesfailmove.h"
#include "messagesend.h"

#ifndef GAMESTALKER
#define GAMESTALKER
class Game;
enum how_ended{dead, win, quitted, not_yet};
class GameStalker{
	MessageSend& messend;
	int level_1_event_placement[LVL1_H/2][4];
	int level_2_event_placement[LVL2_H/2][4];
	std::string player_name;
	Game& game;
	uint8_t max_health;
	uint8_t cur_health;
	uint8_t cur_score;
	int cur_level;
	std::pair<uint8_t, uint8_t> cur_cords;
	uint8_t width; //
	uint8_t height; //
	how_ended end;
	Drawer& draw;


public:
	GameStalker(Game& gm, Drawer& drw, MessageSend& messend);
	bool check_cords(Move_constant c);
	std::string start_info(Move_constant c, char symb);
	std::string win_death_case(status stat = none);
	void get_info(Move_constant c = no, end_of_cycle eoc = nothing_new);
	void prt_info();
	void update_lvl();
};

#endif
