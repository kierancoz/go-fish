cmake_minimum_required(VERSION 3.17)
project(go_fish)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/kieran/go-fish-build)

include_directories(DataModel EventController Interfaces UI)
set(SOURCE_FILES main.cpp UI/UIController.cpp EventController/EventController.cpp DataModel/DataModelManager.cpp)

add_executable(go_fish ${SOURCE_FILES})