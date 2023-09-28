#include "controller.h"
int main(){
    Player* momo = new Player;
    *momo = Player("Strug", 90);
    momo->print();
    Controller cont = Controller(momo, 10, 10);
    cont.print();
    cont.move(down);
    cont.print();
    cont.move(left);
    cont.print();
    return 0;
}
