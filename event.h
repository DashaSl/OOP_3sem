#ifndef EVENT
#define EVENT
#include <cstdint>
#include <string>
class Controller;
class Player;

class Event{
public:

	virtual Event* clone() = 0;
	virtual int type() = 0;
	virtual void event_happens() = 0;
	virtual std::string to_string() = 0;
};
#endif
