#include "player.h"

Player::Player(std::string name, int max) {
    Players_name = name;
    if(max > MAX_HEALTH || max < MIN_HEALTH){
        std::cout << "error: input maximum possible health out of range! Expect it to be 100!" <<std::endl;
        max = MID_HEALTH;
    }
    //на старте игры полное здоровье
    max_health = max;
    health = max_health;
    score = 0;
}

void Player::print(){
    std::cout << "player: " << Players_name;
    std::cout << " health: " << (int) health <<", " << "score: " << score << std::endl;
};

//сеттеры
void Player::change_health(int change){
    //чейндж может быть и отр и пол, в завис от того, убыв ли здор или нет
    if(change + health > max_health){
        health = max_health;
    }else if(change+health < 0){
        health = 0;
    }else{
        health += change;
    }
};


void Player::change_health_val(uint8_t change){
	if(change > max_health){
		health = max_health;
	}else{
		health = change;
	}
}
void Player::change_score_val(uint16_t change){
	score = change;
}

void Player::change_score(uint16_t change){
    score += change;
};

//геттеры
std::string Player::get_name(){
    return Players_name;
};
uint8_t Player::get_health(){
    return health;
};

uint16_t Player::get_score(){
    return score;
}

uint8_t Player::get_max_health(){
    return max_health;
}
void Player::change_max_health(uint8_t new_health_max){
	max_health = new_health_max;
	health = max_health;
}
void Player::change_name(std::string new_name){
	Players_name = new_name;
}
