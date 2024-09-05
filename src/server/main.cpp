#include "chatserver.hpp"
#include "chatservice.hpp"
#include<iostream>
#include<signal.h>
using namespace std;

void resetHandler(int)
{
    ChatService::instance()->reset();
    exit(0);
}

int main()
{
    signal(SIGINT,resetHandler);
    EventLoop loop;
    InetAddress addr("127.0.0.1",6000);
    ChatServer server(&loop,addr,"chatserver");

    server.start();
    loop.loop();

    return 0;
}