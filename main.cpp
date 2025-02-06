#include "gamestalker.h"
int main(int argc, char* argv[]){
	std::srand(time(0));

	Stream rd;
	Read r;

	if(argc > 2){
		std::cout << "Too many arguments! only first one will count!\n";
	}else if(argc > 1){
		std::string tmp_string = argv[1];
		rd.stream_change(tmp_string);
		std::cout << "Configuration "<<tmp_string << " was chosen\n";
	}
	
	char button_act = 'a';
	std::string button = "d";
	std::set<StreamWriterInterface*> ans;
	ans.insert(new TerminalWriter());

	MessageSend messend = MessageSend(ans);


	std::cout << "Enter name:\n";
	std::cin >> button;
	Game gm = Game(rd, r, button);
	std::cout << "starting game\n";
	std::cout << "You need to go from upper left corner to the lower right corner. To do so, you need to go through several walls." << std::endl;
	std::cout << "Each wall has 4 doors - the one which does nothing, other can teleport you, third does damage to you and fourth can give you points." << std::endl;
	std::cout << "Also there are enemies which look like XX. They can either teleport you or do damage."<< std::endl;
	std::cout << "You look like @@. Use a,w,d,s buttons to go right, up, left, down. Use q in order to quit. Use e to start new game." << std::endl;
	Drawer dr;
	GameStalker gmstkr = GameStalker(gm, dr, messend);


	gm.run(gmstkr);

	for(StreamWriterInterface* wrt : ans){
		delete wrt;
	}

	return 0;
}
