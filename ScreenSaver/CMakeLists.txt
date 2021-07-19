cmake_minimum_required(VERSION 3.15)
project(OOP_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_Project main.cpp Shape.cpp Shape.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h Square.cpp Square.h RoundRectangle.cpp RoundRectangle.h)