#include "gamestalker.h"
int main(int argc, char* argv[]){
	std::srand(time(0));
	Stream rd;
	if(argc > 2){
		std::cout << "Too many arguments! only first one will count!\n";
	}else if(argc > 1){
		std::string tmp_string = argv[1];
		rd.stream_change(tmp_string);
		std::cout << "Configuration "<<tmp_string << " was chosen\n";
	}
	Game gm = Game(rd, "Popa");
	std::cout << "starting game\n";
	Drawer dr;
	GameStalker gmstkr = GameStalker(gm, dr);
	gmstkr.prt_info();
	gm.run(gmstkr);
	std::cout << "Programm finished!\n";
	gmstkr.prt_info();
	return 0;
}
