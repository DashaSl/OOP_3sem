#include "field.h"
#define LVL1_W 20
#define LVL1_H 13
#define LVL2_W 13
#define LVL2_H 20
class FieldGenerator{
public:
	FieldGenerator();
	Field generate_lvl1();
	Field generate_lvl2();
};
