#include <iostream>
#include <cstring>
#include <regex>
#include "Board.hpp"

// #include "Peice.hpp"

using namespace std;

bool input_handler(Board &b);

int main(int argc, char const *argv[])
{
    // system("clear");
    bool running = true;
    Board b;
    while(running)
    {
        system("clear");
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
    char response[100];
    cout<<":>>";
    cin >>  response;
    if(!cin)
    {
        cout<<"\nASS\n";
        return false;
    }
    
    if(! (bool) strcmp(response,"exit"))
    {
        return false;
    }
    b.move(7,1,3,1);

    return true;
}