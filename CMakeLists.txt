cmake_minimum_required(VERSION 3.7)

project(Guard_FSM)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

add_executable(guard ${project_SRCS})
