#include "movementrandom.h"
#include "controller.h"
MovementRandom::MovementRandom(){}

int8_t MovementRandom::ret_neg_pos(){
	int8_t ans = std::rand() % 2;
	if(ans) return ans;
	return -1;
} // returns either 1 or -1

std::pair<uint8_t, uint8_t> MovementRandom::move(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord){
	int8_t add_x;
	int8_t add_y;
	bool not_through = true;
	uint8_t variant_is_x;
	while(not_through){
		add_x = this->ret_neg_pos();
		add_y = this->ret_neg_pos();
		variant_is_x = std::rand() % 2;
		if(variant_is_x){
			not_through = !cont.check_through_cell(cur_cord.first + add_x, cur_cord.second);
			variant_is_x = false;
		}else{
			not_through = !cont.check_through_cell(cur_cord.first, cur_cord.second + add_y);
			variant_is_x = true;
		}
	}
	if(!variant_is_x){
		cur_cord.first = cur_cord.first + add_x;
	}else{
		cur_cord.second = cur_cord.second + add_y;
	}
	return cur_cord;
}
