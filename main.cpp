#include <iostream>
#include <cstring>
#include <regex>
#include <unistd.h>
#include "Board.hpp"
#include "state.hpp"

using namespace std;

int turn;
bool input_handler(Board &b);
void regex_handler(Board &b, string &resp);
void print(const std::string &s);

int main(int argc, char const *argv[])
{
    system("clear");
    turn = 1;
    bool running = true;
    Board b;
    while(running)
    {
        cout << "\u001b[1000A\u001b[1000D";
        b.display();
        if (!input_handler(b))
        {
            running = false;
        }
    }

    return 0;
}

bool input_handler(Board &b)
{
    std::string response;
    char c;
    cout<<endl<<endl<<endl<<":>>";
    while(cin.read(&c,1))
    {
        
        if(c == '\n')
        {
            response.push_back('\0');
            cout<<"\u001b[1A";
            cout<<"\u001b[2K\n";
            break;
        }
        // if(c == 3)
        // {
        //     cout<<"Exitting...";
        //     sleep(2);
        //     return false;
        // }
        response.push_back(c);
    }
    if(! (bool) response.compare("exit\0"))
    {
        return false;
    }
    cout<<"\u001b[0K"; //<<response;
    // print(response);
    regex_handler(b,response); 
    return true;
}

void print(const std::string &s)
{
    std::for_each(s.begin(), s.end(), [] (char const &c) {
        std::cout << std::hex << (unsigned int)c << ' ';
    });
}
void regex_handler(Board &b, string &resp)
{
    int sf = -1, sr = -1, df = -1, dr = -1;
    bool cap = false;
    char id = ' ';

    // std::regex reg_ex_cap ("^([RNKQB]|[a-h]?)x([a-h])([1-8])\\0$"); // CAPTURE
    std::regex reg_ex_mov ("^([RNKQB]?)([a-h]?)([1-8]?)(x?)([a-h])([1-8])\\0$");     // MOVE
    std::smatch match;
    bool success = false;
    if(std::regex_search(resp,match,reg_ex_mov))
    {
        success = true;
        cout<<"\u001b[0K";
        for(int i=1;i<=6;i++)
        {
            cout<<i<<":"<<match[i]<<"\t"; //<<std::boolalpha<<match.length(i)<<"\t";
        }
        if(match.length(1) > 0) id = *match.str(1).c_str();
        if(match.length(2) > 0) sf = *match.str(2).c_str()-97;
        if(match.length(3) > 0) sr = 8 - stoi(match[3]);
        if(match.length(5) > 0) df = *match.str(5).c_str()-97;
        if(match.length(6) > 0) dr = 8 - stoi(match[6]);
        if(match.length(4) > 0) cap = true;
        b.move(id,cap,sr,sf,dr,df);
        // cout<<endl<<sr<<"\t"<<sf<<"\t"<<dr<<"\t"<<df<<"\t"<<cap<<"\t"<<id;
        turn = turn==1? 0 : 1;
        return;
    }

    if(!success)
    {
        cout<<"\u001b[0K"<<"Error: Unable to parse input.";
    }
    return;
}