cmake_minimum_required(VERSION 3.16)
project(chess_engine C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)

# Engine core sources (shared between the CLI and the library)
add_library(engine_core OBJECT
    src/board.c
    src/movegen.c
)

# 1) Command-line engine (for perft / debugging)
add_executable(chess_cli src/main.c $<TARGET_OBJECTS:engine_core>)

# 2) Shared library for Python ctypes
add_library(chess_engine SHARED $<TARGET_OBJECTS:engine_core>)
set_target_properties(chess_engine PROPERTIES
    OUTPUT_NAME "chess_engine"
    PREFIX ""
)