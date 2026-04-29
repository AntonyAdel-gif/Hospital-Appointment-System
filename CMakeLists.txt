cmake_minimum_required(VERSION 4.1)
project(Hospital_Appointment_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Hospital_Appointment_System
        BST.h
        main.cpp)
