#include "controller.h"

void Controller::print(){
    std::cout << "Currient location: "  << (int) cord[0] << ", "<< (int)cord[1]<< std::endl;
}

bool Controller::move(Move_constant way){
    if(way%2){
        if(cord[0] + way + 1> max_x || cord[0] + way < 0){
            std::cout<<"You cant go further on X cord!" << std::endl;
            return false;
        }
        cord[0] += way;
        return true;
    }else{
        int8_t tmp = way - 1;
        if(cord[1] + tmp + 1 > max_y || cord[1] + tmp < 0){
            std::cout<<"You cant go further on Y cord!" << std::endl;
            return false;
        }
        cord[1] += tmp;
        return true;
    }
}