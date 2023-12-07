#include "gamestalker.h"
int main(int argc, char* argv[]){
	std::srand(time(0));
	Stream rd;
	Read r;
	MessageSend messend = MessageSend(false, true, "abobusss.txt");
	if(argc > 2){
		std::cout << "Too many arguments! only first one will count!\n";
	}else if(argc > 1){
		std::string tmp_string = argv[1];
		rd.stream_change(tmp_string);
		std::cout << "Configuration "<<tmp_string << " was chosen\n";
	}
	Game gm = Game(rd, r, "Kanye West");
	std::cout << "starting game\n";
	Drawer dr;
	GameStalker gmstkr = GameStalker(gm, dr, messend);
	gmstkr.prt_info();
	gm.run(gmstkr);

	gmstkr.prt_info();
	Player& plr = gm.get_player();
	Controller& cont = gm.get_controller();

	EventMessageDead emd = EventMessageDead(cont);
	EventMessageWin emw = EventMessageWin(plr);
	EventMessageNew emn = EventMessageNew(cont);
	EventMessageMove emm = EventMessageMove('s', up);
	EventMessageFailMove emfm = EventMessageFailMove('p');

	messend.output_message(emd);
	messend.output_message(emw);
	messend.output_message(emn);
	messend.output_message(emfm);
	std::cout << emd << emw << emn << emm << emfm;
	std::cout << "Program finished!\n";
	return 0;
}
