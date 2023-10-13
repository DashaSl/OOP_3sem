#include "controller.h"


Controller::Controller(Player& plr, Field &fld) : character(plr), field(fld){
	cord[0] = fld.get_start().first;
	cord[1] = fld.get_start().second;
	width = field.get_width();
	height = field.get_height();
}



bool Controller::move(Move_constant way){
	int8_t tmp = 0;
    if(way%2){
        if(cord[1] + way + 1> this->height || cord[1] + way < 0){
            std::cout<<"You can't go further on Y cord!" << std::endl;
            return false;
        }
        cord[1] += way;
    }else{
        tmp = way - 1;
        if(cord[0] + tmp + 1 > this->width || cord[0] + tmp < 0){
            std::cout<<"You can't go further on X cord!" << std::endl;
            return false;
        }
        cord[0] += tmp;
    }

    bool check = field.get_cell(std::make_pair((uint8_t)cord[0], (uint8_t)cord[1])).get_is_go_through();

    if(check){
    	return true;
    }
    std::cout << "this cell is not passable!" << std::endl;
    if(way%2){
    	cord[1] -= way;
    }else{
    	cord[0] -= tmp;
    }
    return false;
}
