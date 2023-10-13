#include "controller.h"
int main(){
	/*
    Player momo = Player("Strug", 90);
    momo.print();
    Controller cont = Controller(momo, 2, 2);
    cont.print();
    for(int i = 0; i < 2; i++ ){
        cont.move(right);
        cont.print();
    }

    momo.change_health(-40);
    momo.change_score(25);

    std::cout  << momo.get_name() << " status:" << std::endl;
    std::cout <<"max_health: " << (int)momo.get_max_health() << ", cur_health: "<<(int)momo.get_health() << ", score: "<< (int)momo.get_score() << std::endl;

    Player greg = Player("Greg", 300);
    greg.print();
    Controller cont2 = Controller(greg, 80, 80);
    cont2.print();
    */
	Player momo = Player("Strug", 90);
	momo.print();
	std::pair<uint8_t, uint8_t> tmp, tmp2, tmp3, tmp4;
	tmp.first = 5;
	tmp.second = 5;
	tmp2 = std::make_pair(0, 0);
	tmp3 = std::make_pair(3, 3);
	tmp4 = std::make_pair(1, 0);
	Field f = Field(tmp, tmp2, tmp3);
	Cell& t = f.get_cell(tmp4);
	t.change_is_go_through(false);
	Controller cont = Controller(momo, f);
	for(int i = 0; i < 6; i++){
		cont.move(right);
	}
	Field& gg = f;
	//f.prt();
	Field g = Field(gg);
	Field l = g;
	f.prt();
	g.prt();
	l.prt();

    return 0;
}
