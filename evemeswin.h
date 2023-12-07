#include "eventmessage.h"
#ifndef EVEMESW
#define EVEMESW
class EventMessageWin : public EventMessage{
private:
	uint16_t score;
	uint8_t health;
	uint8_t max_health;
public:
	EventMessageWin(Player& plr);
	std::string to_string() override;
};
#endif
