#include "event.h"
#ifndef TEVE
#define TEVE
#define MAX_CHECKS 100
class TeleportEvent : public Event{
private:
	Controller& controller;
public:
	TeleportEvent(Controller& cont);
	Event* clone();
	int type();
	void event_happens(Controller* cont) override;
};
#endif
