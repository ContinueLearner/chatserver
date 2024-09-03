#include "json.hpp"
using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>
using namespace std;
 

void func01()
{
	json js;
	js["msgtype"] = 2;
	js["from"] = "zhangsan";
	js["to"] = "lisi";
	js["msg"] = "hello,what are you doing";
	
	string sendBuf = js.dump();
	cout<<sendBuf<<endl;
	
}

void func02()
{
	json js;
	// 添加数组
	js["id"] = {1,2,3,4,5};
	// 添加key-value
	js["name"] = "zhang san";
	// 添加对象
	js["msg"]["zhang san"] = "hello world";
	js["msg"]["liu shuo"] = "hello china";
	// 上面等同于下面这句一次性添加数组对象
	js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
	cout << js << endl;
}

void func03()
{
	json js;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	js["list"] = vec;
	
	map<int,string> Hash;
	Hash.insert({1,"华山"});
	Hash.insert({2,"泰山"});
	Hash.insert({3,"衡山"});
	js["path"] = Hash;
	
	cout<<js<<endl;
}
int main()
{
	func03();
	return 0;
}