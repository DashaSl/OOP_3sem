#ifndef OOP_3SEM_PROJECT_CONTROLLER_2_H
#define OOP_3SEM_PROJECT_CONTROLLER_2_H
#include "player.h"
enum Move_constant {up = -1, left, down , right}; // down - 1, up - -1, left - 0 (-1), right 2 (-1)

class Controller{
private:
    Player* character;
    uint8_t cord[2];
    uint8_t max_x;
    uint8_t max_y;
public:
    Controller(Player* plr, int width, int length) {
        character = plr;
        if(plr == nullptr){
            std::cout << "Hey! This player doesn't exist!" << std::endl;
        }
        cord[0] = 0; cord[1] = 0;
        if(width > 50 || width < 1){
            std::cout << "width is out of possible range - [1, 50]. So it is 30 then." << std::endl;
            width = 30;
        }
        if(length > 50 || length < 1){
            std::cout << "length is out of possible range - [1, 50]. So it is 30 then." << std::endl;
            length = 30;
        }
        max_x = width;
        max_y = length;
    }
    void print();
    bool move(Move_constant way);
};

#endif //OOP_3SEM_PROJECT_CONTROLLER_2_H
