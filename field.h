#ifndef FIELD
#define FIELD
#include "cell.h"
#define MAX_WID 50
#define MAX_HEI 50
#define MID_HEI 30
#define MID_WID 30
#define MIN_HEI 2
#define MIN_WID 2

class Field{
private:
	Cell** field;
	uint8_t width, height;
	std::pair<uint8_t, uint8_t> start, finish;
public:

	Field(std::pair<uint8_t, uint8_t> wid_hei = std::make_pair((uint8_t)30, (uint8_t)30), std::pair<uint8_t, uint8_t> beg = std::make_pair((uint8_t)0, (uint8_t)0), std::pair<uint8_t, uint8_t> fin = std::make_pair((uint8_t)1, (uint8_t)1));
	~Field();
	std::pair<uint8_t, uint8_t> check_cords(std::pair<uint8_t, uint8_t> cords, uint8_t flag);//flag - для опр, какие координаты проверяем
	void prt();

	uint8_t get_width();
	uint8_t get_height();
	std::pair<uint8_t, uint8_t> get_start();
	std::pair<uint8_t, uint8_t> get_finish();
	Cell** get_adress();//для тестирования
	Cell& get_cell(std::pair<uint8_t, uint8_t> cel);
	Field& operator =(const Field& fld);
	Field (const Field& other);
	Field(Field&& other);
	Field& operator = (Field&& other);



};

#endif
