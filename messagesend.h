#include "filewriter.h"
#include "terminalwriter.h"
#include <set>
#ifndef MES_SEND
#define MES_SEND

class MessageSend{
private:
	std::set<StreamWriterInterface*>& write_set;
public:
	MessageSend(std::set<StreamWriterInterface*>& wrt);
	void output_message(EventMessage& mes);
};


#endif
