
#ifndef INTER_TELEP
#define INTER_TELEP
class Controller;
class Player;
#include <utility>
#include <cstdint>

#define HP_CHANGE -5

class InteractionTeleport{
public:
	InteractionTeleport();
	void interact(Player& plr, Controller& cont);
	std::pair<uint8_t, uint8_t> get_random_cell(Controller& cont);
};
#endif
