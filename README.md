# ChatServer - 高性能 C++ 集群聊天服务器

本项目是一个基于 C++ 开发的高性能集群聊天服务器，采用 **muduo** 网络库作为底座，并结合 **Redis** 发布/订阅机制实现跨服务器的消息通信。项目支持用户注册、登录、单聊、群聊及离线消息存储等核心业务功能。

## 🚀 核心功能

* **用户管理**：支持用户注册、登录、注销（更新在线状态）。
* **单聊业务**：实时推送在线消息，对离线用户支持离线消息存储。
* **群聊业务**：支持群组创建、加入及群内消息广播。
* **好友系统**：支持添加好友及好友列表查询。
* **集群通信**：利用 Redis 的 `PUBLISH/SUBSCRIBE` 机制，解决跨服务器登录用户的消息转发问题。

## 🛠️ 技术栈

* **网络框架**：[muduo](https://github.com/chenshuo/muduo) (基于 Epoll 的非阻塞网络 IO 库)。
* **消息序列化**：[JSON for Modern C++](https://github.com/nlohmann/json)。
* **数据库**：MySQL (持久化存储用户信息、好友关系、离线消息等)。
* **中间件**：Redis (实现集群服务器间的消息订阅与分发)。
* **构建工具**：CMake。

## 📂 目录结构

```text
.
├── bin/                # 编译生成的二进制文件 (ChatServer, ChatClient)
├── build/              # CMake 编译中间文件
├── include/            # 头文件目录
│   └── server/         # 服务器核心类定义 (ChatServer, ChatService, DB 等)
├── src/                # 源码目录
│   ├── client/         # 客户端源码
│   └── server/         # 服务器源码 (业务逻辑、模型层、数据库接口等)
├── thirdparty/         # 第三方依赖库 (如 json.hpp)
├── chat.sql            # 数据库建表脚本
└── CMakeLists.txt      # 顶层编译配置文件

```

## ⚙️ 环境要求

* **操作系统**：Linux (建议 Ubuntu 20.04+)
* **编译器**：g++ (支持 C++11 及以上)
* **依赖库**：
* `muduo` 网络库
* `libmysqlclient` (MySQL 开发包)
* `hiredis` (Redis 客户端库)
* `boost` (muduo 库依赖)



## 🏗️ 编译与运行

### 1. 准备数据库

执行项目根目录下的 SQL 脚本以初始化 MySQL 表结构：

```bash
mysql -u root -p < chat.sql

```

### 2. 编译项目

在根目录下执行以下命令：

```bash
mkdir build && cd build
cmake ..
make

```

### 3. 启动服务器

```bash
cd ../bin
# 格式: ./ChatServer <IP地址> <端口号>
./ChatServer 127.0.0.1 6000

```

### 4. 启动客户端

```bash
./ChatClient 127.0.0.1 6000

```

## 📐 架构设计

1. **网络层**：`ChatServer` 封装了 muduo 的 `TcpServer`，负责连接管理与 IO 事件处理。
2. **业务层**：`ChatService` 采用单例模式，通过回调机制（Message ID -> Handler）解耦网络事件与业务逻辑。
3. **数据层**：`Model` 类（User, Friend, Group）封装数据库操作，对接 `MySQL` 持久化存储。
