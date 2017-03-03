#!/bin/bash

mkdir build
cd build

cxxtestgen --error-printer -o runner.cpp ../TestShipManager.h
g++ -std=c++14 -o runner -I"../../../cxxtest-4.4" runner.cpp
./runner
