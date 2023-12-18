#ifndef MOVE_RAND
#define MOVE_RAND
class Controller;
#include <utility>
#include <cstdint>

class MovementRandom{
public:
	MovementRandom();
	std::pair<uint8_t, uint8_t> move(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord);
	int8_t ret_neg_pos();

};
#endif
