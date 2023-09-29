#ifndef OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H
#define OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H

#include <iostream>
#include <string>
class Player{
private: //характеристики
    //здоровье макс 250.
    uint8_t health;
    uint8_t max_health;
    //имя игрока
    std::string Players_name;
    //счёт
    uint16_t score;
public:
    //сеттеры
    void change_health(int change);
    void change_score(uint16_t change);

    //геттеры
    std::string get_name();
    uint8_t get_health();
    uint8_t get_max_health();
    uint16_t get_score();
    Player(std::string name = "Noname", int max = 150){
        Players_name = name;
        if(max > 255 || max < 1){
            std::cout << "error: input maximum possible health out of range! Expect it to be 150!" <<std::endl;
            max = 150;
        }
        //на старте игры полное здоровье
        max_health = max;
        health = max_health;
        score = 0;
    }
    void print();
};

#endif //OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H





