
set(INCLUDE_SUBDIRECTORIES DataModel EventController Interfaces UI Enums)
include_directories(${INCLUDE_SUBDIRECTORIES})
set(SOURCE_FILES UI/UIController.cpp EventController/EventController.cpp DataModel/DataModelManager.cpp Interfaces/StateInfo.h Interfaces/IStateHistory.h)

add_library(GoFishLib ${SOURCE_FILES})
add_executable(go_fish_demo main.cpp)
target_link_libraries(go_fish_demo GoFishLib)