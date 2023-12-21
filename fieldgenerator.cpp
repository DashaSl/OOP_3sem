#include "fieldgenerator.h"
#include "controller.h"
#include "enemy.h"

void FieldGenerator::generate_lvl(Controller& cont, Player& plr){
	Field* ans = new Field{std::make_pair(LVL1_W,LVL1_H), std::make_pair(0, 0), std::make_pair(LVL1_W - 1, LVL1_H - 1)};
	Event* eve;
	int bad_ind, good_ind, telep_ind, noeve_ind;
	for(int y = 1; y < LVL1_H; y+=2){
		for(int x = 0; x < LVL1_W; x++){
			ans->get_cell(std::make_pair(x, y)).change_is_go_through(false);
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

		eve = new BadEvent{cont, plr};
		ans->get_cell(std::make_pair(bad_ind, y)).change_is_go_through(true);
		ans->get_cell(std::make_pair(bad_ind, y)).change_event(eve);

		eve = new GoodEvent{cont, plr};
		ans->get_cell(std::make_pair(good_ind, y)).change_is_go_through(true);
		ans->get_cell(std::make_pair(good_ind, y)).change_event(eve);

		eve = new TeleportEvent{cont, plr};
		ans->get_cell(std::make_pair(telep_ind, y)).change_is_go_through(true);
		ans->get_cell(std::make_pair(telep_ind, y)).change_event(eve);

		ans->get_cell(std::make_pair(noeve_ind, y)).change_is_go_through(true);
	}
	eve = nullptr;
	std::pair<uint8_t, uint8_t> cord_enem1 = std::make_pair(7, 7);
	std::pair<uint8_t, uint8_t> cord_enem2 = std::make_pair(3, 8);
	BaseEnemy* enem1 = new Enemy(cord_enem1, plr, cont, MovementRandom(), InteractionHp());
	BaseEnemy* enem2 = new Enemy(cord_enem2, plr, cont, MovementStalker(),  InteractionTeleport());
	ans->add_enemy(enem1);
	ans->add_enemy(enem2);
	cont.change_field(ans);
	ans = nullptr;
}
//стирание типов в c++ ||убрать BaseEnemy
void FieldGenerator::generate_lvl2(Controller& cont, Player& plr){
	Field* ans = new Field{std::make_pair(LVL2_W,LVL2_H), std::make_pair(0, 0), std::make_pair(LVL2_W - 1, LVL2_H - 1)};
	Event* eve;
	int bad_ind, good_ind, telep_ind, noeve_ind;
	for(int y = 1; y < LVL2_H; y+=2){
		for(int x = 0; x < LVL1_W; x++){
			ans->get_cell(std::make_pair(x, y)).change_is_go_through(false);
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

		eve = new BadEvent{cont, plr};
		ans->get_cell(std::make_pair(bad_ind, y)).change_is_go_through(true);
		ans->get_cell(std::make_pair(bad_ind, y)).change_event(eve);

		eve = new GoodEvent{cont, plr};
		ans->get_cell(std::make_pair(good_ind, y)).change_is_go_through(true);
		ans->get_cell(std::make_pair(good_ind, y)).change_event(eve);

		eve = new TeleportEvent{cont, plr};
		ans->get_cell(std::make_pair(telep_ind, y)).change_is_go_through(true);
		ans->get_cell(std::make_pair(telep_ind, y)).change_event(eve);

		ans->get_cell(std::make_pair(noeve_ind, y)).change_is_go_through(true);
	}
	eve = nullptr;
	std::pair<uint8_t, uint8_t> cord_enem1 = std::make_pair(7, 14);
	std::pair<uint8_t, uint8_t> cord_enem2 = std::make_pair(3, 8);
	std::pair<uint8_t, uint8_t> cord_enem3 = std::make_pair(13, 2);
	std::pair<uint8_t, uint8_t> cord_enem4 = std::make_pair(1, 18);
	BaseEnemy* enem1 = new Enemy(cord_enem1, plr, cont, MovementRandom(), InteractionHp());
	BaseEnemy* enem2 = new Enemy(cord_enem2, plr, cont, MovementStalker(),  InteractionTeleport());
	BaseEnemy* enem3 = new Enemy(cord_enem3, plr, cont, MovementRandom(), InteractionTeleport());
	BaseEnemy* enem4 = new Enemy(cord_enem4, plr, cont, MovementStalker(),  InteractionHp());
	ans->add_enemy(enem1);
	ans->add_enemy(enem2);
	ans->add_enemy(enem3);
	ans->add_enemy(enem4);
	cont.change_field(ans);
	ans = nullptr;
}
