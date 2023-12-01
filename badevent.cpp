#include "badevent.h"
#include "controller.h"
#include "player.h"
BadEvent::BadEvent(Controller& cont, Player& plr) : controller(cont), player(plr){}

int BadEvent::type(){
	return 2;
}
Event* BadEvent::clone(){
	return new BadEvent(*this);
}
void BadEvent::event_happens(){
	player.change_health(SUB_HEALTH);
}

std::string BadEvent::to_string(){
	std::string tmp = "bad event";
	return tmp;
}
