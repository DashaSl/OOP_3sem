#include "eventmessage.h"
#ifndef EVEMESFM
#define EVEMESFM

class EventMessageFailMove: public EventMessage{
private:
	char button;
public:
	EventMessageFailMove(char c);
	std::string to_string() override;
};
#endif
