#include "event.h"
#ifndef TEVE
#define TEVE
#define MAX_CHECKS 100
class TeleportEvent : public Event{
private:
	Controller& controller;
	Player& player;
public:
	TeleportEvent(Controller& cont, Player& plr);
	Event* clone();
	int type();
	void event_happens() override;
	std::string to_string() override;
};
#endif
