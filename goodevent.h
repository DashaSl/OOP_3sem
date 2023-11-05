#include "event.h"
#ifndef GEVE
#define GEVE
#define ADD_SCORE 5
class GoodEvent : public Event{
private:
	Controller& controller;
public:
	GoodEvent(Controller& cont);
	Event* clone();
	int type();
	void event_happens(Controller* cont) override;
};
#endif
