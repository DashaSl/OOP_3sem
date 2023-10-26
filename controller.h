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
    bool event_check();
    bool move(Move_constant way);
    Player& get_player();
    Field& get_field();
    uint8_t get_width();
	uint8_t get_height();
	void change_cords(uint8_t x, uint8_t y);
	void prt_cur_player();
};

#endif //OOP_3SEM_PROJECT_CONTROLLER_2_H
