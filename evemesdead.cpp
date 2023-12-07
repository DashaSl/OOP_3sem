#include "evemesdead.h"
#include "controller.h"


EventMessageDead::EventMessageDead(Controller& cont){
	cord = cont.get_cord();
}

std::string EventMessageDead::to_string(){
	return "dead at: x - " + std::to_string((int)cord.first) + ", y - " + std::to_string((int)cord.second);
}

