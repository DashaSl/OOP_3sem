#include "game.h"
#include "FileStream.h"
FileStream::FileStream(std::string path){
	file.open(path);
}

char FileStream::key_operator(){
	char c;
	file >> c;
	switch(c){
		case 'w':
			return c;
		case 'd':
			return c;
		case 's':
			return c;
		case 'a':
			return c;
		case 'q':
			return c;
		case 'e':
			return c;
		case 'z':
			return 'z';
		default:
			return 'u';
	}
}

FileStream::~FileStream(){
	file.close();
}
