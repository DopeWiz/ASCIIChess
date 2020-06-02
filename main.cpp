#include <iostream>
#include <cstring>
#include "Board.hpp"

// #include "Peice.hpp"

using namespace std;

bool input_handler();

int main(int argc, char const *argv[])
{
    // system("clear");
    bool running = true;
    Board b;
    while(running)
    {
        system("clear");
        b.display();
        if (!input_handler())
        {
            running = false;
        }
    }
    
    return 0;
}

bool input_handler()
{
    char response[100];
    // char exit_cmd[] = "exit";
    cout<<":>>";
    cin >>  response;
    // cout << "\n" <<respose;
    // cout << "\n" <<exit_cmd;
    
    if(! (bool) strcmp(response,"exit"))
    {
        // cout<<"exitting";
        return false;
    }

    return true;
}