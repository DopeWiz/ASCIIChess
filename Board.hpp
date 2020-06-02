#include "Peice.hpp"
class Board
{
private:
    Peice board [8][8];

public:
    Board();
    void display();
    void move(Peice &p,int x,int y);
    void move(int sx, int sy,int dx,int dy);

    // void display_p();

};