cmake_minimum_required(VERSION 3.17)
project(go_fish)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY Z:/app_installs/temp/GoFish)
elseif(UNIX)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/kieran/Documents)
endif()

include_directories(DataModel EventController Interfaces UI Enums)
set(SOURCE_FILES main.cpp UI/UIController.cpp EventController/EventController.cpp DataModel/DataModelManager.cpp Interfaces/StateInfo.h Interfaces/IStateHistory.h)

add_executable(go_fish ${SOURCE_FILES})