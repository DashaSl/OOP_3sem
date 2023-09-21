#include "Lab1_player_controller.h"
//ф-я проверки - выводит инфу об игроке
void Player::print(){
    std::cout << "Player: " << Players_name << std::endl;
    std::cout << "Health: " << health <<", " << "score: " << score << std::endl;
};


//ф-и изменения здоровья и счёта
void Player::change_health(int change){
    if(health + change <= 0){
        //end of game - turn off
        health = 0; //
        std::cout << "You'r dead" << std::endl;
    }else{
        health += change;
    }
};

void Player::change_score(int change){
    score += change;
};

//
std::string Player::get_name(){
    return Players_name;
};
int Player::get_health(){
    return health;
};