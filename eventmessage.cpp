#include "eventmessage.h"

std::ostream& operator<<(std::ostream &os, EventMessage& mv){
	return os << mv.to_string() << "\n";
}
