cmake_minimum_required(VERSION 4.3)
project(PIDRegler C)

set(CMAKE_C_STANDARD 11)

add_executable(PIDRegler main.c
        regelkreis.c
        regelkreis.h)
