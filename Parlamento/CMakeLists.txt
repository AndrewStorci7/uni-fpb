cmake_minimum_required(VERSION 3.23)
project(Parlamento)

set(CMAKE_CXX_STANDARD 14)

add_executable(Parlamento main.cpp cls/Partito/Partito.cpp cls/Partito/Partito.h)
