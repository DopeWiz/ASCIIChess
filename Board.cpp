#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board()
{
    for(int i = 2; i<6;i++)
    {
        for(int j = 0; j<8;j++)
        {
            board[i][j].set(' ','N',i,j);
        }
    }
    char seq[] = { 'R','N','B', 'Q', 'K', 'B', 'N', 'R'};
    for(int i=0;i<8;i++)
    {
        board[1][i].set('P','B',1,i);
        board[6][i].set('P','W',6,i);
        board[0][i].set(seq[i],'B',0,i);
        board[7][i].set(seq[i],'W',7,i);
    }

}

void Board::display()
{
    for(int i = 0; i<8;i++)
    {
        cout<<"................................."<<endl;
        // cout<<"#################################"<<endl;
        cout<<".";
        for(int j = 0; j<8;j++)
        {
            cout<<" "<<board[i][j].id()<<" "<<'.';
        }
        cout<<endl;
    }
    // cout<<"#################################"<<endl;
    cout<<"................................."<<endl;
    
}

void Board::move(Peice &p,int x,int y)
{
	if (! p.check_move(x,y))
	{
		cout<<"Error\n";
	}
}