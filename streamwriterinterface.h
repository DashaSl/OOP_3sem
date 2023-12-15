#include "eventmessage.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#ifndef STR_WR_INT
#define STR_WR_INT
class StreamWriterInterface{
public:
	virtual void write(EventMessage& mes) = 0;
	virtual ~StreamWriterInterface() = 0;
};
#endif
