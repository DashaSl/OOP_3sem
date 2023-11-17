#ifndef OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H
#define OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H

#ifndef BASIC
#define BASIC
#include <iostream>
#include <string>
#include <cstdint>
#endif
#define MAX_HEALTH 150
#define MID_HEALTH 100
#define MIN_HEALTH 70

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
    void change_max_health(uint8_t new_max_health);
    void change_name(std::string new_name);

    //геттеры
    std::string get_name();
    uint8_t get_health();
    uint8_t get_max_health();
    uint16_t get_score();
    Player(std::string name = "Noname", int max = MID_HEALTH);
    void print();
};

#endif //OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H





