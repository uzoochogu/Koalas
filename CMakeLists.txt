cmake_minimum_required(VERSION 3.10)

project(Ursidae VERSION 1.0 DESCRIPTION "CSV shared lib")


# set compiler and flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/ursidae.cpp
    src/main.cpp
)


option(BUILD_SHARED_LIB "" OFF)
if (BUILD_SHARED_LIB)
   add_library(Ursidae SHARED
    src/ursidae.cpp)
else()
   add_library(Ursidae STATIC
    src/ursidae.cpp)
endif()



target_include_directories(Ursidae
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)


