#include "interactionhp.h"

void InteractionHp::interact(Player& plr, Controller& cont){
	plr.change_health(HP_CHANGE);
}
