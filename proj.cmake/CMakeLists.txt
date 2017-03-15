cmake_minimum_required (VERSION 2.6)
project (PathfindingShip)

add_subdirectory(../../oxygine/oxygine-framework oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_executable(PathfindingShip
../src/entry_point.cpp
../src/example.cpp
../src/example.h
../src/presenter/presenter.cpp
../src/view/view.cpp
../src/view/cell.cpp
../src/view/ship_view.cpp
../src/model/model.cpp
../src/model/field.cpp
../src/model/ship_manager.cpp
../src/model/ship.cpp
../src/model/pathfinder.cpp
 )

if (WIN32) #disable console mode for VC++
    set_target_properties(PathfindingShip PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

target_link_libraries(PathfindingShip ${OXYGINE_CORE_LIBS})
