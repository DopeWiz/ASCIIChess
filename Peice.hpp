#include <vector> 

class Peice
{
    char P_col;
    char P_id;
    std::pair <int,int> P_pos;
    std::vector  <std::pair <int,int>> avail_moves;

public:
    bool in_game;
    
    Peice();
    void set(char id,char col,int x,int y,bool ig);
    void set(char id,char col, bool ig);
    char id(){ return P_id; }
    char col(){ return P_col; }
    std::pair <int,int> pos(){ return P_pos; };
    int move(Peice &p);
    bool check_move(Peice (&b)[8][8],int x,int y);
    void capture();

    Peice operator=(Peice &p);
};