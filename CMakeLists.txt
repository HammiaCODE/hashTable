cmake_minimum_required(VERSION 3.28)
project(hash)

set(CMAKE_CXX_STANDARD 17)

add_executable(hash main.cpp
        HashTable.cpp
        HashTable.h)
