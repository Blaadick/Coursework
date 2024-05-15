cmake_minimum_required(VERSION 3.28)
project(Coursework)

set(CMAKE_CXX_STANDARD 26)

add_executable(Coursework src/Main.cpp
    src/structs/user.h
    src/Login.cpp
    src/Login.h
    src/Loader.cpp
    src/Loader.h
        src/modules/SwitchModule.cpp
        src/modules/SwitchModule.h
    src/Utils.cpp
    src/Utils.h
        src/structs/athlete.h
        src/modules/Users.cpp
        src/modules/Users.h
        src/modules/Athletes.cpp
        src/modules/Athletes.h
        src/modules/Sorting.cpp
        src/modules/Sorting.h
)
