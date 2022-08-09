cmake_minimum_required(VERSION 3.10.2)

set(PROJECT_NAME "WordsCounter")
project(${PROJECT_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} words_counter.cpp)
