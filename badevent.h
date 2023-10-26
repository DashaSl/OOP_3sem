#include "event.h"
#ifndef BEVE
#define BEVE
#define SUB_HEALTH -5

class BadEvent : public Event{
public:
	BadEvent();
	Event* clone();
	int type();
	void event_happens(Controller* cont) override;
};
#endif
