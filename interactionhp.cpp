#include "interactionhp.h"
#include "controller.h"
InteractionHp::InteractionHp(){}

void InteractionHp::interact(Player& plr, Controller& cont){
	plr.change_health(HP_CHANGE);
}
