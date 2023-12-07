#include "evemesnew.h"
#include "controller.h"

EventMessageNew::EventMessageNew(Controller& cont){
	height = cont.get_height();
	width = cont.get_width();
	start = cont.get_field()->get_start();
}

std::string EventMessageNew::to_string(){
	return "new game field: height - " + std::to_string((int)height) + ", width - " + std::to_string((int)width) + ", start - (" + std::to_string((int)start.first) + ", " + std::to_string((int)start.second) + ")";
}

