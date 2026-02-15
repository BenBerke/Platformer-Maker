cmake_minimum_required(VERSION 3.20)
project(Platformer_Maker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Voxel src/main.cpp
        src/Player.cpp
        Headers/Player.h
        src/Renderer.cpp
        Headers/Renderer.h
        Headers/config.h
        src/Tile.cpp
        Headers/Tile.h
        src/texture_creater.cpp
)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(Voxel PRIVATE SDL3::SDL3)
