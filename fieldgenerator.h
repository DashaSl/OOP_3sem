#include "field.h"
#ifndef FLD_GEN
#define FLD_GEN
#define LVL1_W 20
#define LVL1_H 13
#define LVL2_W 13
#define LVL2_H 20
class Controller;
class FieldGenerator{
public:
	void generate_lvl(Controller& cont, Player& plr);
};
#endif
