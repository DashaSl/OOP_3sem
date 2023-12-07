#include "eventmessage.h"

#ifndef EVEMESM
#define EVEMESM
class EventMessageMove: public EventMessage{
private:
	char button;
	Move_constant move;
public:
	EventMessageMove(char c, Move_constant mv);
	std::string get_move();
	std::string to_string() override;
};
#endif
