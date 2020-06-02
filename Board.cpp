#include <iostream>
#include "Board.hpp"

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
    for(int i = 0; i<8;i++)
    {
        cout<<"................................."<<endl;
        cout<<".";
        for(int j = 0; j<8;j++)
        {
            cout<<" "<<board[i][j].id()<<" "<<'.';
        }
        cout<<endl;
    }
    cout<<"................................."<<endl;
    
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

void Board::move(int sx, int sy,int dx,int dy)
{
	if(!board[sx][sy].in_game)
    {
        cout<<"Captured!\n";
        return;
    }
    if (! board[sx][sy].check_move(board,dx,dy))
	{
		cout<<"Error\n";
        return;
	}
    // Algorithm for move
    board[sx][sy].move(board[dx][dy]);
}