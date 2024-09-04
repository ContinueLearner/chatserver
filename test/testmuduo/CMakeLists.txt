cmake_minimum_required(VERSION 3.0)
project(main)

set(SRC_LIST ./muduo_server.cpp)

#将所有当前目录文件赋值到src_list中
#aux_source_directory(. SRC_LIST)

#配置头文件搜索路径
#include_directories()

#配置库文件搜索路径
#link_directories()

#设置可执行文件最终存储的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(server ${SRC_LIST})

target_link_libraries(server muduo_net muduo_base pthread)
