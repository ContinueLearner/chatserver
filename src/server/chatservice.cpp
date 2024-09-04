#include "chatservice.hpp"
#include "public.hpp"
#include "usermodel.hpp"
#include <muduo/base/Logging.h>
using namespace std;
using namespace muduo;
using namespace placeholders;

ChatService *ChatService::instance()
{
    static ChatService service;
    return &service;
}

void ChatService::login(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    LOG_INFO << "user login";
}
void ChatService::reg(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    string name = js["name"];
    string pwd = js["password"];

    User user;
    user.setName(name);
    user.setPwd(pwd);

    bool state = _userModel.insert(user);
    if (state)
    {
        json response;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 0;
        response["id"] = user.getId();
        conn->send(response.dump());
    }
    else
    {
        json response;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 1;
        conn->send(response.dump());
    }
}
MsgHandler ChatService::getHandler(int msgid)
{
    auto it = _msgHandlerMap.find(msgid);
    if (it == _msgHandlerMap.end())
    {
        return [=](const TcpConnectionPtr &conn, json &js, Timestamp time)
        {
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
    _msgHandlerMap.insert({MSG_LOGIN, bind(&ChatService::login, this, _1, _2, _3)});
    _msgHandlerMap.insert({MSG_REG, bind(&ChatService::reg, this, _1, _2, _3)});
}