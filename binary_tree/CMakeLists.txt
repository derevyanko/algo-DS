cmake_minimum_required(VERSION 3.20)
project(binary_tree)

set(CMAKE_CXX_STANDARD 20 -lcurl)

include_directories(binary_tree)

add_executable(
    DisciplinesPlace.h
    header.h
    main.cpp
    readFunctions.cpp
    SportDisciplinesInfo.h
    Standings.h
    writeFunctions.cpp
)
