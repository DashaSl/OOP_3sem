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
	std::cout << "test2 - changing event in the copies\n";

	Field fl_orig = Field(std::make_pair(20, 20), std::make_pair(2, 2), std::make_pair(10, 10));
	Field fl_copy = Field(fl_orig);
	Cell& test_cell = fl_copy.get_cell(std::make_pair(0, 0));
	Event* eve = new Event{"Kanye West is genius\n"};
	test_cell.change_event(eve);
	Cell& orig_cell = fl_orig.get_cell(std::make_pair(0, 0));

	orig_cell.prt();
	test_cell.prt();



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
    return 0;
}
