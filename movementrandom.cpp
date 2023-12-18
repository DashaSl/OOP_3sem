#include "movementrandom.h"
#include "controller.h"
MovementRandom::MovementRandom(){}

int8_t MovementRandom::ret_neg_pos(){
	int8_t ans = std::rand() % 2;
	if(ans) return ans;
	return -1;
}

std::pair<uint8_t, uint8_t> MovementRandom::move(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord){
	int8_t add_x = this->ret_neg_pos(); //0, 1 -> -1, 1
	int8_t add_y = this->ret_neg_pos(); //0, 1 -> -1, 1
	uint8_t variant = std::rand() % 2;

	int8_t x = cur_cord.first;
	int8_t y = cur_cord.second;

	bool flag = false;

	std::pair<uint8_t, uint8_t> ans;

	ans.first = x;
	ans.second = y;

	while(!flag){
		x = ans.first;
		y = ans.second;
		if(variant){
			x += add_x;
		}else{
			y += add_y;
		}

		flag = cont.check_through_cell(x, y);
	}
	ans.first = x;
	ans.second = y;
	return ans;
}
