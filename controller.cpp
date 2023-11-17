#include "controller.h"


Controller::Controller(Field* fld){
	field = fld;
	if(fld != nullptr){
		cord[0] = fld->get_start().first;
		cord[1] = fld->get_start().second;
		width = field->get_width();
		height = field->get_height();
	}else{
		cord[0] = 0;
		cord[1] = 0;
		width = 0;
		height = 0;
	}
}

std::pair<uint8_t, uint8_t> Controller::get_cord(){
	std::pair<uint8_t, uint8_t> tmp = std::make_pair(cord[0], cord[1]);
	return tmp;
}

bool Controller::event_check(){
	Cell& cur_cell = (this->field)->get_cell(std::make_pair(cord[0], cord[1]));
	if(cur_cell.get_status() == (cell_status) 1){
		(cur_cell.get_event())->event_happens();
		return true;
	}else{
		return false;
	}
}

bool Controller::move(Move_constant way){
	if(field == nullptr) return false;
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

    bool check = field->get_cell(std::make_pair((uint8_t)cord[0], (uint8_t)cord[1])).get_is_go_through();

    if(check){
    	this->event_check();
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

Field* Controller::get_field(){
	return field;
}
uint8_t Controller::get_width(){
	return width;
}
uint8_t Controller::get_height(){
	return height;
}
void Controller::change_cords(uint8_t x, uint8_t y){
	cord[0] = x;
	cord[1] = y;
}
void Controller::prt(){
	std::cout << "Im at: ("<<(int)cord[0] << ", " <<(int)cord[1]<< ")\n";

	if(field != nullptr){
		this->field->prt();
	}else{
		std::cout << "no field.\n";
	}
}
void Controller::prt2(){
	for(int i = 0; i < width+1; i++){
		std::cout <<"--";
	}
	std::cout << '\n';
	for(int i = 0; i < height; i++){
		std::cout << "-";
		for(int j = 0; j < width; j++){
			if(i == cord[1] && j == cord[0]){
				std::cout << "@@";
			}else{
				if((this->field->get_cell(std::make_pair(j, i))).get_is_go_through()){
					std::cout << "  ";
				}else{
					std::cout << "||";
			}
			}
		}
		std::cout << "-" <<std::endl;
	}
	for(int i = 0; i < width+1; i++){
		std::cout <<"--";
	}
	std::cout << '\n';
}


void Controller::change_field(Field* fld){
	if(this->field != nullptr){
		delete this->field;
	}
	field = fld;
	cord[0] = fld->get_start().first;
	cord[1] = fld->get_start().second;
	width = field->get_width();
	height = field->get_height();
}
Controller::~Controller(){
	if(this->field != nullptr){
			delete field;
	}
}



