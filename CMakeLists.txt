cmake_minimum_required(VERSION 3.31)
project(Task_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task_2 main.cpp
        Book.h
        "Paper Book.h"
        EBook.h
        ShowcaseBook.h
        Inventory.h
        TESTS.h)
