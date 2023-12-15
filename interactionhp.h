#include "controller.h"
#ifndef INTER_HP
#define INTER_HP
class Controller;

#define HP_CHANGE -5

class InteractionHp{
public:
	void interact(Player& plr, Controller& cont);
};
#endif
