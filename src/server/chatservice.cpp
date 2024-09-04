#include "chatservice.hpp"
#include "public.hpp"
#include <muduo/base/Logging.h>
using namespace std;
using namespace muduo;
using namespace placeholders;

ChatService* ChatService::instance()
{
    static ChatService service;
    return &service;
}

void ChatService::login(const TcpConnectionPtr &conn,json &js,Timestamp time)
{
    LOG_INFO << "user login";
}
void ChatService::reg(const TcpConnectionPtr &conn,json &js,Timestamp time)
{
    LOG_INFO << "user reg";
}
MsgHandler ChatService::getHandler(int msgid)
{
    auto it = _msgHandlerMap.find(msgid);
    if(it == _msgHandlerMap.end())
    {
        return [=](const TcpConnectionPtr &conn,json &js,Timestamp time){
            LOG_ERROR << "msgid:" << msgid << " can not find handler!";
        };
    }
    else
    {
        return _msgHandlerMap[msgid];
    }
}
ChatService::ChatService()
{
    _msgHandlerMap.insert({MSG_LOGIN,bind(&ChatService::login,this,_1,_2,_3)});
    _msgHandlerMap.insert({MSG_REG,bind(&ChatService::reg,this,_1,_2,_3)});
}