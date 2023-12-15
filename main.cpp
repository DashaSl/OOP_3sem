#include "gamestalker.h"
int main(int argc, char* argv[]){
	std::srand(time(0));

	Stream rd;
	Read r;


	std::cout << "Config info --------\n";
	if(argc > 2){
		std::cout << "Too many arguments! only first one will count!\n";
	}else if(argc > 1){
		std::string tmp_string = argv[1];
		rd.stream_change(tmp_string);
		std::cout << "Configuration "<<tmp_string << " was chosen\n";
	}
	std::cout << "end config info --------\n";


	std::cout << "do you want to output messages into terminal or into file?\n";
	std::cout << "press:\na - only terminal, b - only file, c - terminal and file\n";
	std::string button = "d";
	char button_act = button[0];
	while(button_act != 'a' && button_act != 'b' && button_act != 'c'){
		std::cin >> button;
		if(button.size() > 1 || button.size() == 0){
			std::cout << "too many/not enough args!\n";
			continue;
		}
		button_act = button[0];
	}
	std::set<StreamWriterInterface*> ans;
	if(button_act == 'a' || button_act == 'c'){
		ans.insert(new TerminalWriter());
	}
	if(button_act == 'b' || button_act == 'c'){
		std::cout << "enter name:\n";
		std::cin >> button;
	    ans.insert(new FileWriter(button));
	}
	MessageSend messend = MessageSend(ans);


	std::cout << "Enter name:\n";
	std::cin >> button;
	Game gm = Game(rd, r, button);
	std::cout << "starting game\n";
	Drawer dr;
	GameStalker gmstkr = GameStalker(gm, dr, messend);

	gm.run(gmstkr);

	gmstkr.prt_info();
	for(StreamWriterInterface* wrt : ans){
		std::cout << wrt << "\n";
		delete wrt;
	}
	/*
	EventMessageDead emd = EventMessageDead(cont);
	EventMessageWin emw = EventMessageWin(plr);
	EventMessageNew emn = EventMessageNew(cont);
	EventMessageMove emm = EventMessageMove('s', up);
	EventMessageFailMove emfm = EventMessageFailMove('p');

	messend.output_message(emd);
	messend.output_message(emw);
	messend.output_message(emn);
	messend.output_message(emfm);
	std::cout << emd << emw << emn << emm << emfm;*/
	std::cout << "Program finished!\n";
	return 0;
}
