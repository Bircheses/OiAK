cmake_minimum_required(VERSION 3.27)
project(OiAK)

set(CMAKE_CXX_STANDARD 17)

add_executable(OiAK main.cpp
        Algortihms/SOS.cpp
        Algortihms/SOS.h
        Algortihms/CIOS.cpp
        Algortihms/CIOS.h
        Algortihms/StaticFunctions.cpp
)
