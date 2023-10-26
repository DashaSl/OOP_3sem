#include "fieldgenerator.h"

FieldGenerator::FieldGenerator(){}

Field FieldGenerator::generate_lvl1(){
	Field ans = Field(std::make_pair(LVL1_W,LVL1_H), std::make_pair(0, 0), std::make_pair(LVL1_W - 1, LVL1_H - 1));
	Event* eve;
	int bad_ind, good_ind, telep_ind, noeve_ind;
	for(int y = 1; y < LVL1_H; y+=2){
		for(int x = 0; x < LVL1_W; x++){
			ans.get_cell(std::make_pair(x, y)).change_is_go_through(false);
		}


		bad_ind = std::rand() % LVL1_W;
		do{
			good_ind = std::rand() % LVL1_W;
		}while(good_ind == bad_ind);
		do{
			telep_ind = std::rand() % LVL1_W;
		}while(telep_ind == bad_ind || telep_ind == good_ind);
		do{
			noeve_ind = std::rand() % LVL1_W;
		}while(noeve_ind == bad_ind || noeve_ind == good_ind || noeve_ind == telep_ind);

		eve = new BadEvent{};
		ans.get_cell(std::make_pair(bad_ind, y)).change_is_go_through(true);
		ans.get_cell(std::make_pair(bad_ind, y)).change_event(eve);

		eve = new GoodEvent{};
		ans.get_cell(std::make_pair(good_ind, y)).change_is_go_through(true);
		ans.get_cell(std::make_pair(good_ind, y)).change_event(eve);

		eve = new TeleportEvent{};
		ans.get_cell(std::make_pair(telep_ind, y)).change_is_go_through(true);
		ans.get_cell(std::make_pair(telep_ind, y)).change_event(eve);

		ans.get_cell(std::make_pair(noeve_ind, y)).change_is_go_through(true);
	}
	return ans;
}

Field FieldGenerator::generate_lvl2(){
	Field ans = Field(std::make_pair(LVL2_W,LVL2_H), std::make_pair(0, 0), std::make_pair(LVL1_W - 1, LVL1_H - 1));
	Event* eve;
	int bad_ind, good_ind, telep_ind, noeve_ind;
	for(int x = 1; x < LVL2_W; x+=2){
		for(int y = 0; y < LVL2_H; y++){
			ans.get_cell(std::make_pair(x, y)).change_is_go_through(false);
		}


		bad_ind = std::rand() % LVL2_H;
		do{
			good_ind = std::rand() % LVL2_H;
		}while(good_ind == bad_ind);
		do{
			telep_ind = std::rand() % LVL2_H;
		}while(telep_ind == bad_ind || telep_ind == good_ind);
		do{
			noeve_ind = std::rand() % LVL2_H;
		}while(noeve_ind == bad_ind || noeve_ind == good_ind || noeve_ind == telep_ind);

		eve = new BadEvent{};
		ans.get_cell(std::make_pair(x, bad_ind)).change_is_go_through(true);
		ans.get_cell(std::make_pair(x, bad_ind)).change_event(eve);

		eve = new GoodEvent{};
		ans.get_cell(std::make_pair(x, good_ind)).change_is_go_through(true);
		ans.get_cell(std::make_pair(x, good_ind)).change_event(eve);

		eve = new TeleportEvent{};
		ans.get_cell(std::make_pair(x, telep_ind)).change_is_go_through(true);
		ans.get_cell(std::make_pair(x, telep_ind)).change_event(eve);

		ans.get_cell(std::make_pair(x, noeve_ind)).change_is_go_through(true);
	}
	return ans;
}
