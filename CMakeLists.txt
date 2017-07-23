cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ls.h)
add_executable(untitled ${SOURCE_FILES})