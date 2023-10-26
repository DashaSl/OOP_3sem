#include "teleportevent.h"
#include "controller.h"
TeleportEvent::TeleportEvent(){}

int TeleportEvent::type(){
	return 3;
}

Event* TeleportEvent::clone(){
	return new TeleportEvent(*this);
}

void TeleportEvent::event_happens(Controller* cont){
	uint8_t rand_x, rand_y;
	uint8_t wid, hei;
	Field& fl = cont->get_field();
	wid = cont->get_width();
	hei = cont->get_height();
	std::srand(time(0)); //чтобы рандом был рандомным
	for(int i = 0; i<MAX_CHECKS; i++){
		rand_x = (uint8_t)(std::rand() % (int)wid);
		rand_y = (uint8_t)(std::rand() % (int)hei);
		Cell& cl = fl.get_cell(std::make_pair(rand_x, rand_y));
		if(cl.get_is_go_through() && cl.get_status() != (cell_status)3){
			cont->change_cords(rand_x, rand_y);
			break;
		}
	}
}
