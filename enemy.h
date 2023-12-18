#include "movementstalker.h"
#include "movementrandom.h"
#include "interactionteleport.h"
#include "interactionhp.h"
#ifndef ENEMY
#define ENEMY
class Controller;
class Player;

template <class MoveScheme, class InteractScheme>
class Enemy{
private:
	std::pair<uint8_t, uint8_t> cur_cord;
	Player& player;
	Controller& controller;
	MoveScheme M;
	InteractScheme I;
public:
	Enemy(std::pair<uint8_t, uint8_t> cur_cord, Player& plr, Controller& cont, MoveScheme M, InteractScheme I);
	std::pair<uint8_t, uint8_t> get_cord();
	void move();
	void interact();
	bool is_player_reached();

};
#endif
