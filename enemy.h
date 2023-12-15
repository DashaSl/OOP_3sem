#include "movementstalker.h"
#include "movementrandom.h"
#include "interactionteleport.h"
#include "interactionhp.h"
#include "BaseEnemy.h"
#ifndef ENEMY
#define ENEMY
template <typename MoveScheme, typename InteractScheme>
class Enemy : public BaseEnemy{
private:
	std::pair<uint8_t, uint8_t> cur_cord;
	Player& player;
	Controller& controller;
public:
	Enemy<MoveScheme, InteractScheme>(std::pair<uint8_t, uint8_t> cur_cord, Player& plr, Controller& cont);
	std::pair<uint8_t, uint8_t> get_cord() override;
	void move() override;
	void interact() override;
	bool is_player_reached() override;

};
#endif
