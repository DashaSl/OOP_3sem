#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdint>
#include "controller.h"
class Player;


#ifndef EVEMES
#define EVEMES
class EventMessage{
public:
	virtual std::string to_string() = 0;
};
std::ostream& operator<<(std::ostream &os, EventMessage& mes);
#endif
