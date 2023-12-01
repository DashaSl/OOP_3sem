#include "event.h"
#ifndef BEVE
#define BEVE
#define SUB_HEALTH -15

class BadEvent : public Event{
private:
	Controller& controller;
	Player& player;
public:
	BadEvent(Controller& cont, Player& plr);
	Event* clone();
	int type();
	void event_happens() override;
	std::string to_string() override;
};
#endif
