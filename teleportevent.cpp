#include "teleportevent.h"
#include "controller.h"
#include "player.h"
TeleportEvent::TeleportEvent(Controller& cont, Player& plr) : controller(cont), player(plr){}

int TeleportEvent::type(){
	return 3;
}

Event* TeleportEvent::clone(){
	return new TeleportEvent(*this);
}

void TeleportEvent::event_happens(){
	uint8_t rand_x, rand_y;
	uint8_t wid, hei;
	Field* fl = controller.get_field();
	if(fl == nullptr) return;
	wid = controller.get_width();
	hei = controller.get_height();
	//std::srand(time(0)); //чтобы рандом был рандомным
	for(int i = 0; i<MAX_CHECKS; i++){
		rand_x = (uint8_t)(std::rand() % (int)wid);
		rand_y = (uint8_t)(std::rand() % (int)hei);
		Cell& cl = fl->get_cell(std::make_pair(rand_x, rand_y));
		if(cl.get_is_go_through() && cl.get_status() == (cell_status)2){
			controller.change_cords(rand_x, rand_y);
			break;
		}
	}
}

std::string TeleportEvent::to_string(){
	std::string tmp = "teleport event";
	return tmp;
}
