cmake_minimum_required(VERSION 3.23)
project(_CSES)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOCAL")
add_executable(_CSES main.cpp)
add_executable(test test.cpp)