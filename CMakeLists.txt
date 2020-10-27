cmake_minimum_required(VERSION 3.10)
project(go_fish)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY Z:/app_installs/temp/GoFish)
elseif(UNIX)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/kieran/Documents)
endif()

add_subdirectory(src)
add_subdirectory(test)
enable_testing()
add_test(NAME MyTest COMMAND test)