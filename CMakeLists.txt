cmake_minimum_required(VERSION 3.20)
project(linked_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(linked_list
        DisciplinesPlaceList.h
        header.h
        main.cpp
        readFunctions.cpp
        SportDisciplinesInfoList.h
        StandingsList.h
        writeFunctions.cpp)
