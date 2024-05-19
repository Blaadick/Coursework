cmake_minimum_required(VERSION 3.28)
project(Coursework)

set(CMAKE_CXX_STANDARD 26)

add_executable(Coursework src/Main.cpp
    include/structs/user.h
    src/Login.cpp
    include/Login.h
    src/Loader.cpp
    include/Loader.h
    src/modules/SwitchModule.cpp
    include/modules/SwitchModule.h
    src/Utils.cpp
    include/Utils.h
    include/structs/athlete.h
    src/modules/UsersActions.cpp
    include/modules/UsersActions.h
    src/modules/AthletesActions.cpp
    include/modules/AthletesActions.h
    src/modules/Sorting.cpp
    include/modules/Sorting.h
    src/modules/Searching.cpp
    include/modules/Searching.h
    src/modules/Calculations.cpp
    include/modules/Calculations.h
)
