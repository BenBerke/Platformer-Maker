cmake_minimum_required(VERSION 3.20)
project(Platformer_Maker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Voxel src/main.cpp
        Headers/Renderer.h
        Headers/InputManager.h
        Headers/Tile.h
        Headers/Player.h
        Headers/config.h
        Headers/Vector.h

        src/Renderer.cpp
        src/Tile.cpp
        src/Player.cpp
        src/texture_creater.cpp
        src/InputManager.cpp
)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(Voxel PRIVATE SDL3::SDL3)
