class Peice
{
    // enum class Color { "white", "black", "none" };

    // Color col = "none";
    char P_col;
    char P_id;
    int pos [2];
public:
    Peice();
    void set(char id,char col,int x,int y);
    char id(){ return P_id; }
    bool check_move(int x,int y);

    Peice operator=(Peice &p);
};