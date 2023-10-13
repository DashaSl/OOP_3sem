#ifndef OOP_3SEM_PROJECT_CONTROLLER_2_H
#define OOP_3SEM_PROJECT_CONTROLLER_2_H
#include "player.h"
#include "field.h"
enum Move_constant {up = -1, left, down , right}; // down - 1, up - -1, left - 0 (-1), right 2 (-1)

class Controller{
private:
    Player& character;
    Field &field;
    uint8_t cord[2];
    uint8_t width;
    uint8_t height;
public:
    Controller(Player &plr, Field &fld);
    bool move(Move_constant way);
};

#endif //OOP_3SEM_PROJECT_CONTROLLER_2_H
