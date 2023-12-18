#ifndef INTER_HP
#define INTER_HP
class Controller;
class Player;
#include <utility>
#include <cstdint>

#define HP_CHANGE -5

class InteractionHp{
public:
	InteractionHp();
	void interact(Player& plr, Controller& cont);
};
#endif
