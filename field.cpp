#include "field.h"

std::pair<uint8_t, uint8_t> Field::check_cords(std::pair<uint8_t, uint8_t> cord, uint8_t flag){
	//flag 0 - ширина и высотаб 1 - начало или  2 - конец
	if(flag == 1){

		if(cord.first >= this->width) cord.first = 0;
		if(cord.second >= this->height) cord.second = 0;

		return cord;
	}

	if(flag == 2){

			if(cord.first >= this->width) cord.first = width-1;
			if(cord.second >= this->height) cord.second = height - 1;

			return cord;
	}

	if(cord.first > MAX_WID || cord.first < 2) cord.first = 30;
	if(cord.second > MAX_HEI || cord.second < 2) cord.second = 30;

	return cord;
}

Field::Field(std::pair<uint8_t, uint8_t> wid_hei, std::pair<uint8_t, uint8_t> beg, std::pair<uint8_t, uint8_t> fin){
	wid_hei = this->check_cords(wid_hei, 0);
	width = wid_hei.first;
	height = wid_hei.second;

	beg = this->check_cords(beg, 1);
	fin = this->check_cords(fin, 2);

	start = beg;
	finish = fin;

	this->field = new Cell *[height];
	for(int i = 0; i < height; i++){
		this->field[i] = new Cell[width];
		for(int j = 0; j < width; j++){
			this->field[i][j] = Cell(std::make_pair((uint8_t)j, (uint8_t)i)); //как и какие клетки генерить - выясним позже
		}
	}

	(this->field[start.second][start.first]).change_status((cell_status)0);
	(this->field[finish.second][finish.first]).change_status((cell_status)3);
}

void Field::prt(){
	std::cout << "------field-------"<<std::endl;
	std::cout << "size: width = " << (int)width << ", height = "<< (int)height << std::endl;
	std::cout << "start: x = "<< (int)start.first << ", y = " << (int)start.second << ". Status: " <<  (this->field[start.second][start.first]).get_status() << std::endl;
	std::cout << "finish: x = "<< (int)finish.first << ", y = " << (int)finish.second << ". Status: " <<  (this->field[finish.second][finish.first]).get_status() << std::endl;
	std::cout << "----end field-----"<<std::endl;

}

Field::~Field(){
	if(this->field != nullptr){
		for(int i = 0; i < height; i++){
			delete [] field[i];
		}
		delete [] field;
	}
}

uint8_t Field::get_width(){
	return width;
}

uint8_t Field::get_height(){
	return height;
}

std::pair<uint8_t, uint8_t> Field::get_start(){
	return start;
}
std::pair<uint8_t, uint8_t> Field::get_finish(){
	return finish;
}

Cell& Field::get_cell(std::pair<uint8_t, uint8_t> cel){
	return this->field[(int)cel.second][(int)cel.first];
}


Cell** Field::get_adress(){
	return field;
}

Field::Field(const Field &fld){
	this->width = fld.width;
	this->height = fld.height;
	this->start = fld.start;
	this->finish = fld.finish;

	this->field = new Cell *[height];
	for(int i = 0; i < height; i++){
		this->field[i] = new Cell[width];
	}


	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			this->field[i][j] = fld.field[i][j];
		}
	}
}

Field& Field::operator =(const Field& fld){
	if(&fld == this) return *this;
	this->width = fld.width;
	this->height = fld.height;
	this->start = fld.start;
	this->finish = fld.finish;

	this->field = new Cell *[height];
	for(int i = 0; i < height; i++){
		this->field[i] = new Cell[width];
	}


	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			this->field[i][j] = fld.field[i][j];
		}
	}
	return *this;
}

Field::Field(Field &&fld): width(fld.width), height(fld.height), start(fld.start), finish(fld.finish), field(fld.field){
	fld.field = nullptr;
}

Field& Field::operator =(Field&& fld){

	this->width = fld.width;
	this->height = fld.height;
	this->start = fld.start;
	this->finish = fld.finish;
	this->field = fld.field;
	fld.field = nullptr;
	return *this;
}


