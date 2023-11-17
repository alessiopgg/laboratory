cmake_minimum_required(VERSION 3.23)
project(laboratory)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES main.cpp IObserver.h ISubject.h Item.cpp Item.h ShoppingList.cpp ShoppingList.h User.cpp User.h)
add_executable(laboratory main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(laboratory core)