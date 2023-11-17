#include "goodevent.h"
#include "controller.h"
#include "player.h"
GoodEvent::GoodEvent(Controller& cont, Player& plr) : controller(cont), player(plr){}

int GoodEvent::type(){
	return 1;
}
Event* GoodEvent::clone(){
	return new GoodEvent(*this);
}
void GoodEvent::event_happens(){
	player.change_score(ADD_SCORE);
}
