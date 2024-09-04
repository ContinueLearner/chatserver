#include "chatserver.hpp"
#include "chatservice.hpp"
#include<iostream>
using namespace std;

int main()
{
    EventLoop loop;
    InetAddress addr("127.0.0.1",6000);
    ChatServer server(&loop,addr,"chatserver");

    server.start();
    loop.loop();

    return 0;
}