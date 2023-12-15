#include "movementstalker.h"

std::pair<uint8_t, uint8_t> MovementStalker::move(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord){
	std::pair<uint8_t, uint8_t> player_cord = cont.get_cord();
	int8_t x = cur_cord.first;
	int8_t y = cur_cord.second;
	if(player_cord == cur_cord){
		return this->get_random_cell(cont);
	}
	int8_t diff_x = x - player_cord.first; //diff < 0 => player is on right => need to add 1 ||| else add -1
	int8_t diff_y = y - player_cord.second; //diff < 0  => player is lower => need to add 1 ||| else add -1  || CASE == 0 => on same line! ||if abs(diff) == 1 in closest wall

	std::pair<uint8_t, uint8_t> ans;
	ans.first = x;
	ans.second = y;

	if(y == 0){ //diff_x != 0 'cause obvious
		if(this->check_is_wall(cont, cur_cord)){ //we are on the wall
			y += 1;//go down, cause player always goes down
			ans.second = y;
			if(cont.check_through_cell(x, y)) return ans;
			return cur_cord;
		}
		if(diff_x > 0){
			x -= 1;
		}else if(diff_x < 0){
			x += 1;
		}
		ans.first = x;
		if(cont.check_through_cell(x, y)) return ans;
		return cur_cord;
	}

	uint8_t closest_door;

	if(diff_y > 0){
		y -= 1;
		closest_door = this->calc_closest_door(cont, cur_cord, -1);
	}else{
		y += 1;
		closest_door = this->calc_closest_door(cont, cur_cord, 1);
	}

	diff_x = x - closest_door;
	if(diff_x == 0){
		if(diff_y > 0){
			y -= 1;
		}else{
			y += 1;
		}
		ans.second = y;
		if(cont.check_through_cell(x, y)) return ans;
		return cur_cord;
	}

	if(diff_x < 0){
		x += 1;
	}else{
		x -= 1;
	}
	ans.first = x;
	if(cont.check_through_cell(x, y)) return ans;
	return cur_cord;

}


std::pair<uint8_t, uint8_t> MovementStalker::get_random_cell(Controller& cont){
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


bool MovementStalker::check_is_wall(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord){
	uint8_t width = cont.get_width();
	uint8_t y = cur_cord.second;
	for(int i = 0; i < width; i++){
		if(!cont.check_through_cell(i, y)){
			return true;
		}
	}
	return false;
}




uint8_t MovementStalker::calc_closest_door(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord, int8_t up_down){
	int8_t left_x = -1;
	int8_t right_x = -1;
	int8_t y = cur_cord.second + up_down;
	uint8_t width = cont.get_width();
	int8_t x = cur_cord.first;
	for(int i = cur_cord.first; i < width; i++){
		if(cont.check_through_cell(i, y)){
			right_x = i;
			break;
		}
	}

	for(int i = cur_cord.first; i >= 0; i--){
		if(cont.check_through_cell(i, y)){
			left_x = i;
			break;
		}
	}
	if(left_x == -1 && right_x == -1){
		std::cout << "You've f up! (In movementstalker.cpp) \n";
		return x;
	}
	if(left_x == -1) return right_x;
	if(right_x == -1) return left_x;
	if((x - left_x) < (right_x - x)){
		return left_x;
	}else{
		return right_x;
	}

}

