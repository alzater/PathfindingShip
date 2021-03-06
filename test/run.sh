#!/bin/bash

mkdir build -p
cd build

cxxtestgen --error-printer -o runner.cpp ../TestShipManager.h ../TestField.h ../TestPathfinder.h
g++ -std=c++14 -o runner -I"../../../cxxtest-4.4" runner.cpp ../../src/model/field.cpp ../../src/model/ship_manager.cpp ../../src/model/pathfinder.cpp ../../src/model/ship.cpp
./runner
