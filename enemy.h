#include "movementstalker.h"
#include "movementrandom.h"
#include "interactionteleport.h"
#include "interactionhp.h"
#ifndef ENEMY_ENEMY
#define ENEMY_ENEMY
class Controller;
class Player;
#include "baseenemy.h"
#define PAUSE 3
template <class MoveScheme, class InteractScheme>
class Enemy: public BaseEnemy{
private:
	std::pair<uint8_t, uint8_t> cur_cord;
	Player& player;
	Controller& controller;
	MoveScheme M;
	InteractScheme I;
	uint8_t interaction_pause;
public:
	Enemy(std::pair<uint8_t, uint8_t> cur_cord, Player& plr, Controller& cont, MoveScheme M, InteractScheme I);
	std::pair<uint8_t, uint8_t> get_cord() override;
	void move() override;
	void interact() override;
	bool is_player_reached() override;

};
#endif
