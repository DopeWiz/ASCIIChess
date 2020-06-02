#include "Peice.hpp"
class Board
{
private:
    Peice board [8][8];

public:
    Board();
    void display();
    void move(Peice &p,int x,int y);

    // void display_p();

};