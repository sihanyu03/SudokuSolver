cmake_minimum_required(VERSION 3.28)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        SudokuSolver
        src/main.cpp
        src/board_reader.cpp
        src/solver.cpp)

add_subdirectory(tests)