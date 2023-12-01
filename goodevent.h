#include "event.h"
#ifndef GEVE
#define GEVE
#define ADD_SCORE 5
class GoodEvent : public Event{
private:
	Controller& controller;
	Player& player;
public:
	GoodEvent(Controller& cont, Player& plr);
	Event* clone();
	int type();
	void event_happens() override;
	std::string to_string() override;
};
#endif
