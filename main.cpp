
#include "game.h"
#include "stream.h"
int main(){

	std::srand(time(0));

	FileReader flrd = FileReader("config1.txt");
	std::map <std::string, char> mapa= flrd.get_keys();
	for (const auto& [action, key] : mapa)
	        std::cout << action << "\t" << key << std::endl;
	FileReader flrd2 = FileReader("config2.txt");
	std::cout << "\nConfig with errors\n";
	mapa = flrd2.get_keys();
	for (const auto& [action, key] : mapa)
		        std::cout << action << "\t" << key << std::endl;

	std::cout << "\nTest stream\n";
	/*
	Stream strm;
	strm.stream_change("config1.txt");

	char tmp;
	while(tmp != 'q'){
		tmp = strm.key_operator();
		std::cout << tmp << " ";
	}*/
	std::cout << "\n\nGame test\n";
	Game game1 = Game("Pyotr", "config1.txt");
	game1.run();
	std::cout << "Programm finished!\n";
	return 0;
}
