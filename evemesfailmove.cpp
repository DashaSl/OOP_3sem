#include "evemesfailmove.h"

EventMessageFailMove::EventMessageFailMove(char c){
	button = c;
}

std::string EventMessageFailMove::to_string(){
	std::string but = {button};
	return "fail: " + but;
}


