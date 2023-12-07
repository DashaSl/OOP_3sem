#include "eventmessage.h"
#ifndef EVEMESN
#define EVEMESN

class EventMessageNew: public EventMessage{
private:
	uint8_t height;
	uint8_t width;
	std::pair<uint8_t, uint8_t> start;
public:
	EventMessageNew(Controller& cont);
	std::string to_string() override;
};
#endif
