#include <iostream>
#include "Peice.hpp"

using namespace std;

Peice::Peice()
{
	P_id = ' ';
	P_col = 'N';
	pos[0] = 0;
	pos[1] = 0;
}


void Peice::set(char id,char col,int x,int y)
{
	P_id = id;
	P_col = col;
	pos[0] = x;
	pos[1] = y;
}


bool Peice::check_move(int x,int y)
{
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