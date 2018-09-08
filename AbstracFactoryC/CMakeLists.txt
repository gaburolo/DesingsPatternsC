cmake_minimum_required(VERSION 3.12)
project(AbstracFactoryC)

set(CMAKE_CXX_STANDARD 14)

add_executable(AbstracFactoryC main.cpp carFactory.cpp car.cpp)