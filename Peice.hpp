#include <vector> 

typedef std::vector  <std::pair <int,int>> pos_list;
typedef std::pair <int,int> pos_pair;

class Peice
{
    char P_col;
    char P_id;
    pos_pair P_pos;
    pos_list avail_moves;

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