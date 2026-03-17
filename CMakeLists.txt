cmake_minimum_required(VERSION 3.20)
project(BTVN)

set(CMAKE_CXX_STANDARD 17)

file(GLOB ALL_FILES "*.cpp")

foreach(FILE ${ALL_FILES})
    get_filename_component(FILE_NAME ${FILE} NAME_WE)
    add_executable(${FILE_NAME} ${FILE}
            bai4.cpp
            bai4.h)
endforeach()