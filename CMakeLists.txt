cmake_minimum_required(VERSION 3.23)
project(laboratory)

set(CMAKE_CXX_STANDARD 14)

add_executable(laboratory main.cpp IObserver.h ISubject.h Item.cpp Item.h)
