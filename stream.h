#ifndef GAMEMOVER_STREAM
#define GAMEMOVER_STREAM
#include "gamemover.h"
class StreamMove : public GameMover{

public:
	StreamMove();
	char key_operator() override;

};

#endif
