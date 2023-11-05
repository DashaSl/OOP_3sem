#ifndef EVENT
#define EVENT

class Controller;

class Event{
public:

	virtual Event* clone() = 0;
	virtual int type() = 0;
	virtual void event_happens(Controller* cont) = 0;
};
#endif
