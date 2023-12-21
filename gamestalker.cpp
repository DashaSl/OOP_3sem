#include "gamestalker.h"
//teleport event - 3, bad event - 2, good event - 1 => no event = 0


void GameStalker::update_lvl(){
	int type;
	if(cur_level == 2){
		for(int y = 1; y < LVL2_H; y+=2){
			//finding events cords
			for(int x = 0; x < LVL2_W; x++){

				Cell& checking_cell = game.get_controller().get_field()->get_cell(std::make_pair(x, y));
				if(checking_cell.get_is_go_through()){
					if(checking_cell.get_status() == noevent){
						level_2_event_placement[y/2][0] = x;
					}else{
						type = checking_cell.get_event()->type();
						level_2_event_placement[y/2][type] = x;
					}
				}

			}
			//found events cords in this

		}
	}else{
		for(int y = 1; y < LVL1_H; y+=2){
					//finding events cords
			for(int x = 0; x < LVL1_W; x++){

				Cell& checking_cell = game.get_controller().get_field()->get_cell(std::make_pair(x, y));

				if(checking_cell.get_is_go_through()){

					if(checking_cell.get_status() == noevent){
						level_1_event_placement[y/2][0] = x;
					}else{
						type = checking_cell.get_event()->type();
						level_1_event_placement[y/2][type] = x;
					}
				}

			}


		}
	}
}




GameStalker::GameStalker(Game& gm, Drawer& drw, MessageSend& mes) : game(gm), draw(drw), messend(mes){
	cur_level = game.get_level();

	this->update_lvl();

	end = not_yet;
	player_name = game.get_player().get_name();
	max_health = game.get_player().get_max_health();
	cur_health = game.get_player().get_health();
	cur_score = game.get_player().get_score();
	cur_cords = game.get_controller().get_cord();
	width = game.get_controller().get_width();
	height = game.get_controller().get_height();
}


bool GameStalker::check_cords(Move_constant c){
	if(c > 2) return false;
	int y_cord = cur_cords.second;
	int x_cord = cur_cords.first;
	if(c%2){
		if(y_cord + c >= height || y_cord + c < 0){
			return false;
		}
		cur_cords.second += c;
	}else{
		if(x_cord + c > width || x_cord + c <= 0){
			return false;
		}
		cur_cords.first += c - 1;
	}
	return true;
}

std::string GameStalker::start_info(Move_constant c, char symb){
	if(symb == '\n') return "";
	if(c == no){
		EventMessageFailMove emfm = EventMessageFailMove(symb);
		messend.output_message(emfm);
		return "";
	}
	EventMessageMove emm = EventMessageMove(symb, c);
	messend.output_message(emm);
	std::string ans;
	if(c == quit){
		while(ans != "y" && ans != "n"){
			std::cout << "Are you sure?\n(y/n)\n";
			std::cin >> ans;
			if(ans.size() > 1 || ans.size() < 1) std::cout << "Too many/not enough letters!\n";
			if(ans != "n" && ans != "y" && ans.size() == 1) std::cout << "Wrong letter!\n";
		}

		if(ans == "n") return "n";
		end = quitted;
		return "y";

	}
	if(c == news){
		std::cout << "Write new name: ";
		std::cin >> ans;
		player_name = ans;
		return ans;
	}

	bool cord_change = this->check_cords(c);

	if(!cord_change){
		std::cout << "You can't move there!\n";
	}else{
		int x = cur_cords.first;
		int y = cur_cords.second;
		Cell& checking_cell = game.get_controller().get_field()->get_cell(std::make_pair(x, y));
		if(!checking_cell.get_is_go_through()){
			std::cout << "You can't move there!\n";
		}
		if(checking_cell.get_status() == event){
			std::string event_name =  checking_cell.get_event()->to_string();
			std::cout << event_name << " has happened!\n";
		}
	}
	return "";

}






std::string GameStalker::win_death_case(status stat){
	std::string ans = "";
	if(stat == killed){
		EventMessageDead emd = EventMessageDead(game.get_controller());
		messend.output_message(emd);
		while(ans != "y" && ans != "n"){
			std::cout << "Want to start again?\n(y/n)\n";
			std::cin >> ans;
			if(ans.size() > 1 || ans.size() < 1) std::cout << "Too many/not enough letters!\n";
			if(ans != "n" && ans != "y" && ans.size() == 1) std::cout << "Wrong letter!\n";
		}
		if(ans == "y") return "y";
		end = dead;
		return "n";
	}

	if(stat == win_lvl2){
		EventMessageWin emw = EventMessageWin(game.get_player());
		messend.output_message(emw);
		while(ans != "y" && ans != "n"){
			std::cout << "You won. Want to start new?\n(y/n)\n";
			std::cin >> ans;
			if(ans.size() > 1 || ans.size() < 1) std::cout << "Too many/not enough letters!\n";
			if(ans != "n" && ans != "y" && ans.size() == 1) std::cout << "Wrong letter!\n";
		}
		if(ans == "y"){
			std::cout << "Enter new name: ";
			std::cin >> ans;
			ans = "y" + ans;
			return ans;
		}
		end = win;
		return "n";
	}
	return "";
}

void GameStalker::get_info(Move_constant c, end_of_cycle eoc){
	if(c == no) return;
	cur_health = game.get_player().get_health();
	cur_score = game.get_player().get_score();
	cur_cords = game.get_controller().get_cord();
	if(cur_level != game.get_level() || eoc == next_level || eoc == started_new){
		width = game.get_controller().get_width();
		height = game.get_controller().get_height();
		cur_level = game.get_level();
		this->update_lvl();
	}

	if(eoc == started_new){
		player_name = game.get_player().get_name();
		max_health = game.get_player().get_max_health();
		EventMessageNew emn = EventMessageNew(game.get_controller());
		messend.output_message(emn);
	}


	draw.draw(game.get_controller(), game.get_player());
}


void GameStalker::prt_info(){
	std::cout << "You are " << player_name << "\n";
	std::cout << "Max health: " <<(int) max_health << "Current health: " <<(int) cur_health << "\n";
	std::cout << "Yours score: " << (int) cur_score << "\n";

	std::cout << "You are at level " << cur_level << "\n";

	if(cur_level == 1){
		std::cout << "Cords of:\n no, good, bad, teleport events\n";
		for(int i = 0; i < LVL1_H/2; i++){
			for(int j = 0; j < 4; j++){
				std::cout << level_1_event_placement[i][j] << " ";
			}
			std::cout << "\n";
		}
	}else{
		std::cout << "Cords of:\n no, good, bad, teleport events\n";
		for(int i = 0; i < LVL2_H/2; i++){
			for(int j = 0; j < 4; j++){
				std::cout << level_2_event_placement[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	std::cout << "Your current cords: " << (int) cur_cords.first << ", " << (int) cur_cords.second << "\n";
}



