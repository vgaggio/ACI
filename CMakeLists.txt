cmake_minimum_required(VERSION 3.23)
project(ACI)

set(CMAKE_CXX_STANDARD 14)

add_executable(ACI
        compare.s
        main.c)
