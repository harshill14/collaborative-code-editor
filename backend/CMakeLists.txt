cmake_minimum_required(VERSION 3.10)
project(CollaborativeCodeEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(server
    src/main.cpp
    src/server.cpp
    src/server.hpp
    src/websocket_session.cpp
    src/websocket_session.hpp
    src/doc_manager.cpp
    src/doc_manager.hpp
    src/operational_transformation.cpp
    src/operational_transformation.hpp
)

target_link_libraries(server ${Boost_LIBRARIES})
