#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H

#include<string>
#include<vector>
using namespace std;

class OfflineMsgModel
{
public:
    void insert(int userid,string msg);

    vector<string> query(int userid);

    void remove(int userid);
};

#endif