#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include<muduo/net/TcpConnection.h>
#include<unordered_map>
#include<functional>
#include<mutex>
#include"usermodel.hpp"
#include"json.hpp"
#include "offlinemessagemodel.hpp"
using namespace std;
using namespace muduo;
using namespace muduo::net;
using json = nlohmann::json;

using MsgHandler = function<void(const TcpConnectionPtr &conn,json &js,Timestamp)>;

class ChatService
{
public:
    static ChatService* instance();
    void login(const TcpConnectionPtr &conn,json &js,Timestamp time);
    void reg(const TcpConnectionPtr &conn,json &js,Timestamp time);
    // 获取消息对应的处理器
    MsgHandler getHandler(int msgid);
    //一对一聊天
    void oneChat(const TcpConnectionPtr &conn,json &js,Timestamp time);

    void clientCloseException(const TcpConnectionPtr & conn);
private:
    ChatService();

    unordered_map<int,MsgHandler> _msgHandlerMap;

    unordered_map<int,TcpConnectionPtr> _userConnMap;

    mutex _connMutex;

    UserModel _userModel;

    OfflineMsgModel _offlineMsgModel;
};

#endif