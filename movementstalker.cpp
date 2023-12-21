#include "movementstalker.h"
#include "controller.h"
MovementStalker::MovementStalker(){}

std::pair<uint8_t, uint8_t> MovementStalker::move(Controller& cont, std::pair<uint8_t, uint8_t> cur_cord){
	/*
	 1)Достаём координаты игрока
	 0)Если наши координаты равны - идём в другое место

	 2)Если мы на одном уровне (у равны), то
	 если это не стена - двигаемся к игроку
	 если стена - двигаемся вниз (т.к. игрок всегда идёт вниз)
	 3)На разных уровнях
	 3.1)Разобраться - идти наверх или вниз
	 Если есть возможность двигаться в нужном направлении - идём туда
	 4.2)Иначе вычисляем ближайшую дверь в ряду, - двигаемся к ней
	 */
	std::pair<uint8_t, uint8_t> player_cord = cont.get_cord();

	if(player_cord == cur_cord){
		return cur_cord;
	}

	if(player_cord.second == cur_cord.second){
		bool is_wall = cur_cord.second%2;
		//все стены на нечётных рядах
		if(is_wall){
			cur_cord.second = cur_cord.second - 1;
			return cur_cord;
			//здесь может возникнуть вопрос - а вдруг там стена! - но нет, тог да мы бы не были с игроком на одном уровни (стены чередуются с проходами)
		}else{
			int8_t diff = (int8_t)cur_cord.first - (int8_t)player_cord.first; //  @@   XX -> diff > 0 ->
			if(diff > 0){
				cur_cord.first = cur_cord.first - 1;
				return cur_cord;
			}else{
				cur_cord.first = cur_cord.first + 1;
				return cur_cord;
			}
		}
	}

	//Мы на разных уровнях
	int8_t y_diff = (int)cur_cord.second - (int)player_cord.second;
	int8_t add;
	if(y_diff > 0){
		add = -1;
	}else{
		add = 1;
	}

	if(	cont.check_through_cell(cur_cord.first, cur_cord.second + add)	){
		cur_cord.second = cur_cord.second + add;
		return cur_cord;
	}


	int8_t closest_door = calc_closest_door(cont, cur_cord.first, cur_cord.second + add);

	int8_t x_diff = (int)cur_cord.first - closest_door;

	if(x_diff > 0){
		add = -1;
	}else{
		add = 1;
	}

	cur_cord.first = cur_cord.first + add;
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


int8_t MovementStalker::calc_closest_door(Controller& cont, uint8_t x, uint8_t y){
	int width = cont.get_width();
	int tmp = width*width;
	uint8_t ans = x;
	for(int i = 0; i < width; i++){
		if(cont.check_through_cell(i, y)){

			if(tmp > (i - (int)x)*(i - (int)x)){
				tmp = (i - (int)x)*(i - (int)x);
				ans = i;
			}

		}
	}
	return ans;
}

