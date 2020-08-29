cmake_minimum_required(VERSION 3.17)
project(go_fish)

set(CMAKE_CXX_STANDARD 17)

include_directories(DataModel EventController Interfaces UI)
add_executable(go_fish main.cpp)