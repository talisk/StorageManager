cmake_minimum_required(VERSION 3.3)
project(StorageManager)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Storage.cpp Storage.h Global.h)
add_executable(StorageManager ${SOURCE_FILES})