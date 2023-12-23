#include "game.h"
#include "stream.h"

void Stream::stream_change(std::string path){
	FileReader frd = FileReader(path);
	std::map<std::string, char> mapa = frd.get_keys();
	up_ = mapa["up"];
	down_ = mapa["down"];
	left_ = mapa["left"];
	right_ = mapa["right"];
	exit_ = mapa["exit"];
	new_ = mapa["new"];
	restore_ = mapa["restore"];
	save_ = mapa["save"];
}


Move_constant Stream::key_operator(char c){
	if(c == up_) return up;
	if(c == down_) return down;
	if(c == left_) return left;
	if(c == right_) return right;
	if(c == exit_) return quit;
	if(c == new_) return news;
	if(c == restore_) return restore;
	if(c == save_) return save;
	return no; //just random letter to ignore
}

