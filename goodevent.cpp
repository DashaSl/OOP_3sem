#include "goodevent.h"
#include "controller.h"

GoodEvent::GoodEvent(){}
int GoodEvent::type(){
	return 1;
}
Event* GoodEvent::clone(){
	return new GoodEvent(*this);
}
void GoodEvent::event_happens(Controller* cont){
	(cont->get_player()).change_score(ADD_SCORE);
}
