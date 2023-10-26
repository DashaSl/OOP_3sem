#include "cell.h"
#include "event.h"

Cell::Cell(std::pair<uint8_t, uint8_t> xy, bool igt, Event* eve, cell_status sts){
	is_go_through = igt;
	event = eve;
	cords = xy;
	status = sts;
}

bool Cell::get_is_go_through(){
	return is_go_through;
}
void Cell::change_is_go_through(bool change){
	is_go_through = change;
}

cell_status Cell::get_status(){
	return status;
}
void Cell::change_status(cell_status change){
	status = change;
}

Event* Cell::get_event(){
	return event;
}
void Cell::change_event(Event* eve){
	status = (cell_status) 1;
	delete this->event;
	this->event = eve;
}

void Cell::prt(){
	std::cout << "------------" << std::endl;
	std::cout << "Cell at:" << " ("<< (int)cords.first << ", " << (int)cords.second << "). " << std::endl <<"Is go through? " << is_go_through << std::endl;
	std::cout << "Cell status: " << this->get_status() << std::endl;
	std::cout << "------------" << std::endl;
};

Cell& Cell::operator=(const Cell& cl){
	this->status = cl.status;
	this->is_go_through = cl.is_go_through;
	this->cords = cl.cords;

	if(cl.event == nullptr){
		this->event = nullptr;
	}else{
		this->event = cl.event->clone();
	}

	return *this;
}

Cell::~Cell(){
	if(event != nullptr){
		delete this->event;
	}

}
