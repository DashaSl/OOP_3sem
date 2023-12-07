#include <cstdio>
#include <iostream>
#include <fstream>
#include "eventmessage.h"
#ifndef FILE_WRT
#define FILE_WRT
class FileWriter{
private:
	std::ofstream file;
public:
	FileWriter(std::string path);
	void write(EventMessage& mes);
	~FileWriter();
};
#endif
