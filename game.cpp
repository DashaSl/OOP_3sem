#include "game.h"

Game::Game(GameMover* rd, std::string name, int lvl){
	read = rd;

	uint8_t hp = MIN_HEALTH + std::rand()%(MAX_HEALTH-MIN_HEALTH);
	player = new Player{name, hp};
	controller = new Controller();
	if(lvl%2){
		gen.generate_lvl1(*controller, *player);
	}else{
		gen.generate_lvl2(*controller, *player);
	}
	std::cout << "You are " << player->get_name() << " hp: " << (int)player->get_max_health() << '\n';
	std::cout << "YOUR FIELD :\n";
	controller->prt();
}

Game::~Game(){
	delete this->player;
	delete this->controller;
}

bool Game::is_alive(){
	if(player->get_health() != 0) return true;
	return 0;
}

bool Game::is_finish(){
	std::pair<uint8_t, uint8_t> tmp1 = controller->get_field()->get_finish();
	std::pair<uint8_t, uint8_t> tmp2 = controller->get_cord();
	if(tmp1.first == tmp2.first && tmp1.second == tmp2.second) return true;
	return false;
}

void Game::start_new(std::string name, int lvl){
	uint8_t hp = MIN_HEALTH + std::rand()%(MAX_HEALTH-MIN_HEALTH);
	delete this->player;
	player = new Player{name, hp};
	delete this->controller;
	controller = new Controller();
	if(lvl%2){
		gen.generate_lvl1(*controller, *player);
	}else{
		gen.generate_lvl2(*controller, *player);
	}
	std::cout << "new!" << std::endl;
	std::cout << "You are " << player->get_name() << " hp: " << (int)player->get_max_health() << '\n';
	std::cout << "YOUR FIELD :\n";
	controller->prt();
}
void Game::end_programm(){
	exit(1);
}

int Game::run(){
	char c;
	std::string new_name;
	int lvl;
	controller->prt();
	while(c != 'z' && !this->is_finish() && this->is_alive()){
		c = read->key_operator();
		switch(c){
			case 'w':
				controller->move(up);
				controller->prt2();
				break;
			case 'd':
				controller->move(right);
				controller->prt2();
				break;
			case 's':
				controller->move(down);
				controller->prt2();
				break;
			case 'a':
				controller->move(left);
				controller->prt2();
				break;
			case 'q':
				this->end_programm();
				break;
			case 'e':
				std::cout << "Введите новое имя: ";
				std::cin >> new_name;
				std::cout << '\n';
				std::cout << "Введите новый уровень: ";
				std::cin >> lvl;
				std::cout << '\n';
				this->start_new(new_name, lvl);
				break;
			default:
				break;
		}
	}
	if(this->is_finish()) return 2;
	if(!this->is_alive()) return 1;
	return 0;

}


