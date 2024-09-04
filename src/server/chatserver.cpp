#include "chatserver.hpp"
#include <iostream>
#include <functional>
#include <string>
using namespace std;
using namespace placeholders;

 ChatServer::ChatServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const string &nameArg):_server(loop,listenAddr,nameArg),_loop(loop)
               {
                    _server.setConnectionCallback(bind(&ChatServer::onConnection,this,_1));
                    _server.setMessageCallback(bind(&ChatServer::onMessage,this,_1,_2,_3));
                    _server.setThreadNum(4);
               }


void ChatServer::start()
{
    _server.start();
}

void ChatServer::onConnection(const TcpConnectionPtr &)
{

}
    void ChatServer::onMessage(const TcpConnectionPtr &,
                   Buffer *,
                   Timestamp)
                   {

                   }