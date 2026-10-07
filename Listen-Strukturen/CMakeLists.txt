cmake_minimum_required(VERSION 4.3)
project(Listen_Strukturen C)

set(CMAKE_C_STANDARD 11)

add_executable(Listen_Strukturen main.c
        linkedlist.h
        linkedlist.c
        doublelinkedlist.c
        doublelinkedlist.h
)
