#ifndef OOP_3SEM_PROJECT_CONTROLLER_2_H
#define OOP_3SEM_PROJECT_CONTROLLER_2_H
#include "player.h"
#include "field.h"

enum Move_constant {up = -1, left, down , right, quit, news, no, restore, save}; // down - 1, up - -1, left - 0 (-1), right 2 (-1)

class Controller{
private:
    Field* field;
    uint8_t cord[2];
    uint8_t width;
    uint8_t height;
public:
    Controller(Field* fld = nullptr);
    ~Controller();
    bool event_check();
    bool move(Move_constant way);
    void move_enemy();
    Player& get_player();
    Field* get_field();
    uint8_t get_width();
	uint8_t get_height();
	void change_cords(uint8_t x, uint8_t y);
	std::pair<uint8_t, uint8_t> get_cord();
	void prt();
	void prt2();
	bool check_through_cell(int x, int y);
	void change_field(Field* fld);
};

#endif //OOP_3SEM_PROJECT_CONTROLLER_2_H
