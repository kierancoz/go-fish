find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
message("Source Dir:" ${go_fish_SOURCE_DIR})
include_directories (${go_fish_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
        )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (GoFishUnitTests test.cpp)
target_link_libraries (GoFishUnitTests
        GoFishLib
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

