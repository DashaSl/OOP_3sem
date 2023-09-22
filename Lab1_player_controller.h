#ifndef OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H
#define OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H
#include <iostream>
#include <string>

enum Move_constant {up, right, down, left};

class Player{
private:
    //характеристики
    int health = 0;
    std::string Players_name;
    int score = 0;
public:
    void change_health(int change);
    void change_score(int change);
    void change_name(std::string name);
    std::string get_name();
    int get_health();
    int get_score();
    Player(std::string name = "Noname"){
        Players_name = name;
    }
    void print();
};

class Controller{
private:
    Player character;
public:
    Controller(std::string name, int health_start) {
        character.change_name(name);
        character.change_health(health_start);
    }
    void print();
};
#endif //OOP_3SEM_PROJECT_LAB1_PLAYER_CONTROLLER_H


//на два c .h
//не задавать параметры в объявлении
//проверка значенинй в конструкторе (проверка здоровья)
//реализация перемещения коорд. и метод взаим
//не поле а ссылка на игррока
//переделать отчёт