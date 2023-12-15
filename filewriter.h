#include "streamwriterinterface.h"
#ifndef FILE_WRT
#define FILE_WRT
class FileWriter : public StreamWriterInterface{
private:
	std::ofstream file;
public:
	FileWriter(std::string path);
	void write(EventMessage& mes) override;
	~FileWriter() override;
};
#endif
