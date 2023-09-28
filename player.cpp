#include "player.h"


void Player::print(){
    std::cout << "Player: " << Players_name << std::endl;
    std::cout << "Health: " << (int) health <<", " << "score: " << score << std::endl;
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