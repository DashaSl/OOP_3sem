#include "badevent.h"
#include "controller.h"
BadEvent::BadEvent(Controller& cont) : controller(cont){}

int BadEvent::type(){
	return 2;
}
Event* BadEvent::clone(){
	return new BadEvent(*this);
}
void BadEvent::event_happens(Controller* cont){
	(cont->get_player()).change_health(SUB_HEALTH);
}
