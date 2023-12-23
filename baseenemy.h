#include <cstdio>
#include <vector>
#include <string>

#ifndef BASE_ENEMY
#define BASE_ENEMY

class BaseEnemy{
public:
	virtual std::pair<uint8_t, uint8_t> get_cord() = 0;
	virtual void move() = 0;
	virtual void interact() = 0;
	virtual bool is_player_reached() = 0;

};

#endif
