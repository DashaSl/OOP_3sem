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
}


char Stream::key_operator(){
	Read rd;
	char c = rd.read(); //may change depending on stream
	if(c == up_) return 'w';
	if(c == down_) return 's';
	if(c == left_) return 'a';
	if(c == right_) return 'd';
	if(c == exit_) return 'q';
	if(c == new_) return 'e';
	return '\n'; //just random letter to ignore
}

