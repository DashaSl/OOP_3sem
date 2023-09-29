#include "controller.h"
int main(){
    Player* momo = new Player;
    *momo = Player("Strug", 90);
    momo->print();
    Controller cont = Controller(momo, 2, 2);
    cont.print();
    for(int i = 0; i < 2; i++ ){
        cont.move(right);
        cont.print();
    }

    momo->change_health(-40);
    momo->change_score(25);

    std::cout  << momo->get_name() << " status:" << std::endl;
    std::cout <<"max_health: " << (int)momo->get_max_health() << ", cur_health: "<<(int)momo->get_health() << ", score: "<< (int)momo->get_score() << std::endl;

    Player greg = Player("Greg", 300);
    greg.print();
    Controller cont2 = Controller(&greg, 80, 80);
    cont2.print();

    return 0;
}
