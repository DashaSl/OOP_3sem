#include "controller.h"
#ifndef MOVE_STALK
#define MOVE_STALK
class Controller;
class MovementStalker{
public:
	std::pair<uint8_t, uint8_t> move(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord);
	std::pair<uint8_t, uint8_t> get_random_cell(Controller& cont);
	bool check_is_wall(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord);
	uint8_t calc_closest_door(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord, int8_t up_down);
};
#endif
