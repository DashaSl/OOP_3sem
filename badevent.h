#include "event.h"
#ifndef BEVE
#define BEVE
#define SUB_HEALTH -20

class BadEvent : public Event{
private:
	Controller& controller;
public:
	BadEvent(Controller& cont);
	Event* clone();
	int type();
	void event_happens(Controller* cont) override;
};
#endif
