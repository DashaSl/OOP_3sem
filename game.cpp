#include "game.h"
#include "gamestalker.h"
Game::Game(Stream& rd, std::string name): read(rd){
	level = 1;
	uint8_t hp = MIN_HEALTH + std::rand()%(MAX_HEALTH-MIN_HEALTH);
	player = Player(name, hp);
	controller = Controller();
	gen.generate_lvl(controller, player);
	beg_level_health = player.get_health();
	beg_level_score = player.get_score();
}


bool Game::is_alive(){
	if(player.get_health() != 0) return true;
	return 0;
}

bool Game::is_finish(){
	std::pair<uint8_t, uint8_t> tmp1 = controller.get_field()->get_finish();
	std::pair<uint8_t, uint8_t> tmp2 = controller.get_cord();
	if(tmp1.first == tmp2.first && tmp1.second == tmp2.second) return true;
	return false;
}


void Game::start_new(std::string name){
	uint8_t hp = MIN_HEALTH + std::rand()%(MAX_HEALTH-MIN_HEALTH);
	player.change_name(name);
	player.change_max_health(hp);
	gen.generate_lvl(controller, player);
	level = 1;
}

void Game::restore_game(){
	return;
}

void Game::start_again(){
	controller.change_cords(0, 0); // go to start
	player.change_health_val(beg_level_health); //to heal completely
	player.change_score_val(beg_level_score);
}

int Game::run(GameStalker& gmstkr){
	Move_constant c = no;
	controller.prt2();
	bool not_finish_of_lvl_2 = true;
	std::string ans_from_stalker = "";

	end_of_cycle endofcyc = nothing_new;

	while(c != quit && not_finish_of_lvl_2 && this->is_alive()){
		c = read.key_operator();
		ans_from_stalker = gmstkr.start_info(c);
		endofcyc = nothing_new;
		switch(c){
			case up:
				break;
			case quit:
				if(ans_from_stalker == "n") c = no;
				break;
			case no:
				break;
			case news:
				this->start_new(ans_from_stalker);
				endofcyc = started_new;
				break;
			default:
				controller.move(c);
				break;
		}

		if(this->is_finish() && level == 1){
			level = 2;
			gen.generate_lvl2(controller, player);
			beg_level_health = player.get_health();
			beg_level_score = player.get_score();
			endofcyc = next_level;
		}else if(this->is_finish() && level == 2){
			ans_from_stalker = gmstkr.win_death_case(win_lvl2);
			if(ans_from_stalker[0] == 'y'){
				this->start_new(ans_from_stalker.substr(1));
				endofcyc = started_new;
			}else{
				not_finish_of_lvl_2 = false;
			}
		}else if(!this->is_alive() ){
			ans_from_stalker = gmstkr.win_death_case(killed);
			if(ans_from_stalker == "y"){
				this->start_again();
			}
		}

		gmstkr.get_info(c, endofcyc);

	}
	if(!this->is_alive()) return 2;
	if(this->is_finish()) return 1;
	return 0;

}

Controller& Game::get_controller(){
	return this->controller;
}

Player& Game::get_player(){
	return this->player;
}

std::pair<uint8_t, uint8_t> Game::get_cur_cords(){
	std::pair<uint8_t, uint8_t> tmp = controller.get_cord();
	return tmp;
}

int Game::get_level(){
	return level;
}





