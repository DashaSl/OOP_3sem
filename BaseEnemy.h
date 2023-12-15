#ifndef BAZE_ENEMY
#define BAZE_ENEMY
class Controller;
class BaseEnemy{
public:
	virtual std::pair<uint8_t, uint8_t> get_cord() = 0;
	virtual void move() = 0;
	virtual void interact() = 0;
	virtual bool is_player_reached() = 0;
};
#endif
