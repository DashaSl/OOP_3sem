#include "eventmessage.h"
#ifndef EVEMESD
#define EVEMESD

class EventMessageDead : public EventMessage{
private:
	std::pair<uint8_t, uint8_t> cord;
public:
	EventMessageDead(Controller& cont);
	std::string to_string() override;
};
#endif
