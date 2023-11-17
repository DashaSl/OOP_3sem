#include "game.h"
#include "stream.h"

StreamMove::StreamMove(){}

char StreamMove::key_operator(){
	char c = getchar();
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
