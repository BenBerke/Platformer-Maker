cmake_minimum_required(VERSION 3.20)
project(Platformer_Maker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Voxel main.cpp)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(Voxel PRIVATE SDL3::SDL3)
