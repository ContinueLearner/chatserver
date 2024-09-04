aux_source_directory(. SRC_LIST)

add_executable(ChatServer ${SRC_LIST})

link_directories(ChatServer muduo_net muduo_base pthread)
