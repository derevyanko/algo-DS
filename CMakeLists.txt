cmake_minimum_required(VERSION 3.20)
project(linked_list)

set(CMAKE_CXX_STANDARD 20 -lcurl)

include_directories(linked_list)

add_executable(
    DisciplinesPlaceList.h
    header.h
    main.cpp
    readFunctions.cpp
    SportDisciplinesInfoList.h
    StandingsList.h
    writeFunctions.cpp
)
