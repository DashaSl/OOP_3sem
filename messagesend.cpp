#include "messagesend.h"

MessageSend::MessageSend(bool terminal_output, bool file_output, std::string name){
	term_out = terminal_output;
	file_out = file_output;
	if(file_output){
		flwr = new FileWriter(name);
	}
}
void MessageSend::output_message(EventMessage& mes){
	if(term_out){
		std::cout << mes;
	}
	if(file_out){
		flwr->write(mes);
	}
}
MessageSend::~MessageSend(){
	delete this->flwr;
}
