#include "evemesmove.h"

EventMessageMove::EventMessageMove(char c, Move_constant mv){
	button = c;
	move = mv;
}

std::string EventMessageMove::get_move(){
	switch(move){
		case up:
			return "up";
		case down:
			return "down";
		case left:
			return "left";
		case right:
			return "right";
		case quit:
			return "quit";
		case news:
			return "new";
		default:
			return "?";
	}
}

std::string EventMessageMove::to_string(){
	std::string mv = this->get_move();
	std::string but = {button};
	return "button: " + but + ", action: " + mv;
}
