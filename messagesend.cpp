#include "messagesend.h"
#include <set>
MessageSend::MessageSend(std::set<StreamWriterInterface*>& wrt) : write_set(wrt){

}
void MessageSend::output_message(EventMessage& mes){
	for (StreamWriterInterface* wrt : write_set){
		wrt->write(mes);
	}
}
