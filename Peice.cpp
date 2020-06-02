#include <iostream>
#include "Peice.hpp"


using namespace std;

Peice::Peice()
{
	P_id = ' ';
	P_col = 'N';
	P_pos.first = 0;
	P_pos.second = 0;
}


void Peice::set(char id,char col,int x,int y,bool ig)
{
	P_id = id;
	P_col = col;
	P_pos.first = x;
	P_pos.second = y;
	in_game = ig;
}

void Peice::set(char id,char col, bool ig)
{
	P_id = id;
	P_col = col;
	in_game = ig;
}


bool Peice::check_move(Peice (&b)[8][8],int x,int y)
{
	std::cout<<b[0][0].id();
	return false;
}

Peice Peice::operator=(Peice &p)
{
	char tmp;
	tmp = P_id;
	P_id = p.P_id;
	p.P_id = tmp;
	tmp = P_col;
	P_col = p.P_col;
	p.P_col = tmp;
	return *this;
}

void Peice::capture()
{
	in_game = false;
}

int Peice::move(Peice &p)
{
	// std::pair<int, int> pos = p.pos();
	p.set(P_id,P_col,true);
    set(' ','N',false);

	return 0;
}