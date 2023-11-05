#include "controller.h"
#include "fieldgenerator.h"

int main(){
	std::srand(time(0));
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
    *//*
	Player momo = Player("Strug", 90);
	momo.print();
	std::pair<uint8_t, uint8_t> tmp, tmp2, tmp3, tmp4;
	tmp.first = 5;
	tmp.second = 5;
	tmp2 = std::make_pair(0, 0);
	tmp3 = std::make_pair(3, 3);
	tmp4 = std::make_pair(1, 0);
	Field field_0 = Field(tmp, tmp2, tmp3); //поле 5 на 5, старт (0, 0), финиш (3, 3)
	Cell& t = field_0.get_cell(tmp4);
	t.change_is_go_through(false);
	Controller cont = Controller(momo, field_0);
	for(int i = 0; i < 3; i++){
		cont.move(right);
	}

	std::cout << "test 1 - all prisvaivanyia" << std::endl;
	Field fl_1 = field_0; //fl1 -теперь копия field_0
	std::cout << "adress fl1: " << fl_1.get_adress() << '\n';
	Field fl_2 = std::move(fl_1);
	std::cout << "adress fl1: " << fl_1.get_adress() << '\n';
	std::cout << "поэтому std::move - опасен лишний раз\n";
	Field fl3 = Field(field_0); //копия
	Field fl4 = Field(std::move(field_0));
	Field fl5 = Field(std::make_pair(20, 20), std::make_pair(0, 0), std::make_pair(19, 19));
	Field fl6 = fl5;
	std::cout << "TTTTTTTTTT\n";
	fl5.prt();
	fl6.prt();
	std::cout << "test2 - changing event in the copies\n";
	*//*
	Player momo = Player("Strug", 90);

	Field fl_orig = Field(std::make_pair(25, 25), std::make_pair(5, 10), std::make_pair(12, 17));
	Field fl_copy = Field(fl_orig);
	Cell& test_cell = fl_copy.get_cell(std::make_pair(0, 0));
	Event* eve = new TeleportEvent{};
	Event* eve2 = new BadEvent{};
	Event* eve3 = new GoodEvent{};
	test_cell.change_event(eve);
	Cell& orig_cell = fl_orig.get_cell(std::make_pair(0, 0));

	orig_cell.prt();
	test_cell.prt();
	std::cout << std::endl << eve2->type() << std::endl <<std::endl;
	Controller cont = Controller(momo, fl_copy);
	cont.prt_cur_player();
	eve->event_happens(&cont);
	cont.prt_cur_player();

	Field copy_of_changed = fl_copy;
	Cell& copy_of_copy = copy_of_changed.get_cell(std::make_pair(0, 0));
	copy_of_copy.prt();

	c
	delete eve2;
	delete eve3;*/
	/*
	std::cout << "move and event work check\n\n";
	Player plr = Player("Bob", 30);
	Field fl_orig = Field(std::make_pair(25, 25), std::make_pair(0, 0), std::make_pair(12, 17));
	Cell& test_cell = fl_orig.get_cell(std::make_pair(1, 0));
	Event* eve = new TeleportEvent{};
	test_cell.change_event(eve);
	Controller cont = Controller(plr, fl_orig);
	cont.prt_cur_player();
	cont.move(right);

	cont.prt_cur_player();
	std::cout << "\nend of move and event work check\n\n";
	std::cout << "copy move and event work check\n\n";
	Field fl_copy = fl_orig;
	Player plr_2 = Player("Becky", 40);
	Controller cont2 = Controller(plr_2, fl_copy);

	cont2.prt_cur_player();
	cont2.move(right);

	cont2.prt_cur_player();

	std::cout << "end copy move and event work check\n\n";

	std::cout << "check lvl generation\n\n";
	FieldGenerator gen_fl = FieldGenerator();
	Field generated_fl = gen_fl.generate_lvl1();



	generated_fl.prt();
	bool is_g_t;
	for(int i = 0; i < generated_fl.get_width(); i++){
		is_g_t = (generated_fl.get_cell(std::make_pair(i, 1))).get_is_go_through();
		if(is_g_t){
			if((generated_fl.get_cell(std::make_pair(i, 1))).get_status() == noevent){
				std::cout << "0";
			}else{
				std::cout<< ((generated_fl.get_cell(std::make_pair(i, 1))).get_event())->type();
			}
		}else{
			std::cout << "x";
		}
	}
	std::cout << "\n";

	Field hor_fl = gen_fl.generate_lvl2();
	hor_fl.prt();
	for(int i = 0; i < hor_fl.get_height(); i++){
		is_g_t = (hor_fl.get_cell(std::make_pair(1, i))).get_is_go_through();
		if(is_g_t){
			if((hor_fl.get_cell(std::make_pair(1, i))).get_status() == noevent){
				std::cout << "0";
			}else{
				std::cout<< ((hor_fl.get_cell(std::make_pair(1, i))).get_event())->type();
			}
		}else{
			std::cout << "x";
		}
	}
	/*
	Field& gg = f;
	//f.prt();
	Field g = Field(gg);
	Field l = g;
	Field ll = std::move(l);
	f.prt();
	g.prt();
	l.prt();

	std::cout << "\n\n\n\n" << "testing copying" << '\n';
	Field test_new_field = Field(std::make_pair(20, 20), std::make_pair(5, 5), std::make_pair(15, 15));
	Event* evet_test = new Event("eve1", 1);
	Cell& test_new_cell = test_new_field.get_cell(std::make_pair(0, 0));
	std::cout << "!!!cell (0, 0) of original before\n";
	test_new_cell.prt();
	test_new_cell.get_ptr_event();
	std::cout << "!!!cell (0, 0) of original even changed to  eve1 and 1\n";
	test_new_cell.prt();
	std::cout << "234\n";
	/*
	Field test_copy = std::move(test_new_field);
	/*
	Cell& cell_copy =  test_copy.get_cell(std::make_pair(0, 0));
	std::cout << "!!!cell (0, 0) of copy beginning";
	cell_copy.prt();
	Event* evet_copy = cell_copy.get_event();
	evet_copy->val = 35;
	evet_copy->name = "eve2";
	std::cout << "!!!cell (0, 0) of copy event changed to eve2 and 35\n";
	cell_copy.prt();
	std::cout << "!!!meanwhile cell (0, 0) of original\n";
	test_new_cell.prt();
	*/
	Player plr = Player("Lise", 120);
	Controller cont = Controller(plr);
	cont.prt();
	FieldGenerator gen = FieldGenerator();
	gen.generate_lvl1(cont);
	cont.prt();
	gen.generate_lvl2(cont);
	cont.prt();
	std::cout << "\nProgramm finished!\n";
    return 0;
}
