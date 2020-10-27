cmake_minimum_required(VERSION 3.10)
project(go_fish)

set(CMAKE_CXX_STANDARD 20)

# when bin used to be outside of project files - fixed by allowing exec permissions for linux on windows mounted drive
#if (WIN32)
#    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY Z:/app_installs/temp/GoFish)
#elseif(UNIX)
#    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/kieran/Documents)
#endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${go_fish_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_subdirectory(src)
# Setup unit tests
add_subdirectory(test)
enable_testing()
set(UNIT_TEST UnitTests)
add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})