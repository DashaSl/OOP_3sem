
#include "game.h"
#include "stream.h"
#include "FileStream.h"
int main(){
/*
	std::srand(time(0));
	Player plr2 = Player();
	Player plr = Player("Lise", 120);
	Controller cont = Controller();
	cont.prt();
	FieldGenerator gen = FieldGenerator();
	gen.generate_lvl1(cont, plr);
	plr.print();
	cont.prt();
	gen.generate_lvl2(cont, plr2);
	plr.print();
	cont.prt();
	std::cout << "\nProgramm finished!\n";*/

	GameMover* fp = new FileStream("text.txt");
	Game gm = Game(fp ,"Lola");
	std::cout << gm.is_alive() << " " << gm.is_finish() << '\n';
	//gm.end_programm();
	gm.start_new("Lera");

	int a = gm.run();
	std::cout << "programm finished!\n";
	GameMover* fp2 = new StreamMove();
	Game gm2 = Game(fp2, "Lena", 3);
	gm2.run();
    return 0;
}
