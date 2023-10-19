#ifndef CELL
#define CELL


#ifndef BASIC
#define BASIC
#include <iostream>
#include <string>
#include <cstring>
#endif

//класс события в будующем будет перведён в свой .h, пока это заглушка
enum cell_status {start = 0, event, noevent, finish};
class Event{
public:
	std::string name;
	Event(std::string nm = "noname");
	Event(const Event& eve);
};

class Cell{
private:
	cell_status status;
	bool is_go_through;
	std::pair<uint8_t, uint8_t> cords;
	Event* event;
public:
	Cell(std::pair<uint8_t, uint8_t> xy = std::make_pair((uint8_t)0, (uint8_t)0), bool igt = true, Event* eve = nullptr, cell_status sts = noevent);

	bool get_is_go_through();
	void change_is_go_through(bool change);
	cell_status get_status();
	void change_status(cell_status change);
	void change_event(Event* eve);

	Event* get_event();
	Cell& operator=(const Cell& cl); //надо будет до-реализовать с появлением event, т.к. там будет указатель.

	void prt();
	~Cell();
};

#endif
