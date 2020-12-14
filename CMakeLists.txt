cmake_minimum_required(VERSION 3.17)
project(michal C)

set(CMAKE_C_STANDARD 99)

add_executable(michal main.c getline.c getline.h ProtStats.h ProtStats.c)