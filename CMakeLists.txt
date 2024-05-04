cmake_minimum_required(VERSION 3.28)
project(Coursework)

set(CMAKE_CXX_STANDARD 26)

add_executable(Coursework main.cpp
    structs/user.h
    login.cpp
    login.h
    loader.cpp
    loader.h
)
