#include "evemeswin.h"
#include "player.h"

EventMessageWin::EventMessageWin(Player& plr){
	score = plr.get_score();
	health = plr.get_health();
	max_health = plr.get_max_health();
}

std::string EventMessageWin::to_string(){
	return "score: " + std::to_string((int)score) + ", health: " + std::to_string((int)health) + "/"  + std::to_string((int)max_health);
}
