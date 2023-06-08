cmake_minimum_required(VERSION 3.23)
project(Cittadini)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cittadini main.cpp cls/Cittadino/Cittadino.cpp cls/Cittadino/Cittadino.h cls/Residente/Residente.cpp cls/Residente/Residente.h cls/Visitatore/Visitatore.cpp cls/Visitatore/Visitatore.h cls/Data/Data.cpp cls/Data/Data.h cls/Stato/Stato.cpp cls/Stato/Stato.h)
