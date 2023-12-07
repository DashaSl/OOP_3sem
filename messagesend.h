#include "filewriter.h"


#ifndef MES_SEND
#define MES_SEND

class MessageSend{
	FileWriter* flwr;
	bool term_out;
	bool file_out;
public:
	MessageSend(bool terminal_output, bool file_output, std::string name = "untitled.txt");
	void output_message(EventMessage& mes);
	~MessageSend();
};


#endif
