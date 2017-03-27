cmake_minimum_required (VERSION 2.6)
project (PathfindingShip)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(../../oxygine/oxygine-framework oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS} -std=c++14 -o2")

add_executable(PathfindingShip
../src/entry_point.cpp
../src/example.cpp
../src/example.h
../src/presenter/presenter.cpp
../src/view/view.cpp
../src/view/cell.cpp
../src/view/ship_view.cpp
../src/view/ship_place.cpp
../src/model/model.cpp
../src/model/ship.cpp
../src/model/field.cpp
../src/model/field_loader.cpp
../src/model/ship_manager.cpp
../src/model/pathfinder.cpp
 )

target_link_libraries(PathfindingShip ${OXYGINE_CORE_LIBS})

if (WIN32) #disable console mode for VC++
	set_target_properties(HelloWorld PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)



if (EMSCRIPTEN)
	SET(CMAKE_EXECUTABLE_SUFFIX ".html")	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s NO_EXIT_RUNTIME=1 -s WARN_ON_UNDEFINED_SYMBOLS=1 --memory-init-file 0 -s TOTAL_MEMORY=50331648")
	em_link_pre_js(PathfindingShip  ${OXYGINE_JS_LIBRARIES}  ${CMAKE_CURRENT_SOURCE_DIR}/data.js)
endif(EMSCRIPTEN)
