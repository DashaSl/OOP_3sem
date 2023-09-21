#ifndef OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H
#define OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H
#include <iostream>
#include <string>

enum class Move_constant {up, right, down, left};

class Player{
private:
    //характеристики
    int health;
    std::string Players_name;
    int score = 0;

public:
    void change_health(int change);
    void change_score(int change);
    std::string get_name();
    int get_health();
    Player(std::string name = "NoName", int health_start = 30){
        Players_name = name;
        health = health_start;
    }

    //для проверки
    void print();
};

class Controller{

};
#endif //OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H
