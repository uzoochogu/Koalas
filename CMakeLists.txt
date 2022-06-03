cmake_minimum_required(VERSION 3.10)

project(Ursidae VERSION 1.0 DESCRIPTION "CSV shared lib")


# set compiler and flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${PROJECT_NAME} PUBLIC include)
include_directories(${PROJECT_NAME} PUBLIC src)

add_library(Ursidae src/ursidae.cpp)     #todo

set_target_properties(Ursidae PROPERTIES VERSION ${PROJECT_VERSION})

