#ifndef MOVE_STALK
#define MOVE_STALK
class Controller;
#include <utility>
#include <cstdint>

class MovementStalker{
public:
	MovementStalker();
	std::pair<uint8_t, uint8_t> move(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord);
	std::pair<uint8_t, uint8_t> get_random_cell(Controller& cont);
	int8_t calc_closest_door(Controller& cont, uint8_t x, uint8_t y);
};
#endif
