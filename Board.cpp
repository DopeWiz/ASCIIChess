#include <iostream>
#include "Board.hpp"
#include "state.hpp"


#define W_FG "\u001b[37m"
#define W_BG "\u001b[47m"
#define B_FG "\u001b[30m"
#define B_BG "\u001b[40m"
#define BG_G "\u001b[48;5;243m"


using namespace std;

Board::Board()
{
    for(int i = 2; i<6;i++)
    {
        for(int j = 0; j<8;j++)
        {
            board[i][j].set(' ','N',i,j,false);
        }
    }
    char seq[] = { 'R','N','B', 'Q', 'K', 'B', 'N', 'R'};
    for(int i=0;i<8;i++)
    {
        board[1][i].set('P','B',1,i,true);
        board[6][i].set('P','W',6,i,true);
        board[0][i].set(seq[i],'B',0,i,true);
        board[7][i].set(seq[i],'W',7,i,true);
    }

}

void Board::display()
{
    char bound_ch = '#';
    std::string bg,fg;

    for(int i = 0; i<8;i++)
    {
        cout<<B_FG<<BG_G<<"   "<<std::string(33,bound_ch)<<" "<<endl;
        cout<<" "<<8-i<<" "<<bound_ch;
        for(int j = 0; j<8;j++)
        {
            char col = board[i][j].col();
            if(col == 'W')
            {
                fg = W_FG;
                bg = B_BG;
            }
            else if(col == 'B')
            {
                fg = B_FG;
                bg = W_BG;
            }
            else
            {
                bg = BG_G;
            }
            cout<<fg<<bg<<" "<<board[i][j].id()<<" "<<B_FG<<BG_G<<bound_ch;
        }
        cout<<" "<<endl;
    }
    cout<<"   "<<std::string(33,bound_ch)<<" \n     a   b   c   d   e   f   g   h   "<<"\u001b[0m\t"<<turn<<endl;
    
}

// void Board::move(Peice &p,int x,int y)
// {
// 	if(!p.in_game)
//     {
//         cout<<"Captured!";
//     }
//     if (! p.check_move(board,x,y))
// 	{
// 		cout<<"Error\n";
// 	}
//     // Algorithm for move
//     board[x][y].set(p.id(),p.col());
//     p.set(' ','N');
// }

void Board::move(char id, bool cap,int srank, int sfile,int drank,int dfile)
{
	// cout<<std::boolalpha<<board[srank][sfile].in_game<<endl;
    // cout<<"\n"<<srank<<"\t"<<sfile<<"\t"<<drank<<"\t"<<dfile;
    cout<<"\u001b[3A\u001b[1000D";
    // cout<<"\u001b[1A"
    if(board[srank][sfile].id() == ' ')
    {
        cout<<"Invalid Move.";
        return;
    }
    if(!board[srank][sfile].in_game)
    {
        cout<<"Captured! Not in game.\n";
        return;
    }
    // if (! board[srank][sfile].check_move(board,drank,dfile))
	// {
	// 	cout<<"\nError\n";
    //     return;
	// }
    // Algorithm for move
    cout<<"\u001b[4B";

    board[srank][sfile].move(board[drank][dfile]);

}