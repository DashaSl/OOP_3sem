#include "game.h"

Game::Game(std::string name, std::string path){
	if(path != ""){
		read.stream_change(path);
	}

	uint8_t hp = MIN_HEALTH + std::rand()%(MAX_HEALTH-MIN_HEALTH);
	player = Player(name, hp);
	controller = Controller();
	gen.generate_lvl(controller, player);
	std::cout << "You are " << player.get_name() << " hp: " << (int)player.get_max_health() << '\n';
	std::cout << "YOUR FIELD :\n";
	controller.prt();
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
	player = Player(name, hp);
	controller = Controller();
	gen.generate_lvl(controller, player);
	std::cout << "new!" << std::endl;
	std::cout << "You are " << player.get_name() << " hp: " << (int)player.get_max_health() << '\n';
	std::cout << "YOUR FIELD :\n";
	controller.prt();
}

int Game::run(){
	char c = '2';
	std::string new_name;
	int lvl;
	controller.prt2();
	while(c != 'q' && !this->is_finish() && this->is_alive()){
		c = read.key_operator();
		switch(c){
			case 'w':
				std::cout << "there is no turning back!\n";
				//controller.move(up);
				player.print();
				controller.prt2();
				break;
			case 'd':
				controller.move(right);
				player.print();
				controller.prt2();
				break;
			case 's':
				controller.move(down);
				player.print();
				controller.prt2();
				break;
			case 'a':
				controller.move(left);
				player.print();
				controller.prt2();
				break;
			case 'e':
				std::cout << "Введите новое имя: ";
				std::cin >> new_name;
				std::cout << '\n';
				this->start_new(new_name);
				break;
			default:
				break;
		}
	}
	if(this->is_finish()) return 2;
	if(!this->is_alive()) return 1;
	return 0;

}
/*
void Game::change_stream(){
	if(read_ex == nullptr){
		std::cout << "No extra stream was given.\n";
	}else{
		GameMover* tmp = read;
		read = read_ex;
		read_ex = tmp;
	}
}*/


