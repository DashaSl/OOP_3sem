#ifndef GAMEMOVER_FILE
#define GAMEMOVER_FILE
#include <fstream>
#include "gamemover.h"
class FileStream : public GameMover{
private:
	std::ifstream file;
public:
	FileStream(std::string path);
	char key_operator() override;
	~FileStream();

};

#endif
