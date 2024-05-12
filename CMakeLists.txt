cmake_minimum_required(VERSION 3.28)
project(Coursework)

set(CMAKE_CXX_STANDARD 26)

add_executable(Coursework Main.cpp
    structs/user.h
    Login.cpp
    Login.h
    Loader.cpp
    Loader.h
    SwitchModule.cpp
    SwitchModule.h
    Utils.cpp
    Utils.h
)
