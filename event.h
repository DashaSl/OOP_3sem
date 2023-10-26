#ifndef EVENT
#define EVENT

class Controller;

class Event{
public:
	Event();
	virtual Event* clone() = 0;
	virtual int type();
	virtual void event_happens(Controller* cont) = 0;
};
#endif
