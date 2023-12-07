#include "drawer.h"
#include "player.h"
#include "controller.h"


void Drawer::draw(Controller& cont, Player& plr){
	std::cout << plr.get_name() << " health: " << (int)plr.get_health() << "/" << (int)plr.get_max_health() << " score: " << (int)plr.get_score() << std::endl;

	int x_player = cont.get_cord().first;
	int y_player = cont.get_cord().second;

	int width = cont.get_width();
	int height = cont.get_height();

	for(int i = 0; i < width+1; i++){
			std::cout <<"--";
		}
		std::cout << '\n';
		for(int i = 0; i < height; i++){
			std::cout << "-";
			for(int j = 0; j < width; j++){
				if(i == y_player && j == x_player){
					std::cout << "@@";
				}else{
					if(cont.check_through_cell(j, i)){
						std::cout << "  ";
					}else{
						std::cout << "||";
				}
				}
			}
			std::cout << "-" <<std::endl;
		}

		for(int i = 0; i < width+1; i++){
			std::cout <<"--";
		}
		std::cout << '\n';
}
