#include "streamwriterinterface.h"
#ifndef TERM_WR
#define TERM_WR
class TerminalWriter : public StreamWriterInterface{
public:
	void write(EventMessage& mes) override;
};
#endif
