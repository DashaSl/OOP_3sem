#include "interactionteleport.h"


std::pair<uint8_t, uint8_t> InteractionTeleport::get_random_cell(Controller& cont){
	uint8_t height = cont.get_height();
	uint8_t width = cont.get_width();
	uint8_t x = std::rand() % width;
	uint8_t y = std::rand() % height;
	bool flag = cont.check_through_cell(x, y);
	while(!flag){
		x = std::rand() % width;
		y = std::rand() % height;
		flag = cont.check_through_cell(x, y);
	}

	std::pair<uint8_t, uint8_t> ans;
	ans.first = x;
	ans.second = y;
	return ans;
}

void InteractionTeleport::interact(Player& plr, Controller& cont){
	std::pair<uint8_t, uint8_t> new_place = this->get_random_cell(cont);
	cont.change_cords(new_place.first, new_place.second);
}
